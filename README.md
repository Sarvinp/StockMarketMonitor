# Stock Market Monitor 📈
A professional C++ real-time stock market monitoring system that demonstrates advanced C++ programming concepts including multithreading, design patterns, RAII, and STL mastery.

## 🎯 What This Project Does
Stock Market Monitor simulates a real-time financial trading system that:

## 🔄 Real-Time Market Simulation
Live Price Updates: Continuously generates realistic stock price movements using random walk simulation

Multiple Stocks: Tracks popular stocks (AAPL, GOOGL, TSLA, MSFT) with individual volatility profiles

Market Data Feed: Background thread constantly updates prices and notifies all subscribers

## 📊 Portfolio Management
Position Tracking: Maintains holdings of multiple stocks with quantities

Real-time Valuation: Automatically calculates total portfolio value as prices change

Performance Analytics: Identifies top-performing stocks using STL algorithms

Thread-safe Operations: All portfolio operations are safe for concurrent access

## ⚠️ Risk Management System
Price Limit Monitoring: Automatically alerts when stocks exceed predefined price limits

Position Size Validation: Prevents excessive exposure to single stocks

Portfolio Risk Metrics: Calculates overall portfolio risk based on warning events

Real-time Alerts: Immediate notifications for risk threshold breaches

## 🎪 Advanced Features
Live Notifications: Observer pattern delivers instant price updates to all subscribers

Concurrent Processing: Multithreaded architecture handles market data and UI simultaneously

Memory Safe: RAII and smart pointers ensure no memory leaks

Professional Patterns: Singleton, Observer, and Factory patterns for scalable architecture

## 🛠️ Technical Implementation

### Core C++ Concepts Demonstrated

| Concept | Implementation | File |
|---------|----------------|------|
| **RAII** | Smart pointers, lock guards, automatic cleanup | All files |
| **STL Mastery** | Algorithms, containers, utilities | Portfolio.cpp |
| **Multithreading** | std::thread, mutex, atomic, condition_variable | MarketDataFeed.cpp |
| **Memory Management** | Smart pointers, rule of five | Stock.h |
| **Design Patterns** | Singleton, Observer, Factory | MarketDataFeed.h |

### Design Patterns Used

| Pattern | Purpose | Implementation |
|---------|---------|----------------|
| **Singleton Pattern** | Ensures single global market data source | `MarketDataFeed::getInstance()` |
| **Observer Pattern** | Real-time notifications to multiple subscribers | `PriceObserver` interface |
| **Factory Pattern** | Centralized object creation with validation | `createStock()` method |
| **RAII Pattern** | Automatic resource management | Smart pointers, lock guards |

## 🎓 Educational Value

| Developer Level | Learning Focus | Key Takeaways |
|-----------------|----------------|---------------|
| **Junior Developers** | Professional C++ coding standards | Memory management, basic patterns |
| **Intermediate Developers** | Design patterns in context | Thread-safe design, advanced STL |
| **Senior Developers** | System architecture | Code review, mentoring examples |

## 🔧 Extensibility Options

| Extension | Description | Implementation Difficulty |
|-----------|-------------|---------------------------|
| **Database Persistence** | Add SQLite/PostgreSQL for data storage | Medium |
| **Real Market Data APIs** | Connect to Yahoo Finance or Alpha Vantage | High |
| **Graphical UI** | Add Qt/QML interface | Medium |
| **Extended Risk Models** | VAR, Monte Carlo simulations | High |
| **Order Execution System** | Simulated trading engine | High |

## 📊 Performance Features

| Feature | Benefit | Implementation |
|---------|---------|----------------|
| **Lock-free operations** | Reduced contention | `std::atomic` variables |
| **Efficient STL usage** | Optimal algorithms | `std::transform`, `std::accumulate` |
| **Minimal copying** | Better performance | Move semantics |
| **Thread coordination** | Efficient waiting | `std::condition_variable` |

## 🚀 Quick Start Commands

| Step | Command | Description |
|------|---------|-------------|
| **1. Clone** | `git clone https://github.com/Sarvinp/StockMarketMonitor.git` | Get the source code |
| **2. Build** | `mkdir build && cd build && cmake .. && make` | Compile the project |
| **3. Run** | `./StockMarketMonitor` | Start the application |

## 📁 Project Structure

| Directory/File | Purpose |
|----------------|---------|
| `include/Stock.h` | Stock data model with RAII |
| `include/Portfolio.h` | Portfolio management with STL |
| `include/MarketDataFeed.h` | Singleton market data source |
| `include/RiskManager.h` | Observer pattern implementation |
| `src/Stock.cpp` | Price simulation logic |
| `src/Portfolio.cpp` | STL algorithms demonstration |
| `src/MarketDataFeed.cpp` | Multithreading implementation |
| `src/RiskManager.cpp` | Risk monitoring logic |
| `src/main.cpp` | Application entry point |
| `CMakeLists.txt` | Build configuration |

## 💡 Sample Output Preview

| Component | Sample Output |
|-----------|---------------|
| **Market Data** | `Stock AAPL updated to: $152.34` |
| **Portfolio** | `Top performers: GOOGL AAPL` |
| **Risk Management** | `🚨 RISK WARNING: AAPL price $161.25 exceeds limit $160` |
| **Performance** | `Portfolio value: $30297.3, Portfolio risk: 0%` |

## 🎯 System Requirements

| Requirement | Minimum | Recommended |
|-------------|---------|-------------|
| **C++ Standard** | C++17 | C++20 |
| **Compiler** | GCC 7+, Clang 5+, MSVC 2017+ | GCC 11+, Clang 12+ |
| **Memory** | 512 MB RAM | 2 GB RAM |
| **Storage** | 100 MB | 1 GB |
| **Threading** | POSIX Threads | Standard C++ Threads |

## 📁 Project Structure
```text
stock-market-monitor/
├── include/
│   ├── Stock.h              # Stock data model with RAII
│   ├── Portfolio.h          # Portfolio management with STL
│   ├── MarketDataFeed.h     # Singleton market data source
│   └── RiskManager.h        # Observer pattern implementation
├── src/
│   ├── Stock.cpp            # Price simulation logic
│   ├── Portfolio.cpp        # STL algorithms demonstration
│   ├── MarketDataFeed.cpp   # Multithreading implementation
│   ├── RiskManager.cpp      # Risk monitoring logic
│   └── main.cpp            # Application entry point
├── CMakeLists.txt          # Build configuration
└── README.md              # This file
```
## 💡 Learning Objectives
This project is perfect for understanding:

Modern C++17/20 features in practice

Thread-safe design and implementation

Resource management without leaks

STL algorithms and containers usage

Design patterns in real-world scenarios

Professional C++ architecture and patterns

## 🤝 Contributing
Contributions welcome! Areas for improvement:

Additional risk models

More STL algorithm examples

Performance optimizations

Additional design patterns
