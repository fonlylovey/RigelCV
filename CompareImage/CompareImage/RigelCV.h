#pragma once
#include "opencv2/imgcodecs.hpp"
#include <QImage>

class RigelCV
{
public:
	RigelCV();
	~RigelCV();
	static QImage cvImageToQImage(cv::Mat cvImage);
};

