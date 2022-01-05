#include <pcl/visualization/cloud_viewer.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>
#include "ImageToPointCloud.h"
#include "Visualize.h"
#include "SplitImage.h"
#include "GetDisparityMap.h"
#include "CreatePointCloud.h"

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	string path = argv[1]; 
	Mat img = imread(path, IMREAD_COLOR);

	Mat disparityMap = GetDisparityMap(img);

	pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointCloud = CreatePointCloud(disparityMap, img);

	Visualize(pointCloud);
}