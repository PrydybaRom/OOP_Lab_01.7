#include "Account.h"
#include <string>
#include <iostream>

int main()
{
	Account g;
	Money m;
	m.setB100(8);
	m.setB200(1);
	m.setB1(12);
	m.setC1(22);

	g.Init("Roman", 1, 22, m);

	cout << m.AllBalance() << endl;
	g.zniatuGroshi(100);
	g.Display();
	cout << g.toString();

	g.poklastyGroshi(500);
	cout << g.toString();

	g.procentGroshi(g.getProcent());
	cout << g.toString();

	g.toDollar();
	g.toEuro();

	cout << g.numberToWords() << endl;

	if (m < m) {
		cout << "m < m" << endl;
	}
	else {
		cout << "m is not < m" << endl;
	}

	return 0;
}
