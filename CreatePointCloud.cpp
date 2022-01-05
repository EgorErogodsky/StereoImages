#include "CreatePointCloud.h"

// Создание облака точек из карты глубины.
// Фон не отображается.
pcl::PointCloud<pcl::PointXYZRGB>::Ptr CreatePointCloud(Mat disparityMap, Mat img)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointCloud(new pcl::PointCloud<pcl::PointXYZRGB>());
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			float z = disparityMap.at<float>(Point(j, i));
			
			if (z > 0)
			{
				pcl::PointXYZRGB point;

				point.x = j - img.cols / 2;
				point.y = img.rows - i - img.rows / 2;
				point.z = z;

				Vec3b channels = img.at<Vec3b>(Point(j, i)); //bgr
				point.r = (uint8_t)channels[2];
				point.g = (uint8_t)channels[1];
				point.b = (uint8_t)channels[0];

				pointCloud->points.push_back(point);
			}
		}
	}

	return pointCloud;
}