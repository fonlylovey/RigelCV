#pragma once
#include "opencv/cv.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"

class ImageCompare
{
public:
	ImageCompare();
	ImageCompare(cv::Mat& imageA, cv::Mat& imageB);
	virtual ~ImageCompare();

	cv::Mat MoveDetect(cv::Mat preImage, cv::Mat curImage);

private:
	cv::Mat m_imageA;
	cv::Mat m_imageB;
};


