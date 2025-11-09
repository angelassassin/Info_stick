#include "info_stick.h"

Info_stick::Info_stick(QWidget *parent)
	: QMainWindow(parent)                   //Call the parent class constructor
    , ui(new Ui::Info_stickClass()) 
{
	ui->setupUi(this);                      //initialize the UI
	collectSystemInfo();					//placeholder to collect system information
}

Info_stick::~Info_stick()					//Destructor
{
    delete ui;
}

void Info_stick::collectSystemInfo()		//Function to collect system information
{
	//Placeholder function
	qDebug() << "CPU: Intel i7";
	qDebug() << "RAM: 16GB";
	qDebug() << "OS: Windows 10";
}

void Info_stick::collectStorageHealth()		//Function to collect storage health information
{
	//Placeholder function
	qDebug() << "SSD Health: 95%";
}

void Info_stick::generateReport()			//HTML/PDF report generation function
{
	//Placeholder function
	qDebug() << "Report save to USB drive.";
}