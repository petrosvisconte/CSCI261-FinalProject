//PIERRE VISCONTI
//CSCI 261 - F
//FINAL PROJECT

#ifndef FINALPROJECT_CALCULATEINDICATORS_H
#define FINALPROJECT_CALCULATEINDICATORS_H

#include <vector>
#include "DailyData.h"
#include "Indicators.h"
using std::vector;

class CalculateIndicators {
public:
    static const int LARGEST_TIMEFRAME = 26;
    vector<Indicators> technicalData;
    CalculateIndicators();
    void CalculateRSI(vector<DailyData> dataSet);
    void CalculateSMA(vector<DailyData> dataSet, int timeInterval);
    void CalculateEMA(vector<DailyData> dataSet, int timeInterval);
    void CalculateMACD();
    float CalculateWeightedMultiplier(int timeInterval);
    void CombineTechnicalData(vector<DailyData> dataSet);
    float GetRSI(int index);
    float GetThirteenSMA(int index);
    float GetThirteenEMA(int index);
    float GetTwentyOneSMA(int index);
    float GetTwentyOneEMA(int index);
    float GetNineSMA(int index);
    float GetNineEMA(int index);
    float GetTwelveSMA(int index);
    float GetTwelveEMA(int index);
    float GetTwentySixSMA(int index);
    float GetTwentySixEMA(int index);
    float GetMACD(int index);
private:
    //For RSI
    vector<float> _RSI;
    //For EMA
    vector<float> _thirteenSMA;
    vector<float> _thirteenEMA;
    vector<float> _twentyOneSMA;
    vector<float> _twentyOneEMA;
    //For Signal
    vector<float> _nineSMA;
    vector<float> _nineEMA;
    //For MACD
    vector<float> _twelveSMA;
    vector<float> _twelveEMA;
    vector<float> _twentySixSMA;
    vector<float> _twentySixEMA;
    vector<float> _MACD;
};


#endif //FINALPROJECT_CALCULATEINDICATORS_H
