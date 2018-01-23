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

	//1.��ͼ��תΪ�Ҷ�ͼ  
	cv::Mat preGrayImg, curGrayImg;
	cv::cvtColor(preImage, preGrayImg, CV_BGR2GRAY);
	cv::cvtColor(curImage, curGrayImg, CV_BGR2GRAY);

	cv::Mat diffImg;
	cv::absdiff(preGrayImg, curGrayImg, diffImg);

	//�Ҷ�ͼ����ֵ
	//imshow("", diffImg);

	//3.�Բ�ֵͼdiff_thresh������ֵ������  
	cv::Mat diff_thresh;
	cv::threshold(diffImg, diff_thresh, 0.0, 255, CV_THRESH_BINARY);
	//imshow("diff_thresh", diff_thresh);

	//��ʴ
	cv::Mat kerner_erode = getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	erode(diff_thresh, diff_thresh, kerner_erode);
	
	//����
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
	//drawContours(result, contours, -1, cv::Scalar(0, 0, 255), 2);//��result�ϻ�������  


	//imshow("result", dilateImg);
	return result;
}

