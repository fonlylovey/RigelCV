#include "RigelCV.h"
#include "opencv2/imgproc.hpp"

RigelCV::RigelCV()
{
}


RigelCV::~RigelCV()
{
}

QImage RigelCV::cvImageToQImage(cv::Mat cvImage)
{
	cv::cvtColor(cvImage, cvImage, CV_BGR2RGB);
	QImage img = QImage((const unsigned char*)(cvImage.data),
		cvImage.cols, cvImage.rows, QImage::Format_RGB888);
	return img;
}
