#include "ImageCompare.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

ImageCompare::ImageCompare(cv::Mat& imageA, cv::Mat& imageB)
{
	m_imageA = imageA;
	m_imageB = imageB;

}


ImageCompare::~ImageCompare()
{
}


