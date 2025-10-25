#include "RiskManager.h"
#include <iostream>

RiskManager::RiskManager(std::shared_ptr<Portfolio> portfolio, double maxPositionSize)
        : portfolio_(portfolio), maxPositionSize_(maxPositionSize) {

    // Register with market data feed (Observer Pattern)
    MarketDataFeed::getInstance().registerObserver(
            std::shared_ptr<PriceObserver>(this, [](auto*) {}) // Custom deleter to avoid double delete
    );
}

RiskManager::~RiskManager() {
    MarketDataFeed::getInstance().unregisterObserver(
            std::shared_ptr<PriceObserver>(this, [](auto*) {})
    );
}

void RiskManager::onPriceUpdate(const std::string& symbol, double price) {
    // Check risk limits on price update
    std::lock_guard<std::mutex> lock(riskMutex_);
    auto it = riskLimits_.find(symbol);
    if (it != riskLimits_.end() && price > it->second) {
        warningCount_++;
        std::cout << "🚨 RISK WARNING: " << symbol << " price $" << price
                  << " exceeds limit $" << it->second << std::endl;
    }
}

bool RiskManager::checkPositionLimit(const std::string& symbol, int quantity, double price) const {
    double positionValue = quantity * price;
    if (positionValue > maxPositionSize_) {
        std::cout << "❌ Position limit exceeded for " << symbol
                  << ": $" << positionValue << " > $" << maxPositionSize_ << std::endl;
        return false;
    }
    return true;
}

double RiskManager::calculatePortfolioRisk() const {
    // Simplified risk calculation
    auto totalValue = portfolio_->getTotalValue();
    return totalValue > 0 ? (warningCount_.load() * 100.0 / totalValue) : 0.0;
}

void RiskManager::setRiskLimit(const std::string& symbol, double limit) {
    std::lock_guard<std::mutex> lock(riskMutex_);
    riskLimits_[symbol] = limit;
    std::cout << "Set risk limit for " << symbol << ": $" << limit << std::endl;
}