import numpy as np                        # Fundamental package for scientific computing
import matplotlib.pyplot as plt           # 2D plotting library producing publication quality figures
import pyrealsense2.pyrealsense2 as rs    # Intel RealSense cross-platform open-source API
import open3d as o3d
import imageio
import cv2
import pyransac3d as pyrsc                # open3d librairie to use RANSAC for different shapes
from datetime import datetime as date     # Library use to get the actual date and time


# Configure depth and color streams
# Change resolution here
pipe = rs.pipeline()
cfg = rs.config()
cfg.enable_stream(rs.stream.depth,848, 480)
cfg.enable_stream(rs.stream.color, 848, 480)

#Start streaming
pipe.start(cfg)

# Filter generates color images based on input depth frame
colorizer = rs.colorizer()

# Skip 5 first frames to give the Auto-Exposure time to adjust
for x in range(5):pipe.wait_for_frames()

# Get intrinsic camera parameters
profile = pipe.get_active_profile()

# Change the type of stereo vision
device = profile.get_device()
depth_sensor = device.query_sensors()[0]
depth_sensor.set_option(rs.option.emitter_enabled, 1.0)

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
imageio.imwrite("depth"+timestamp+".png", depth_image)

#Start streaming
pipe.start(cfg)

# Skip 5 first frames to give the Auto-Exposure time to adjust
for x in range(5):pipe.wait_for_frames()

# Get intrinsic camera parameters
profile2 = pipe.get_active_profile()

# Change the type of stereo vision
device2 = profile2.get_device()
depth_sensor2 = device2.query_sensors()[0]
depth_sensor2.set_option(rs.option.emitter_enabled, 0.0)

# Store frameset
frameset2 = pipe.wait_for_frames()
depth_frame2 = frameset2.get_depth_frame()

# Cleanup
pipe.stop()

# Convert images to numpy arrays
depth_image2 = np.asanyarray(depth_frame2.get_data())

# save both images (the name is changed each time using the timestamp in order to save all the images)
imageio.imwrite("depth2"+timestamp+".png", depth_image2)

# Get back the images
depth_raw = o3d.io.read_image("depth"+timestamp+".png")

# Get back the images
depth_raw2 = o3d.io.read_image("depth2"+timestamp+".png")

# Draw the RGB and depth image for passive and active mode
plt.subplot(1, 2, 1)
plt.title('Depth image')
plt.imshow(depth_raw)
plt.subplot(1, 2, 2)
plt.title('Depth image2')
plt.imshow(depth_raw2)
plt.show()

# Get the default intrinsic parameters of the camera
p = o3d.camera.PinholeCameraIntrinsic(o3d.camera.PinholeCameraIntrinsicParameters.PrimeSenseDefault)
# Change the intrinsic parameters of the camera to match the chosen resolution
p.intrinsic_matrix=[[421.139, 0.0, 426.176], [ 0.0, 421.139, 237.017], [ 0.0, 0.0, 1.0]] # 848*480 resolution
# Create the point cloud from the rgbd image
pcd = o3d.geometry.PointCloud.create_from_depth_image(
    depth_raw,p)
pcd2 = o3d.geometry.PointCloud.create_from_depth_image(
    depth_raw2,p)

# Flip itthe point cloud, otherwise it will be upside down
pcd2.transform([[1, 0, 0, 0], [0, -1, 0, 0], [0, 0, -1, 0], [0, 0, 0, 1]])
# Save the point cloud
o3d.io.write_point_cloud("cloud2"+timestamp+".ply", pcd2)
# Get back the point cloud
pcd_load2 = o3d.io.read_point_cloud("cloud2"+timestamp+".ply")

# Visualize the merge point cloud
o3d.visualization.draw_geometries([pcd_load2])

# open3d librairie to use RANSAC for a circular shape
circ = pyrsc.Circle()

# convert Open3D.o3d.geometry.PointCloud to numpy array (RANSAC needs a numpy array to work)
xyz_load = np.asarray(pcd_load2.points)
# RANSAC implementation for circular shape detection in point clouds
center, axis, radius, inliers = circ.fit(xyz_load, thresh=0.03, maxIteration=150)
print(radius*2000)

# Select the inliers and the outliers points
inlier_cloud = pcd_load2.select_by_index(inliers)
outlier_cloud = pcd_load2.select_by_index(inliers, invert=True)

# Merge the two point clouds
# Save the data structure
inlier_np = np.asarray(inlier_cloud.points)
outlier_np = np.asarray(outlier_cloud.points)
# Add the point clouds all together
rans_np = np.concatenate((inlier_np,outlier_np), axis=0)
# Get the individuals colors of each point cloud
inlier_color = np.asarray(inlier_cloud.colors)
outlier_color = np.asarray(outlier_cloud.colors)
rans_color = np.concatenate((inlier_color, outlier_color), axis=0)
# Create a new pointcloud instance and read the pointcloud, color together
rans = o3d.geometry.PointCloud()
rans.points = o3d.utility.Vector3dVector(rans_np)
rans.colors = o3d.utility.Vector3dVector(rans_color)
# Save the inlier and outlier point cloud
o3d.io.write_point_cloud("ransac_cloud"+timestamp+".ply", rans)
# Get back the inlier and outlier point cloud
rans_load = o3d.io.read_point_cloud("ransac_cloud"+timestamp+".ply")
# Visualize the inlier and outlier point clouds
o3d.visualization.draw_geometries([rans_load])