#ifndef RISKMANAGER_H
#define RISKMANAGER_H

#include "MarketDataFeed.h"
#include "Portfolio.h"
#include <unordered_map>
#include <atomic>

class RiskManager : public PriceObserver {
public:
    RiskManager(std::shared_ptr<Portfolio> portfolio, double maxPositionSize = 10000.0);
    ~RiskManager();

    // Observer Pattern implementation
    void onPriceUpdate(const std::string& symbol, double price) override;

    // Risk management methods
    bool checkPositionLimit(const std::string& symbol, int quantity, double price) const;
    double calculatePortfolioRisk() const;

    // STL: Container for risk limits
    void setRiskLimit(const std::string& symbol, double limit);

private:
    std::shared_ptr<Portfolio> portfolio_;
    double maxPositionSize_;

    // STL Container: Risk limits per stock
    std::unordered_map<std::string, double> riskLimits_;
    mutable std::mutex riskMutex_;

    // Multithreading: Atomic operations
    std::atomic<int> warningCount_{0};
};

#endif