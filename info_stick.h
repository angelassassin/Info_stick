#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_info_stick.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Info_stickClass; };
QT_END_NAMESPACE


/*Custom class Info_stick inherits all the features of QMainWindow*/
class Info_stick : public QMainWindow
{
    Q_OBJECT

public:
	Info_stick(QWidget* parent = nullptr);  //Constructor
	~Info_stick();                          //Destructor

	void collectSystemInfo();				//Function to collect system information
	void collectStorageHealth();			//Function to collect storage health information
	void generateReport();					//HTML/PDF report generation function
private:
	Ui::Info_stickClass* ui;				//Pointer to the UI class
};

