#include "Visualize.h"

// ����������� ������ �����.
void Visualize(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointCloud)
{
	pcl::visualization::CloudViewer viewer ("Stereo image");
	viewer.showCloud(pointCloud);
	while (!viewer.wasStopped())
	{
	}
}