#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWidget.h"

class MainWidget : public QMainWindow
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = Q_NULLPTR);

public slots:
	//ª“∂»Õº
	void slotGrayscale();

	//º∆À„Ã›∂»
	void slotSobel();

	//Ωµ‘Î
	void slotDenoise();
private:
	Ui::MainWidget ui;
};
