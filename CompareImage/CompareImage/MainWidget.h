#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWidget.h"

class MainWidget : public QMainWindow
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWidget ui;
};
