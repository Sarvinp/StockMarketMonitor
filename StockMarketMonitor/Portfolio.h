#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Stock.h"
#include <unordered_map>
#include <vector>
#include <memory>
#include <algorithm>
#include <mutex>

class Portfolio {
public:
    Portfolio() = default;

    // Memory Management: Smart pointers for ownership
    void addStock(std::shared_ptr<Stock> stock, int quantity);
    void removeStock(const std::string& symbol);

    // STL Algorithms
    double getTotalValue() const;
    double getStockValue(const std::string& symbol) const;
    std::vector<std::string> getTopPerformers(int count) const;

    // Multithreading: Thread-safe operations
    void updateStockPrice(const std::string& symbol, double newPrice);

    // RAII: Clean resource management
    void clear();

private:
    struct Holding {
        std::shared_ptr<Stock> stock;
        int quantity;
    };

    // STL Container: Unordered map for fast lookup
    std::unordered_map<std::string, Holding> holdings_;
    mutable std::mutex mutex_; // For thread safety
};

#endif