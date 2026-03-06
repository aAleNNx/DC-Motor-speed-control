#pragma once

#include <vector>
#include <string>

class DataLogger{
public:
    DataLogger() = default;

    void log(double time,
             double setpoint,
             double measurement,
             double control,
             double load);

    void saveToFile(const std::string& filename);

private:
    std::vector<double> time_;
    std::vector<double> setpoint_;
    std::vector<double> measurement_;
    std::vector<double> control_;
    std::vector<double> load_;
};