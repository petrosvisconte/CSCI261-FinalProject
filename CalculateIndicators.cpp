//PIERRE VISCONTI
//CSCI 261 - F
//FINAL PROJECT

#include "CalculateIndicators.h"

//Default constructor
CalculateIndicators::CalculateIndicators() {}

//Calculates Relative Strength Index (RSI) based on a 14 day scale using price averages
/*
 * HOW TO CALCULATE RSI:
 * Add up gain of each day over a 14 day period to find total gain
 * Add up loss of each day over a 14 day period to find total loss
 * Find the average gain over the 14 day period by dividing total gain by 14
 * Find the average loss over the 14 day period by dividing total loss by 14
 * Then divide the average gain by the average loss, add 1, and divide 100 by that number
 * Then subtract that number from 100 to get your daily RSI value
 * Note: If RSI > 70, stock is considered overbought, if RSI < 30, stock is considered oversold.
 */
void CalculateIndicators::CalculateRSI (vector<DailyData> dataSet) {
    int count  = 0;

    for (int i = 0; i < dataSet.size() - 14; i++) {
        float totalGain = 0.0;
        float totalLoss = 0.0;
        for (int j = count; j < count + 14; j++) {
            if (dataSet.at(j).GetClose() > dataSet.at(j).GetOpen()) {            //If stock gained value
                totalGain += dataSet.at(j).GetClose() - dataSet.at(j).GetOpen();
            } else if (dataSet.at(j).GetOpen() > dataSet.at(j).GetClose()) {     // If stock lost value
                totalLoss += dataSet.at(j).GetOpen() - dataSet.at(j).GetClose();
            }
        }
        float averageGain = totalGain / 14.0;
        float averageLoss = totalLoss / 14.0;
        _RSI.push_back(100 - (100 / ((averageGain / averageLoss) + 1)));
        count ++;
    }
}

/* Calculates Simple Moving Average (SMA) for a time period based on the parameter passed
 * HOW TO CALCULATE SMA:
 * Find the sum of the stock's closing price for the number of days in a time period
 * Divide the sum by the number of days in the time period
 */
void CalculateIndicators::CalculateSMA (vector<DailyData> dataSet, int timeInterval) {
    int count = 0;

    for (int i = 0; i < dataSet.size() - timeInterval; i++) {
        float sum = 0;
        for (int j = count; j < count + timeInterval; j++) {
            sum += dataSet.at(j).GetClose();
        }
        if (timeInterval == 9) {
            _nineSMA.push_back(sum/(float)timeInterval);
        } else if (timeInterval == 12) {
            _twelveSMA.push_back(sum/(float)timeInterval);
        } else if (timeInterval == 13) {
            _thirteenSMA.push_back(sum/(float)timeInterval);
        } else if (timeInterval == 21) {
            _twentyOneSMA.push_back(sum/(float)timeInterval);
        } else if (timeInterval == 26) {
            _twentySixSMA.push_back(sum/(float)timeInterval);
        }
        count ++;
    }
}

/* Calculates Exponential Moving Average (EMA) for a time period based on the parameter passed
 * HOW TO CALCULATE EMA
 * Find the sum of the current price of the stock and the weighted multiplier
 * Then find the sum of the EMA value of the previous day multiplied by (1 - the weighted multiplier)
 * Then add these two numbers from the previous steps together to get the EMA
 */
void CalculateIndicators::CalculateEMA (vector<DailyData> dataSet, int timeInterval) {
    int sizeSMA;
    if (timeInterval == 9) {
        sizeSMA = _nineSMA.size();
    } else if (timeInterval == 12) {
        sizeSMA = _twelveSMA.size();
    } else if (timeInterval == 13) {
        sizeSMA = _thirteenSMA.size();
    } else if (timeInterval == 21) {
        sizeSMA = _twentyOneSMA.size();
    } else if (timeInterval == 26) {
        sizeSMA = _twentySixSMA.size();
    }

    for (int i = 0; i < sizeSMA; i++) {
        if (i == 0) {
            if (timeInterval == 9) {
                _nineEMA.push_back(_nineSMA.at(0));
            } else if (timeInterval == 12) {
                _twelveEMA.push_back(_twelveSMA.at(0));
            } else if (timeInterval == 13) {
                _thirteenEMA.push_back(_thirteenSMA.at(0));
            } else if (timeInterval == 21) {
                _twentyOneEMA.push_back(_twentyOneSMA.at(0));
            } else if (timeInterval == 26) {
                _twentySixEMA.push_back(_twentySixSMA.at(0));
            }
        } else {
            float ema;
            if (timeInterval == 9) {
                ema = (dataSet.at(i).GetClose() - _nineEMA.at(i - 1)) * CalculateWeightedMultiplier(timeInterval) + _nineEMA.at(i - 1);
                _nineEMA.push_back(ema);
            } else if (timeInterval == 12) {
                ema = (dataSet.at(i).GetClose() - _twelveEMA.at(i - 1)) * CalculateWeightedMultiplier(timeInterval) + _twelveEMA.at(i - 1);
                _twelveEMA.push_back(ema);
            } else if (timeInterval == 13) {
                ema = (dataSet.at(i).GetClose() - _thirteenEMA.at(i - 1)) * CalculateWeightedMultiplier(timeInterval) + _thirteenEMA.at(i - 1);
                _thirteenEMA.push_back(ema);
            } else if (timeInterval == 21) {
                ema = (dataSet.at(i).GetClose() - _twentyOneEMA.at(i - 1)) * CalculateWeightedMultiplier(timeInterval) + _twentyOneEMA.at(i - 1);
                _twentyOneEMA.push_back(ema);
            } else if (timeInterval == 26) {
                ema = (dataSet.at(i).GetClose() - _twentySixEMA.at(i - 1)) * CalculateWeightedMultiplier(timeInterval) + _twentySixEMA.at(i - 1);
                _twentySixEMA.push_back(ema);
            }
        }
    }
}

