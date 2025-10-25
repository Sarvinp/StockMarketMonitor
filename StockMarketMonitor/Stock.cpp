#include "Stock.h"
#include <random>
#include <iostream>

// Thread-safe random number generation
thread_local std::mt19937 gen{std::random_device{}()};

Stock::Stock(const std::string& symbol, double price, double volatility)
        : symbol_(symbol), price_(price), volatility_(volatility),
          lastUpdate_(std::chrono::system_clock::now()) {
}

void Stock::updatePrice() {
    std::normal_distribution<double> dist(0.0, volatility_);
    double change = dist(gen);
    price_ *= (1.0 + change);

    // Ensure price doesn't go negative
    if (price_ < 0.01) price_ = 0.01;

    lastUpdate_ = std::chrono::system_clock::now();

    std::cout << "Stock " << symbol_ << " updated to: $" << price_ << std::endl;
}