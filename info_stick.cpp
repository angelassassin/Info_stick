#include "info_stick.h"
#include "ui_info_stick.h"

#include <QSysInfo>
#include <QStorageInfo>
#include <QThread>
#include <QTextStream>

#ifdef Q_OS_WIN
#include <windows.h>
#endif

Info_stick::Info_stick(QWidget *parent)
	: QMainWindow(parent)                   //Call the base class constructor with parent widget
    , ui(new Ui::Info_stickClass()) 
{
	//initialize the UI
	ui->setupUi(this);                      

	//app startup collect and display system info
	displaySystemInfo();					

	//connect refresh button signal to displaySystemInfo slot
	//calls displaySystemInfo() when refreshButton is clicked
	connect(ui->refreshButton, &QPushButton::clicked, this, &Info_stick::displaySystemInfo);
}	

Info_stick::~Info_stick()					//Destructor
{
    delete ui;
}

QString Info_stick::collectSystemInfo()		//Function definition to collect system information
{
	QString info;
	QTextStream stream(&info);

	//OS Information
	stream << "----------System Information----------\n";
	stream << "OS Type: " << QSysInfo::productType() << "\n";
	stream << "OS Version: " << QSysInfo::productVersion() << "\n";
	stream << "CPU Architecture: " << QSysInfo::currentCpuArchitecture() << "\n";

	//CPU Cores
	int cores = QThread::idealThreadCount();
	stream << "CPU Cores: " << cores << "\n";

#ifdef Q_OS_WIN
	//Total RAM on Windows
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	if(GlobalMemoryStatusEx(&memInfo)) {
		stream << "Total RAM: " << (memInfo.ullTotalPhys / (1024 * 1024)) << " MB\n";
		stream << "Available RAM: " << (memInfo.ullAvailPhys / (1024 * 1024)) << " MB\n";
	}
#endif
	//Storage Information
	stream << "\n----------Storage Information----------\n";
	QList<QStorageInfo> storages = QStorageInfo::mountedVolumes();
	for (const QStorageInfo &storage : storages) {
		stream << "Root Path: " << storage.rootPath() << "\n";
		stream << "File System Type: " << storage.fileSystemType() << "\n";
		stream << "Total Size: " << (storage.bytesTotal() / (1024 * 1024 * 1024)) << " GB\n";
		stream << "Available Size: " << (storage.bytesAvailable() / (1024 * 1024 * 1024)) << " GB\n\n";
	}
return info;
}

void Info_stick::displaySystemInfo()				//Function to display system information in the UI
{
	QString systemInfo = collectSystemInfo();
	ui->textEdit->setPlainText(systemInfo);			//Assuming there is a QTextEdit named textEdit in the UI
}
