# DC Motor Speed Control Simulation (C++)

Discrete-time PID control of a DC motor model with actuator saturation and disturbance injection.

This project implements a modular closed-loop speed control system for a DC motor using a discrete PID controller.

The simulation includes:
- Mechanical DC motor model (inertia, friction, torque constant)
- Discrete-time PID with anti-windup
- Actuator voltage saturation
- Disturbance torque injection
- Modular architecture separating controller, plant and simulation layers


Mechanical dynamics:

J * dω/dt = K * V - bω - T_load

Discrete-time integration (Forward Euler):

ω[k+1] = ω[k] + Ts * ((K*V - bω - T_load)/J)


Features:
- Anti-windup via output clamping
- Modular component-based architecture
- No dynamic memory allocation
- Discrete-time implementation

How to Build:

mkdir build
cd build
cmake ..
make
./pid_app