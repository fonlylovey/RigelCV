#include "MainWidget.h"
#include "ImageCompare.h"
#include "RigelCV.h"
#include <QPixmap>
#include "opencv2/highgui.hpp"


MainWidget::MainWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	auto image1 = cv::imread("D:/WorkSpace/Data/111.png");
	auto image2 = cv::imread("D:/WorkSpace/Data/222.png");
	std::string strInfo = "";
	
	//LOG() << "asd";
// 	LogStream strStrem;
// 	strStrem << "123";
	//ImageCompare imgCompare;
	//auto matImg = imgCompare.MoveDetect(image1, image2);
	


	//cv::cvtColor(image, image, CV_BGR2RGB);
	//imshow("hello openCV", matImg);
	//imshow("hello openCV", image2);
	//QImage img = QImage((const unsigned char*)(image.data),
	//	image.cols, image.rows, QImage::Format_RGB888);
	//ui.label_left->setPixmap(QPixmap::fromImage(img));
	//ui.label_right->setPixmap(QPixmap::fromImage(qImageS));
}

void MainWidget::slotGrayscale()
{

}

void MainWidget::slotSobel()
{

}

void MainWidget::slotDenoise()
{

}
