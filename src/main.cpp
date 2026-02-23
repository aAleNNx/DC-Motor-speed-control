#include <iostream>

#include "PID.hpp"
#include "DCMotor.hpp"

int main() {
    double Kp = 1.5;
    double Ki = 3;
    double Kd = 0.01;
    double Ts = 0.01;

    int iter = 1000;

    PID regulator = PID(Kp, Ki, Kd, Ts);

    double setpoint = 10;

    double J = 0.1;
    double b = 0.1;
    double K = 0.5;

    regulator.setOutputLimits(-12.0, 12.0);

    DCMotor motor = DCMotor(J, b, K, Ts);

    double omega = 0.0;

    for(int i = 0; i < iter; i++){
        double u = regulator.update(setpoint, omega);
        
        motor.step(u);
        omega = motor.getSpeed();

        if(i == 200){motor.setLoadTorque(8);}
        else if(i == 700){motor.setLoadTorque(2);};
        
        std::cout << "iteracja: " << i + 1
        << "    measurement: " << omega 
        << "    control: " << u << std::endl;
    }
    return 0;
}