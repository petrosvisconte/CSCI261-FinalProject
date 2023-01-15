cmake_minimum_required(VERSION 3.14)
project(FinalProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(FinalProject main.cpp DailyData.cpp DailyData.h HistoricalData.cpp HistoricalData.h Indicators.cpp Indicators.h CalculateIndicators.cpp CalculateIndicators.h)