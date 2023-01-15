//PIERRE VISCONTI
//CSCI 261 - F
//FINAL PROJECT

#ifndef FINALPROJECT_HISTORICALDATA_H
#define FINALPROJECT_HISTORICALDATA_H

#include <vector>
#include <fstream>
#include "DailyData.h"
using std::vector;
using std::ifstream;

class HistoricalData {
public:
    vector<DailyData> dataSet;
    explicit HistoricalData(string name);
    bool CheckFile();
    void ReadFileData();
    void CloseFile();
private:
    ifstream _file;
    string _name;
};


#endif //FINALPROJECT_HISTORICALDATA_H
