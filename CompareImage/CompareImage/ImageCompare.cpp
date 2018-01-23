#include "ImageCompare.h"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core/types.hpp"
#include <vector>

ImageCompare::ImageCompare(cv::Mat& imageA, cv::Mat& imageB)
{
	m_imageA = imageA;
	m_imageB = imageB;

	
}


ImageCompare::ImageCompare()
{

}

ImageCompare::~ImageCompare()
{
}

cv::Mat ImageCompare::MoveDetect(cv::Mat preImage, cv::Mat curImage)
{
	cv::Mat result;

	//1.将图像转为灰度图  
	cv::Mat preGrayImg, curGrayImg;
	cv::cvtColor(preImage, preGrayImg, CV_BGR2GRAY);
	cv::cvtColor(curImage, curGrayImg, CV_BGR2GRAY);

	cv::Mat diffImg;
	cv::absdiff(preGrayImg, curGrayImg, diffImg);

	//灰度图做差值
	//imshow("", diffImg);

	//3.对差值图diff_thresh进行阈值化处理  
	cv::Mat diff_thresh;
	cv::threshold(diffImg, diff_thresh, 0.0, 255, CV_THRESH_BINARY);
	//imshow("diff_thresh", diff_thresh);

	//腐蚀
	cv::Mat kerner_erode = getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	erode(diff_thresh, diff_thresh, kerner_erode);
	
	//膨胀
	cv::Mat dilateImg;
	cv::Mat kernel_dilate = getStructuringElement(cv::MORPH_RECT, cv::Size(15, 15));
	dilate(diff_thresh, dilateImg, kernel_dilate);
		
	cv::Mat hierarchy;
	std::vector<cv::Mat> contours;
	
	//try
	{
		//findContours(dilateImg, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	}
	//catch (cv::Exception exception)
	{
	//	auto strError = exception.err;
	//	auto strmsg = exception.msg;
	}
	
	result = dilateImg;
	//drawContours(result, contours, -1, cv::Scalar(0, 0, 255), 2);//在result上绘制轮廓  


	//imshow("result", dilateImg);
	return result;
}

