#include <QApplication>

#include "clock.h"

using namespace clk;

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	Clock clock = Clock();
	QWidget *clockptr = clock.digitalClock();
	clockptr->show();
	return app.exec();
}
