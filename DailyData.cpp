//PIERRE VISCONTI
//CSCI 261 - F
//FINAL PROJECT

#include "DailyData.h"

//Default constructor
DailyData::DailyData() {}

//Parameterized constructor
DailyData::DailyData(string date, float open, float high, float low, float close, float adjClose, int volume) {
    _date = date;
    _open = open;
    _high = high;
    _low = low;
    _close = close;
    _adjClose = adjClose;
    _volume = volume;
}

//Set function
void DailyData::SetDate(string date) {
    _date = date;
}

//Set function
void DailyData::SetOpen(float open) {
    _open = open;
}

//Set function
void DailyData::SetHigh(float high) {
    _high = high;
}

//Set function
void DailyData::SetLow(float low) {
    _low = low;
}

//Set function
void DailyData::SetClose(float close) {
    _close = close;
}

//Set function
void DailyData::SetAdjClose(float adjClose) {
    _adjClose = adjClose;
}

//Set function
void DailyData::SetVolume(int volume) {
    _volume = volume;
}

//Get function
string DailyData::GetDate() {
    return _date;
}

//Get function
float DailyData::GetOpen() {
    return _open;
}

//Get function
float DailyData::GetHigh() {
    return _high;
}

//Get function
float DailyData::GetLow() {
    return _low;
}

//Get function
float DailyData::GetClose() {
    return _close;
}

//Get function
float DailyData::GetAdjClose() {
    return _adjClose;
}

//Get function
int DailyData::GetVolume() {
    return _volume;
}