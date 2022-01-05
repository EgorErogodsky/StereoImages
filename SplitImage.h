#include <iostream>
#include <algorithm>
#include <map>
#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>
#include <ranges>
#include <iterator>

using namespace std;
using namespace cv;

void SplitImage(Mat& img, Mat& imgL, Mat& imgR);
