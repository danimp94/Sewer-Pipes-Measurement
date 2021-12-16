# RANSAC algorithm for RealSense D435i

## Explain how to run the script and what parameters are tunable EXAMPLE BELOW:


## Steps followed in this script

* Download and unzip the RansacShapeAligner folder
* Open RansacShapeAligner folder
* Open the main.cpp file and modify the desired parameters (threshold, resolution, required point for a primitive, …)
* Open the CMakeLists.txt file and compile it
* Open out/build/x64-Debug folder
* Open the PowerShell window in that folder
* Find a relevant point cloud of a cylinder that you want to analyse
* Write ./main.exe -f PathToYourPointCloud
* The results can be found in the file NameOfYourPointCloud-cylinders.txt
