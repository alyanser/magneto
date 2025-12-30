#include "main_window.h"

#include <QApplication>
#include <QFile>

int main(int argc, char ** argv) {
	QApplication Magneto(argc, argv);

	QApplication::setOrganizationName("fyp-minhaal-faheem");
	QApplication::setApplicationName("Magneto");
	QApplication::setWindowIcon(QIcon(":app_icon.png"));

	if(QFile stylesheet(":stylesheet.qss"); stylesheet.open(QFile::ReadOnly)) {
		Magneto.setStyleSheet(stylesheet.readAll());
	}

	Main_window main_window;
	QObject::connect(&main_window, &Main_window::closed, &Magneto, &QApplication::quit);

	return QApplication::exec();
}