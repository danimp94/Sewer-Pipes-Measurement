# Sewer-Pipes-Measurement

This project researches a solution for measuring the diameter of sewer pipes in cooperation with the project partners Aarhus Vand A/S and Aarsleff A/S, in order to avoid the entering of workers into the sewer system. Using the depth camera Intel Realsense D435i, active stereo is used to acquire a point cloud that is further processed by a Random Sample Consensus (RANSAC) algorithm to calculate the diameter of the pipes. To introduce and position the camera inside the pipe in order to improve the accuracy of the measurements, a model and a stability control with an extendable linear actuator is designed. Then, a prototype is built and tested in a laboratory setup and in an outdoor testing plant of Aarhus Vand. A key finding is that the in-pipe measurement system leads to improved measurement results.

## Table of contents

- Dynamics model using Matlab and Simulink: [Dynamics](src/dynamics/)
- RealSense D435i RANSAC implementation: [RealSense](src/realsense-ransac/)
- Linear Actuator Control: [LA_Control](src/linear-actuator/)
