#include <pcl/visualization/cloud_viewer.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>
#include "ImageToPointCloud.h"

using namespace std;
using namespace cv;

pcl::PointCloud<pcl::PointXYZRGB>::Ptr ImageToPointCloud(Mat &projection)
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointCloud(new pcl::PointCloud<pcl::PointXYZRGB>());
	for (int i = 0; i < projection.cols ; i++)
	{
		for (int j = 0; j < projection.rows ; j++)
		{
			pcl::PointXYZRGB point;

			//Vec3b channels = projection.at<Vec3b>(Point(i, j)); //bgr

			/*point.x = projection.cols-i-projection.cols/2;
			point.y = projection.rows-j-projection.rows/2;
			point.z = 0;*/
			point.x = i;
			point.y = j;
			point.z = int(projection.at<float>(Point(i, j)));
			/*point.r = (uint8_t)channels[2];
			point.g = (uint8_t)channels[1];
			point.b = (uint8_t)channels[0];*/

			point.r = (uint8_t)255;
			
			pointCloud->points.push_back(point);
		}
	}
	return pointCloud;
}