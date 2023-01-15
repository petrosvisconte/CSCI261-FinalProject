//PIERRE VISCONTI
//CSCI 261 - F
//FINAL PROJECT

#ifndef FINALPROJECT_DAILYDATA_H
#define FINALPROJECT_DAILYDATA_H

#include <string>
using std::string;

class DailyData {
public:
    DailyData();
    DailyData(string date, float open, float high, float low, float close, float adjClose, int volume);
    void SetDate(string date);
    void SetOpen(float open);
    void SetHigh(float high);
    void SetLow(float low);
    void SetClose(float close);
    void SetAdjClose(float adjClose);
    void SetVolume(int volume);
    string GetDate();
    float GetOpen();
    float GetHigh();
    float GetLow();
    float GetClose();
    float GetAdjClose();
    int GetVolume();
private:
    string _date;
    float _open;
    float _high;
    float _low;
    float _close;
    float _adjClose;
    int _volume;
};


#endif //FINALPROJECT_DAILYDATA_H
