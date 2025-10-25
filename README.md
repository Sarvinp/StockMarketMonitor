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

Concept	Implementation	File

RAII	Smart pointers, lock guards, automatic cleanup	All files

STL Mastery	Algorithms, containers, utilities	Portfolio.cpp

Multithreading	std::thread, mutex, atomic, condition_variable	MarketDataFeed.cpp

Memory Management	Smart pointers, rule of five	Stock.h

Design Patterns	Singleton, Observer, Factory	MarketDataFeed.h

### Design Patterns Used

Singleton Pattern: MarketDataFeed - Ensures single global market data source

Observer Pattern: PriceObserver - Real-time notifications to multiple subscribers

Factory Pattern: createStock() - Centralized object creation with validation

RAII Pattern: Automatic resource management throughout codebase

## 🚀 Quick Start
Prerequisites
C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)

CMake 3.15+

Threading support (usually included)

### Build & Run
```bash
# Clone and build
git clone https://github.com/yourusername/stock-market-monitor.git
cd stock-market-monitor
mkdir build && cd build
cmake ..
make
# Run the application
./StockMarketMonitor
Sample Output
text
=== Stock Market Monitor Started ===
Added 10 shares of AAPL
Added 2 shares of GOOGL
Set risk limit for AAPL: $160
Set risk limit for GOOGL: $2800
Market data feed started
Stock AAPL updated to: $152.34
Stock GOOGL updated to: $2712.45
Top performers: GOOGL AAPL 
Portfolio value: $30297.3
Portfolio risk: 0%
---
🚨 RISK WARNING: AAPL price $161.25 exceeds limit $160
```

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

## 🎓 Educational Value
### For Junior Developers
Learn professional C++ coding standards

Understand memory management best practices

See real multithreading implementation

### For Intermediate Developers
Study design patterns in context

Learn thread-safe class design

Understand modern C++ features

### For Senior Developers
Reference architecture for financial systems

Pattern implementation examples

Code review and mentoring material

## 🔧 Extensibility
The architecture supports easy extensions:

Add database persistence

Implement real market data APIs

Add graphical UI with Qt

Extend risk models

Add order execution system

## 📊 Performance Features
Lock-free operations where possible

Efficient STL algorithm usage

Minimal copying with move semantics

Thread coordination with condition variables

## 🤝 Contributing
Contributions welcome! Areas for improvement:

Additional risk models

More STL algorithm examples

Performance optimizations

Additional design patterns
