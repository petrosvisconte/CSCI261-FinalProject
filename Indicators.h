//PIERRE VISCONTI
//CSCI 261 - F
//FINAL PROJECT

#ifndef FINALPROJECT_INDICATORS_H
#define FINALPROJECT_INDICATORS_H

class Indicators {
public:
    Indicators();
    void SetRSI(float RSI);
    void SetThirteenSMA(float SMA);
    void SetThirteenEMA(float EMA);
    void SetTwentyOneSMA(float SMA);
    void SetTwentyOneEMA(float EMA);
    void SetNineSMA(float SMA);
    void SetNineEMA(float EMA);
    void SetTwelveSMA(float SMA);
    void SetTwelveEMA(float EMA);
    void SetTwentySixSMA(float SMA);
    void SetTwentySixEMA(float EMA);
    void SetMACD(float MACD);
    void SetVolume(int volume);
    float GetRSI();
    float GetThirteenSMA();
    float GetThirteenEMA();
    float GetTwentyOneSMA();
    float GetTwentyOneEMA();
    float GetNineSMA();
    float GetNineEMA();
    float GetTwelveSMA();
    float GetTwelveEMA();
    float GetTwentySixSMA();
    float GetTwentySixEMA();
    float GetMACD();
    float GetVolume();

private:
    float _RSI;
    float _thirteenSMA;
    float _thirteenEMA;
    float _twentyOneSMA;
    float _twentyOneEMA;
    float _nineSMA;
    float _nineEMA;
    float _twelveSMA;
    float _twelveEMA;
    float _twentySixSMA;
    float _twentySixEMA;
    float _MACD;
    int _volume;
};


#endif //FINALPROJECT_INDICATORS_H
