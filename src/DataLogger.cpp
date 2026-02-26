#include "DataLogger.hpp"

#include <iostream>
#include <fstream>

void DataLogger::log(double time, double setpoint, double measurement, double control){
    time_.push_back(time);
    setpoint_.push_back(setpoint);
    measurement_.push_back(measurement);
    control_.push_back(control);
}

void DataLogger::saveToFile(const std::string& filename){
    std::ofstream file(filename);

    if(!file.is_open()){
        std::cerr << "opening error";
        return;
    }
    
    file << "Time,Setpoint,Speed,Control\n";

    for(size_t i = 0; i < time_.size(); i++){
        file << time_[i] << ","
         << setpoint_[i] << ","
         << measurement_[i] << "," 
         << control_[i] << "\n";
    };

    file.close();
}
