#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <memory>
#include <chrono>
#include <vector>

class Stock {
public:
    Stock(const std::string& symbol, double price, double volatility = 0.02);

    // RAII: Rule of Five
    Stock(const Stock&) = delete;
    Stock& operator=(const Stock&) = delete;
    Stock(Stock&&) = default;
    Stock& operator=(Stock&&) = default;
    ~Stock() = default;

    // Getters
    std::string getSymbol() const { return symbol_; }
    double getPrice() const { return price_; }
    double getVolatility() const { return volatility_; }
    std::chrono::system_clock::time_point getLastUpdate() const { return lastUpdate_; }

    // Update price with simulated market movement
    void updatePrice();

private:
    std::string symbol_;
    double price_;
    double volatility_;
    std::chrono::system_clock::time_point lastUpdate_;
};

#endif