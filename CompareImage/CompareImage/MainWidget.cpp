#include "MainWidget.h"
#include "ImageCompare.h"
#include "RigelCV.h"
#include <QPixmap>

MainWidget::MainWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	auto image = cv::imread("123.png");
	//ImageCompare imCom;
	QImage qImage = RigelCV::cvImageToQImage(image);
	ui.label_left->setPixmap(QPixmap::fromImage(qImage));
	ui.label_right->setPixmap(QPixmap::fromImage(qImage));
}
