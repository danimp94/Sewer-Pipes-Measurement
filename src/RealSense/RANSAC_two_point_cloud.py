import numpy as np
import open3d as o3d
import pyransac3d as pyrsc
from datetime import datetime as date

# Get back the point cloud
pcd_load = o3d.io.read_point_cloud("cloud.ply")
pcd_load2 = o3d.io.read_point_cloud("cloud2.ply")

# Merge the two point clouds
# Save the data structure
pcd1_np = np.asarray(pcd_load.points)
pcd2_np = np.asarray(pcd_load2.points)
# Add the point clouds all together
pcds_np = np.concatenate((pcd1_np,pcd2_np), axis=0)
# Get the individuals colors of each point cloud
pcd1_color = np.asarray(pcd_load.colors)
pcd2_color = np.asarray(pcd_load2.colors)
pcds_color = np.concatenate((pcd1_color, pcd2_color), axis=0)
# Create a new pointcloud instance and read the pointcloud, color together
pcds = o3d.geometry.PointCloud()
pcds.points = o3d.utility.Vector3dVector(pcds_np)
pcds.colors = o3d.utility.Vector3dVector(pcds_color)
# Save the merge point cloud
timestamp = date.now().strftime("%Y-%m-%d-%H-%M")
o3d.io.write_point_cloud("merge_cloud"+timestamp+".ply", pcds)
# Get back the merge point cloud
pcds_load = o3d.io.read_point_cloud("merge_cloud"+timestamp+".ply")
# Visualize the merge point cloud
o3d.visualization.draw_geometries([pcds_load])

# open3d librairie to use RANSAC for a circular shape
circ = pyrsc.Circle()

# convert Open3D.o3d.geometry.PointCloud to numpy array (RANSAC needs a numpy array to work)
xyz_load = np.asarray(pcds_load.points)
# RANSAC implementation for circular shape detection in point clouds
center, axis, radius, inliers = circ.fit(xyz_load, thresh=0.1, maxIteration=2)
print(radius)

# Select the inliers and the outliers points
inlier_cloud = pcd_load.select_by_index(inliers)
outlier_cloud = pcd_load.select_by_index(inliers, invert=True)

# Paint the inliers points in red and the rest in grey
inlier_cloud.paint_uniform_color([1, 0, 0])
outlier_cloud.paint_uniform_color([0.6, 0.6, 0.6])

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
