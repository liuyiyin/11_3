// 11_3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	cv::Mat src = imread("D:\\gtest.jpg", 0);
	cv::Mat dst;
	uchar Lut[256];
	for (int i = 0; i<256; i++) {
		float a = (float)i / 255;
		float b = powf(a, 0.4);
		Lut[i] = b * 255;
	}
	src.copyTo(dst);
	MatIterator_<uchar> it, end;
	for (it = dst.begin<uchar>(), end = dst.end<uchar>(); it != end; it++) {
		*it = Lut[(*it)];
	}
	cv::imshow("src", src);
	cv::imshow("dst", dst);
	cv::waitKey(0);
	return 0;
}
