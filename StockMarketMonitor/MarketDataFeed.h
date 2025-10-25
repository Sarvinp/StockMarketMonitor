#ifndef MARKETDATAFEED_H
#define MARKETDATAFEED_H

#include "Stock.h"
#include <vector>
#include <memory>
#include <functional>
#include <thread>
#include <atomic>
#include <condition_variable>

// Observer Pattern: Interface for price updates
class PriceObserver {
public:
    virtual ~PriceObserver() = default;
    virtual void onPriceUpdate(const std::string& symbol, double price) = 0;
};

class MarketDataFeed {
public:
    // Singleton Pattern: Global access to market data
    static MarketDataFeed& getInstance();

    // Observer Pattern management
    void registerObserver(std::shared_ptr<PriceObserver> observer);
    void unregisterObserver(std::shared_ptr<PriceObserver> observer);

    // Multithreading: Start/stop feed
    void startFeed();
    void stopFeed();

    // Factory-like method to create stocks
    std::shared_ptr<Stock> createStock(const std::string& symbol, double price);

private:
    MarketDataFeed(); // Private constructor for Singleton
    void runFeed();   // Main feed loop

    // STL Containers
    std::vector<std::shared_ptr<Stock>> stocks_;
    std::vector<std::shared_ptr<PriceObserver>> observers_;

    // Multithreading primitives
    std::thread feedThread_;
    std::atomic<bool> running_{false};
    std::mutex observersMutex_;
    std::condition_variable cv_;

    // Singleton: Delete copy operations
    MarketDataFeed(const MarketDataFeed&) = delete;
    MarketDataFeed& operator=(const MarketDataFeed&) = delete;
};

#endif