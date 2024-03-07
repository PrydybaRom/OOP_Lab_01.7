#pragma once
#include <sstream> 
#include <string>
#include "Money.h"
using namespace std;


class Account
{
private:
	string name;
	int no = 0;
	double procent;
	Money balance;

public:
	string getName() const { return name; }
	int getNo() const { return no; }
	double getProcent() const { return procent; }
	Money getBalanse() const { return balance; }

	void setName(string name) { this->name = name; }
	void setNo(int no) { this->no = no; }
	void setProcent(double procent) { this->procent = procent; }
	void setMoney(Money balance) { this->balance = balance; }

	void Init(string name, int no, double procent, Money Balance);
	void Display() const;
	void Read();
	string toString() const;

	void changeName(string);
	void zniatuGroshi(double amount);
	void poklastyGroshi(double amount);
	void procentGroshi(double amount);
	void toDollar();
	void toEuro();
	string numberToWords();

};


