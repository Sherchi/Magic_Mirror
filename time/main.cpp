#include <iostream>
#include <QByteArray>
#include <QList>
#include "clock.h"

using namespace clk;
using namespace std;

int main()
{
	Clock t = Clock();
	int *p;
	t.switchTimeZone("Asia/Shanghai");
	p = t.getTime();
	cout << "Current time is: ";
	for(int i = 0; i < 6; i++){
		cout << *(p + i) << endl;
	}
	return 0;
}