void CalculateIndicators::CalculateMACD() {
   for (int i = 0; i < _twentySixEMA.size(); i++) {
       float macd = _twelveEMA.at(i + 11) - _twentySixEMA.at(i);
       _MACD.push_back(macd);
   }
}

/* Calculates weighted multiplier used in EMA calculation
 * HOW TO CALCULATE WEIGHTED MULTIPLIER
 * Divide the number 2 by the number of days in a time period plus one.
 */
float CalculateIndicators::CalculateWeightedMultiplier (int timeInterval) {
    return 2 % (timeInterval + 1);
}

void CalculateIndicators::CombineTechnicalData(vector<DailyData> dataSet) {
    for (int i = 0; i < _MACD.size(); i++) {
        Indicators indicator;
        indicator.SetRSI(_RSI.at(i + (LARGEST_TIMEFRAME - 14)));
        indicator.SetThirteenSMA(_thirteenSMA.at(i + (LARGEST_TIMEFRAME - 13)));
        indicator.SetThirteenEMA(_thirteenEMA.at(i + (LARGEST_TIMEFRAME - 13)));
        indicator.SetTwentyOneSMA(_twentyOneSMA.at(i + (LARGEST_TIMEFRAME - 21)));
        indicator.SetTwentyOneEMA(_twentyOneEMA.at(i + (LARGEST_TIMEFRAME - 21)));
        indicator.SetNineSMA(_nineSMA.at(i + (LARGEST_TIMEFRAME - 9)));
        indicator.SetNineEMA((_nineEMA.at(i + (LARGEST_TIMEFRAME - 9))));
        indicator.SetTwelveSMA(_twelveSMA.at(i + (LARGEST_TIMEFRAME - 12)));
        indicator.SetTwelveEMA(_twelveEMA.at(i + (LARGEST_TIMEFRAME - 12)));
        indicator.SetTwentySixSMA(_twentySixSMA.at(i + (LARGEST_TIMEFRAME - 26)));
        indicator.SetTwentySixEMA(_twentySixEMA.at(i + (LARGEST_TIMEFRAME - 26)));
        indicator.SetMACD(i);
        indicator.SetVolume(dataSet.at(i + 26).GetVolume());

        technicalData.push_back(indicator);
    }
}

float CalculateIndicators::GetRSI(int index) {
    return _RSI.at(index);
}

float CalculateIndicators::GetThirteenSMA(int index) {
    return _thirteenSMA.at(index);
}

float CalculateIndicators::GetThirteenEMA(int index) {
    return _thirteenEMA.at(index);
}

float CalculateIndicators::GetTwentyOneSMA(int index) {
    return _twentyOneSMA.at(index);
}

float CalculateIndicators::GetTwentyOneEMA(int index) {
    return _twentyOneEMA.at(index);
}

float CalculateIndicators::GetNineSMA(int index) {
    return _nineSMA.at(index);
}

float CalculateIndicators::GetNineEMA(int index) {
    return _nineEMA.at(index);
}

float CalculateIndicators::GetTwelveSMA(int index) {
    return _twelveSMA.at(index);
}

float CalculateIndicators::GetTwelveEMA(int index) {
    return _twelveEMA.at(index);
}

float CalculateIndicators::GetTwentySixSMA(int index) {
    return _twentySixSMA.at(index);
}

float CalculateIndicators::GetTwentySixEMA(int index) {
    return _twentySixEMA.at(index);
}

float CalculateIndicators::GetMACD(int index) {
    return _MACD.at(index);
}





