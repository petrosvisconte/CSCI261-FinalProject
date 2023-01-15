//PIERRE VISCONTI
//CSCI 261 - F
//FINAL PROJECT

#include "Indicators.h"

//Default constructor
Indicators::Indicators() {}

void Indicators::SetRSI(float RSI) {
    _RSI = RSI;
}

void Indicators::SetThirteenSMA(float SMA) {
    _thirteenSMA = SMA;
}

void Indicators::SetThirteenEMA(float EMA) {
    _thirteenEMA = EMA;
}

void Indicators::SetTwentyOneSMA(float SMA) {
    _twentyOneSMA = SMA;
}

void Indicators::SetTwentyOneEMA(float EMA) {
    _twentyOneEMA = EMA;
}

void Indicators::SetNineSMA(float SMA) {
    _nineSMA = SMA;
}

void Indicators::SetNineEMA(float EMA) {
    _nineEMA = EMA;
}

void Indicators::SetTwelveSMA(float SMA) {
    _twelveSMA = SMA;
}

void Indicators::SetTwelveEMA(float EMA) {
    _twelveEMA = EMA;
}

void Indicators::SetTwentySixSMA(float SMA) {
    _twentySixSMA = SMA;
}

void Indicators::SetTwentySixEMA(float EMA) {
    _twentySixEMA = EMA;
}

void Indicators::SetMACD(float MACD) {
    _MACD = MACD;
}
void Indicators::SetVolume(int volume) {
    _volume = volume;
}

float Indicators::GetRSI() {
    return _RSI;
}

float Indicators::GetThirteenSMA() {
    return _thirteenSMA;
}

float Indicators::GetThirteenEMA() {
    return _thirteenEMA;
}

float Indicators::GetTwentyOneSMA() {
    return _twentyOneSMA;
}

float Indicators::GetTwentyOneEMA() {
    return _twentyOneEMA;
}

float Indicators::GetNineSMA() {
    return _nineSMA;
}

float Indicators::GetNineEMA() {
    return _nineEMA;
}

float Indicators::GetTwelveSMA() {
    return _twelveSMA;
}

float Indicators::GetTwelveEMA() {
    return _twelveEMA;
}

float Indicators::GetTwentySixSMA() {
    return _twentySixSMA;
}

float Indicators::GetTwentySixEMA() {
    return _twentySixEMA;
}

float Indicators::GetMACD() {
    return _MACD;
}

float Indicators::GetVolume() {
    return _volume;
}