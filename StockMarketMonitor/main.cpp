#include "MarketDataFeed.h"
#include "Portfolio.h"
#include "RiskManager.h"
#include <iostream>
#include <thread>
#include <memory>

int main() {
    std::cout << "=== Stock Market Monitor Started ===" << std::endl;

    // RAII: Automatic memory management with smart pointers
    auto portfolio = std::make_shared<Portfolio>();
    auto riskManager = std::make_shared<RiskManager>(portfolio, 5000.0);

    // Factory: Create stocks through market data feed
    auto& marketFeed = MarketDataFeed::getInstance(); // Singleton

    // Add stocks to portfolio
    portfolio->addStock(marketFeed.createStock("AAPL", 150.0), 10);
    portfolio->addStock(marketFeed.createStock("GOOGL", 2700.0), 2);

    // Set risk limits
    riskManager->setRiskLimit("AAPL", 160.0);
    riskManager->setRiskLimit("GOOGL", 2800.0);

    // Multithreading: Start market data feed in background
    marketFeed.startFeed();

    // Main thread work simulation
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(2));

        // STL: Use algorithms to get portfolio info
        auto topPerformers = portfolio->getTopPerformers(2);
        std::cout << "Top performers: ";
        for (const auto& symbol : topPerformers) {
            std::cout << symbol << " ";
        }
        std::cout << std::endl;

        std::cout << "Portfolio value: $" << portfolio->getTotalValue() << std::endl;
        std::cout << "Portfolio risk: " << riskManager->calculatePortfolioRisk() << "%" << std::endl;
        std::cout << "---" << std::endl;
    }

    // RAII: Automatic cleanup when objects go out of scope
    marketFeed.stopFeed();

    std::cout << "=== Stock Market Monitor Finished ===" << std::endl;
    return 0;
}