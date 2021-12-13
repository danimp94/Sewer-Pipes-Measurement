import numpy as np                        # Fundamental package for scientific computing
import matplotlib.pyplot as plt           # 2D plotting library producing publication quality figures
import pyrealsense2.pyrealsense2 as rs    # Intel RealSense cross-platform open-source API
import open3d as o3d
import imageio
import cv2
import pyransac3d as pyrsc                # open3d librairie to use RANSAC for different shapes
from datetime import datetime as date     # Library use to get the actual date and time
import RPi.GPIO as GPIO
import time
print("Environment Ready")

# Pin Definitons:
actuator = 4 # Broadcom pin 4 (pin 7 on pi)

# Pin Setup:
GPIO.setmode(GPIO.BCM) # Broadcom pin-numbering scheme
GPIO.setup(actuator, GPIO.OUT) # LED pin set as output

# 3.3v on pin 7 pi:
GPIO.output(actuator, GPIO.HIGH)
time.sleep(10)
print("sleep over")

# Configure depth and color streams
# Change resolution here
pipe = rs.pipeline()
cfg = rs.config()
cfg.enable_stream(rs.stream.depth,848, 480)

#Start streaming
pipe.start(cfg)

# Filter generates color images based on input depth frame
colorizer = rs.colorizer()

# Skip 5 first frames to give the Auto-Exposure time to adjust
#for x in range(5):pipe.wait_for_frames()

# Get intrinsic camera parameters
profile = pipe.get_active_profile()

# Change the type of stereo vision
#device = profile.get_device()
#depth_sensor = device.query_sensors()[0]
#depth_sensor.set_option(rs.option.emitter_enabled, 1.0)

# Store frameset
frameset = pipe.wait_for_frames()
depth_frame = frameset.get_depth_frame()

# Cleanup
pipe.stop()
print("Frames Captured")

# Convert images to numpy arrays
depth_image = np.asanyarray(depth_frame.get_data())

# Collect the actual date and time
timestamp = date.now().strftime("%Y-%m-%d-%H-%M")

# save both images (the name is changed each time using the timestamp in order to save all the images)
imageio.imwrite("Output/DepthImage/depth"+timestamp+".png", depth_image)

# Get back the images
depth_raw = o3d.io.read_image("Output/DepthImage/depth"+timestamp+".png")

# Get the default intrinsic parameters of the camera
p = o3d.camera.PinholeCameraIntrinsic(o3d.camera.PinholeCameraIntrinsicParameters.PrimeSenseDefault)
# Change the intrinsic parameters of the camera to match the chosen resolution
p.intrinsic_matrix=[[421.139, 0.0, 426.176], [ 0.0, 421.139, 237.017], [ 0.0, 0.0, 1.0]] # 848*480 resolution
# Create the point cloud from the rgbd image
pcd = o3d.geometry.PointCloud.create_from_depth_image(
    depth_raw,p)

# Flip itthe point cloud, otherwise it will be upside down
pcd.transform([[1, 0, 0, 0], [0, -1, 0, 0], [0, 0, -1, 0], [0, 0, 0, 1]])

# Save the point cloud
o3d.io.write_point_cloud("Output/PointCloud/cloud"+timestamp+".ply", pcd)

# 0v on pin 7 pi:
GPIO.output(actuator, GPIO.LOW)

GPIO.cleanup() # cleanup all GPIO
