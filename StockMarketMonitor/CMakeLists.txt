cmake_minimum_required(VERSION 3.15)
project(StockMarketMonitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable threading
find_package(Threads REQUIRED)

add_executable(StockMarketMonitor
        main.cpp
        Stock.cpp
        Portfolio.cpp
        MarketDataFeed.cpp
        RiskManager.cpp
        Stock.h
)

target_link_libraries(StockMarketMonitor Threads::Threads)