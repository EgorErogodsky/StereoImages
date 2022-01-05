#include "GetDisparityMap.h"

// Получение карты глубины мнимого изображения.
Mat GetDisparityMap(Mat& img)
{
	int numDisparities = 16*3;
	int blockSize = 23;

	Mat imgL, imgR;
	SplitImage(img, imgL, imgR);
	
	Mat disparityMap(img.rows, img.cols, CV_16FC3);
	Ptr<StereoBM> stereo = StereoBM::create(numDisparities, blockSize);
	stereo->compute(imgL, imgR, disparityMap);

	//
	// Можно посмотреть disparity map
	//
	/*Mat displayDisparityMap;
	disparityMap.convertTo(displayDisparityMap, CV_8U, 255. / (numDisparities * 16.));
	imshow("gray", displayDisparityMap);
	waitKey();*/
	
	disparityMap.convertTo(disparityMap, CV_32F);

	return disparityMap;
}