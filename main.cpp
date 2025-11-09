#include "info_stick.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);	//Initialize QApplication app(argc, argv);
	Info_stick window;				//instantiate Info_stick window;
	window.show();					//show the window; its hidden without this command
	return app.exec();				//execute the application
}
