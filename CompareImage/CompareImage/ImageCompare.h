#pragma once
#include "opencv/cv.h"


class ImageCompare
{
public:
	ImageCompare(cv::Mat& imageA, cv::Mat& imageB);
	virtual ~ImageCompare();


private:
	cv::Mat m_imageA;
	cv::Mat m_imageB;
};


