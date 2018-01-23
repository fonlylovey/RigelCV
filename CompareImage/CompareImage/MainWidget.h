#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWidget.h"

class MainWidget : public QMainWindow
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = Q_NULLPTR);

public slots:
	//�Ҷ�ͼ
	void slotGrayscale();

	//�����ݶ�
	void slotSobel();

	//����
	void slotDenoise();
private:
	Ui::MainWidget ui;
};
