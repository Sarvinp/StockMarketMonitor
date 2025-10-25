#include "MarketDataFeed.h"
#include <iostream>
#include <random>

MarketDataFeed& MarketDataFeed::getInstance() {
    static MarketDataFeed instance; // Meyer's Singleton
    return instance;
}

MarketDataFeed::MarketDataFeed() {
    // Factory: Create some sample stocks
    stocks_.push_back(createStock("AAPL", 150.0));
    stocks_.push_back(createStock("GOOGL", 2700.0));
    stocks_.push_back(createStock("TSLA", 800.0));
    stocks_.push_back(createStock("MSFT", 300.0));
}

std::shared_ptr<Stock> MarketDataFeed::createStock(const std::string& symbol, double price) {
    return std::make_shared<Stock>(symbol, price, 0.02 + (std::rand() % 10) / 100.0);
}

void MarketDataFeed::registerObserver(std::shared_ptr<PriceObserver> observer) {
    std::lock_guard<std::mutex> lock(observersMutex_);
    observers_.push_back(observer);
    std::cout << "Observer registered with market data feed" << std::endl;
}

void MarketDataFeed::unregisterObserver(std::shared_ptr<PriceObserver> observer) {
    std::lock_guard<std::mutex> lock(observersMutex_);
    observers_.erase(std::remove(observers_.begin(), observers_.end(), observer),
                     observers_.end());
    std::cout << "Observer unregistered from market data feed" << std::endl;
}

void MarketDataFeed::startFeed() {
    if (!running_.exchange(true)) {
        feedThread_ = std::thread(&MarketDataFeed::runFeed, this);
        std::cout << "Market data feed started" << std::endl;
    }
}

void MarketDataFeed::stopFeed() {
    if (running_.exchange(false)) {
        if (feedThread_.joinable()) {
            feedThread_.join();
        }
        std::cout << "Market data feed stopped" << std::endl;
    }
}

void MarketDataFeed::runFeed() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(500, 2000); // Random interval

    while (running_) {
        // Update random stock
        if (!stocks_.empty()) {
            std::uniform_int_distribution<> stockDis(0, stocks_.size() - 1);
            auto& stock = stocks_[stockDis(gen)];
            stock->updatePrice();

            // Notify observers (Observer Pattern)
            std::vector<std::shared_ptr<PriceObserver>> currentObservers;
            {
                std::lock_guard<std::mutex> lock(observersMutex_);
                currentObservers = observers_;
            }

            for (auto& observer : currentObservers) {
                observer->onPriceUpdate(stock->getSymbol(), stock->getPrice());
            }
        }

        // Sleep for random interval
        std::this_thread::sleep_for(std::chrono::milliseconds(dis(gen)));
    }
}