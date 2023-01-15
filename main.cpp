//PIERRE VISCONTI
//CSCI 261 - F
//FINAL PROJECT

#include <iostream>
#include "HistoricalData.h"
#include "CalculateIndicators.h"
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::ofstream;

int main() {
    const int THIRTEEN_MOVING_AVERAGE = 13;
    const int TWENTY_ONE_MOVING_AVERAGE = 21;
    const int NINE_MOVING_AVERAGE = 9;
    const int TWELVE_MOVING_AVERAGE = 12;
    const int TWENTY_SIX_MOVING_AVERAGE = 26;
    string dataFileName;

    cout << "TRADING BOT, by Pierre Visconti" << endl << endl;
    cout << "You will be prompted to enter the name of a CSV file." << endl;
    cout << "The data in the file must be in the following order: " << endl;
    cout << "date, open price, highest price, lowest price, closing price, adjusted close price, and volume." << endl;
    cout << "Each line must contain stock data for the day. With the next line containing the data for the following day." << endl << endl;
    cout << "Please enter the name of your CSV file" << endl;
    cin >> dataFileName;

    //Reads data from CSV file, then closes the file
    HistoricalData hd(dataFileName);
    if (!hd.CheckFile()) {
        cerr << "File failed to open";
        return -1;
    }
    hd.ReadFileData();
    hd.CloseFile();

    //Calculates technical indicators based off data read from CSV file
    CalculateIndicators ci;
    //Calculations for RSI
    ci.CalculateRSI(hd.dataSet); //Calculates 14 day RSI
    //Calculations for EMA
    ci.CalculateSMA(hd.dataSet, THIRTEEN_MOVING_AVERAGE); //13 day SMA
    ci.CalculateEMA(hd.dataSet, THIRTEEN_MOVING_AVERAGE); //13 day EMA
    ci.CalculateSMA(hd.dataSet, TWENTY_ONE_MOVING_AVERAGE); //21 day SMA
    ci.CalculateEMA(hd.dataSet, TWENTY_ONE_MOVING_AVERAGE); //21 day EMA
    //Calculations for signal
    ci.CalculateSMA(hd.dataSet, NINE_MOVING_AVERAGE); //9 day SMA
    ci.CalculateEMA(hd.dataSet, NINE_MOVING_AVERAGE); //9 day EMA
    //Calculations for MACD
    ci.CalculateSMA(hd.dataSet, TWELVE_MOVING_AVERAGE); //12 day SMA
    ci.CalculateEMA(hd.dataSet, TWELVE_MOVING_AVERAGE); //12 day EMA
    ci.CalculateSMA(hd.dataSet, TWENTY_SIX_MOVING_AVERAGE); //26 day SMA
    ci.CalculateEMA(hd.dataSet, TWENTY_SIX_MOVING_AVERAGE); //26 day EMA
    ci.CalculateMACD(); //Calculates MACD based off 12 and 26 day EMA
    //Adds all tech data to a vector of indicators
    ci.CombineTechnicalData(hd.dataSet);

    //Writes all indicator data to a CSV file
    ofstream techData;
    techData.open("indicatorData.csv");
    if (techData.is_open()) {
        for (int i = 0; i < ci.technicalData.size(); i++) {
            techData << ci.technicalData.at(i).GetRSI() << ",";
            techData << ci.technicalData.at(i).GetThirteenSMA() << ",";
            techData << ci.technicalData.at(i).GetThirteenEMA() << ",";
            techData << ci.technicalData.at(i).GetTwentyOneSMA() << ",";
            techData << ci.technicalData.at(i).GetTwentyOneEMA() << ",";
            techData << ci.technicalData.at(i).GetNineSMA() << ",";
            techData << ci.technicalData.at(i).GetNineEMA() << ",";
            techData << ci.technicalData.at(i).GetTwelveSMA() << ",";
            techData << ci.technicalData.at(i).GetTwelveEMA() << ",";
            techData << ci.technicalData.at(i).GetTwentySixSMA() << ",";
            techData << ci.technicalData.at(i).GetTwentySixEMA() << ",";
            techData << ci.technicalData.at(i).GetMACD() << ",";
            techData << ci.technicalData.at(i).GetVolume() << endl;
        }
    } else {
        cerr << "File failed to open" << endl;
        return -2;
    }
    techData.close();


    return 0;
}