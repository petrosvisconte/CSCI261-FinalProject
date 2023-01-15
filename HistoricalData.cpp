//PIERRE VISCONTI
//CSCI 261 - F
//FINAL PROJECT

#include "HistoricalData.h"

//Parameterized constructor
HistoricalData::HistoricalData(string name) {
    _name = name;
}

//Checks if file is open, returns false if not
bool HistoricalData::CheckFile() {
    _file.open(_name);
    return _file.is_open();
}

//Reads data from file and adds values to vector of DailyData objects
void HistoricalData::ReadFileData() {
    string line;

    while (getline(_file,line)) {
            DailyData d;

            d.SetDate(line.substr(0,line.find(',')));
            line.replace(0, line.find(',') + 1,"");

            d.SetOpen(stof(line.substr(0,line.find(','))));
            line.replace(0, line.find(',') + 1,"");

            d.SetHigh(stof(line.substr(0,line.find(','))));
            line.replace(0, line.find(',') + 1,"");

            d.SetLow(stof(line.substr(0,line.find(','))));
            line.replace(0, line.find(',') + 1,"");

            d.SetClose(stof(line.substr(0,line.find(','))));
            line.replace(0, line.find(',') + 1,"");

            d.SetAdjClose(stof(line.substr(0,line.find(','))));
            line.replace(0, line.find(',') + 1,"");

            d.SetVolume(stoi(line));

            dataSet.push_back(d);
        }
}

void HistoricalData::CloseFile() {
    _file.close();
}
