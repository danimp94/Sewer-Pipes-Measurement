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