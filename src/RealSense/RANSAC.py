import numpy as np
import open3d as o3d
import pyransac3d as pyrsc

# Get back the point cloud
pcd_load = o3d.io.read_point_cloud("cloud22021-11-16-08-56.ply")

# open3d librairie to use RANSAC for a circular shape
circ = pyrsc.Circle()

# convert Open3D.o3d.geometry.PointCloud to numpy array (RANSAC needs a numpy array to work)
xyz_load = np.asarray(pcd_load.points)
# RANSAC implementation for circular shape detection in point clouds
center, axis, radius, inliers = circ.fit(xyz_load, thresh=0.1, maxIteration=2)

# Select the inliers and the outliers points
inlier_cloud = pcd.select_by_index(inliers)
outlier_cloud = pcd.select_by_index(inliers, invert=True)

# Paint the inliers points in red and the rest in grey
inlier_cloud.paint_uniform_color([1, 0, 0])
outlier_cloud.paint_uniform_color([0.6, 0.6, 0.6])

# Visualize the inlier and outlier point clouds
o3d.visualization.draw_geometries([inlier_cloud, outlier_cloud])

