#include <QApplication>
#include <QTranslator>

#include "inc/windows/mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTranslator frenchTranslator;
	if (frenchTranslator.load("qt_fr", "D:/Programmes/Qt_4.4.1/5.9.2/mingw53_32/translations"))
	{
		a.installTranslator(&frenchTranslator);
	}

	MainWindow w;
	w.showMaximized();

	return a.exec();
}
