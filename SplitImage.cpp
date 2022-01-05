#include "SplitImage.h"

// Создание двух стереокартинок, отстоящих друг от друга 
//	на сдвиг d, равный периоду повторения рисунка на исходной стереокартинке.
// Поиск d производится путём нахождения наиболее частого 
//	расстояния между одинаковыми пикселями вдоль оси Ox на половине изображения.
void SplitImage(Mat &img, Mat &imgL, Mat &imgR)
{ 
	map<int, int> possibleDisparities;
	for (int k = 0; k < img.rows; k++)
	{
		for (int i = 0; i < img.cols/2 - 1; i++)
		{
			for (int j = i + 1; j < img.cols/2; j++)
			{
				Vec3b colour1 = img.at<Vec3b>(Point(i, k));
				Vec3b colour2 = img.at<Vec3b>(Point(j, k));
				if (colour1[0] == colour2[0]
					&& colour1[1] == colour2[1]
					&& colour1[2] == colour2[2]
					&& j-i > 10)
				{
					possibleDisparities[j - i]++;
				}
			}
		}
	}

	map<int, int>::iterator mostFrequentD = ranges::max_element(possibleDisparities,
		[](const pair<int, int> a,
			const pair<int, int> b) ->
		bool {return a.second < b.second; });
		
	int d = mostFrequentD->first;

	int width = img.cols - d;
	Rect rL(0, 0, width, img.rows);
	Rect rR(img.cols - width, 0, width, img.rows);
	Rect rOrig(d / 2, 0, width - d / 2, img.rows);

	img(rL).copyTo(imgL);
	cvtColor(imgL, imgL, COLOR_BGR2GRAY);

	img(rR).copyTo(imgR);	
	cvtColor(imgR, imgR, COLOR_BGR2GRAY);

	img(rOrig).copyTo(img);
}