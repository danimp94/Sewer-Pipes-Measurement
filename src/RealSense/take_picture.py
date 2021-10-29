import cv2                                # state of the art computer vision algorithms library
import numpy as np                        # fundamental package for scientific computing
import matplotlib.pyplot as plt           # 2D plotting library producing publication quality figures
import pyrealsense2 as rs                 # Intel RealSense cross-platform open-source API
import open3d as o3d
print("Environment Ready") 

# Configure depth and color streams
# Change resolution here
pipe = rs.pipeline()
cfg = rs.config()
cfg.enable_stream(rs.stream.depth)
cfg.enable_stream(rs.stream.color)

# Start streaming
profile = pipe.start(cfg)

# Filter generates color images based on input depth frame
colorizer = rs.colorizer()

# Skip 5 first frames to give the Auto-Exposure time to adjust
for x in range(5):
  pipe.wait_for_frames()
 
# Store frameset
frameset = pipe.wait_for_frames()
color_frame = frameset.get_color_frame()
depth_frame = frameset.get_depth_frame()
 
# Cleanup
pipe.stop()
print("Frames Captured")

# display 2D-images 
color = np.asanyarray(color_frame.get_data())
plt.rcParams["axes.grid"] = False
colorized_depth = np.asanyarray(colorizer.colorize(depth_frame).get_data())
plt.subplot(1, 2, 1)
plt.title('rgb image')
plt.imshow(color)
plt.subplot(1, 2, 2)
plt.title('depth image')
plt.imshow(colorized_depth)
plt.show()

