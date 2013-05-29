#include "workouttimer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WorkoutTimer w;
	w.show();

	QCoreApplication::setOrganizationName("TheLetterEph");
	QCoreApplication::setOrganizationDomain("thelettereph.com");
	QCoreApplication::setApplicationName("Workout Timer");
	return a.exec();
}
