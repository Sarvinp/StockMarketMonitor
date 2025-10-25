#include "Portfolio.h"
#include <algorithm>
#include <numeric>
#include <iostream>

void Portfolio::addStock(std::shared_ptr<Stock> stock, int quantity) {
    std::lock_guard<std::mutex> lock(mutex_);
    holdings_[stock->getSymbol()] = {stock, quantity};
    std::cout << "Added " << quantity << " shares of " << stock->getSymbol() << std::endl;
}

void Portfolio::removeStock(const std::string& symbol) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = holdings_.find(symbol);
    if (it != holdings_.end()) {
        holdings_.erase(it);
        std::cout << "Removed " << symbol << " from portfolio" << std::endl;
    }
}

double Portfolio::getTotalValue() const {
    std::lock_guard<std::mutex> lock(mutex_);

    // STL Algorithm: accumulate
    return std::accumulate(holdings_.begin(), holdings_.end(), 0.0,
                           [](double total, const auto& pair) {
                               return total + pair.second.stock->getPrice() * pair.second.quantity;
                           });
}

std::vector<std::string> Portfolio::getTopPerformers(int count) const {
    std::lock_guard<std::mutex> lock(mutex_);
    std::vector<std::pair<std::string, double>> performances;

    // STL Algorithm: transform
    std::transform(holdings_.begin(), holdings_.end(),
                   std::back_inserter(performances),
                   [](const auto& pair) {
                       return std::make_pair(pair.first,
                                             pair.second.stock->getPrice() * pair.second.quantity);
                   });

    // STL Algorithm: partial_sort
    std::partial_sort(performances.begin(),
                      performances.begin() + std::min(count, (int)performances.size()),
                      performances.end(),
                      [](const auto& a, const auto& b) { return a.second > b.second; });

    // STL Algorithm: transform again
    std::vector<std::string> result;
    std::transform(performances.begin(),
                   performances.begin() + std::min(count, (int)performances.size()),
                   std::back_inserter(result),
                   [](const auto& pair) { return pair.first; });

    return result;
}

void Portfolio::updateStockPrice(const std::string& symbol, double newPrice) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = holdings_.find(symbol);
    if (it != holdings_.end()) {
        // In real scenario, we'd update the stock object
        // For demo, we'll just note the update
        std::cout << "Price update for " << symbol << ": $" << newPrice << std::endl;
    }
}

void Portfolio::clear() {
    std::lock_guard<std::mutex> lock(mutex_);
    holdings_.clear();
    std::cout << "Portfolio cleared" << std::endl;
}