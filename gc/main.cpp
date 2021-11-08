#include <QApplication>
#include "calendarWidget.h"

using namespace calendar;

int main(int argc, char *argv[])
{
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	QApplication app(argc, argv);
	calendarWidget c;
	c.show();
	return app.exec();
}
