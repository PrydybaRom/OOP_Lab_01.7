
#include "Account.h"
#include <string>
#include <iostream>

using namespace std;

void Account::Init(string name, int no, double procent, Money balance) {
    setName(name);
    setNo(no);
    setProcent(procent);
    setMoney(balance);
}

void Account::changeName(string name)
{
    setName(name);
}

void Account::Display() const {
    cout << " Account: " << endl << " Name - " << name << endl << " Namber - " << no << endl << " Procent - " << procent << endl;
    balance.Display();
}

void Account::Read() {
    string name;
    int no;
    double proc;
    Money m;
    cout << " Account: " << endl;
    cout << " Enter name: "; cin >> name;
    cout << " Enter namber: "; cin >> no;
    cout << " Enter procent: "; cin >> proc;
    cout << " Money - ? " << endl;
    m.Read();
    Init(name, no, proc, m);
}

string Account::toString() const
{
    stringstream sout;
    sout << " Account Name - " << name << " Namber - " << no << " Procent - " << procent << " " << balance.toString() << endl;
    return sout.str();
}


void Account::zniatuGroshi(double amount) {
    if (balance.AllBalance() < amount) {
        cout << " You don`t have enough money. " << endl;
        return;
    }

    if (balance.vidniatyGroshi(amount)) {
        cout << "Withdrawal of " << amount << " successful." << endl;
    }
    else {
        cout << " failed." << endl;
    }
}


void Account::poklastyGroshi(double amount)
{
    balance.dodatyGroshi(amount);
};

void Account::procentGroshi(double amount) 
{
    balance.mnogGroshi(procent);
}


void Account::toDollar() {
    balance.dileniaD();
}
void Account::toEuro() {
    balance.dileniaE();
}

string Account::numberToWords() {
    

    int grivnas = static_cast<int>(balance.AllBalance());
    int kopecks = static_cast<int>((balance.AllBalance() - grivnas) * 100);

    
    const string units[] = { "", "odin", "dva", "tri", "chotiri", "piat", "shist", "sim", "visim", "deviat" };
    const string teens[] = { "desiat", "odinatsiat", "dvanatsiat", "trinadsiat", "chitirnatsiat", "piatnadsia", "sichnadsiat", "simnadsiat", "visimnadsiat", "devaitnadsiat" };
    const string tens[] = { "", "", "dvadsiat", "tridsat", "sorok", "piatdesat", "shistdesat", "simdesat", "visimdesat", "devainosto" };
    const string hundreds[] = { "", "sto", "dvista", "trista", "chotirista", "piatsot", "shisot", "simsot", "visimsot", "deviatsot" };
    const string thousands[] = { "", "tisacha", "tisachi", "tisach" };
    const string millions[] = { "", "milion", "miliona", "milioniv" };

    // Число в словах
    string result;

    // Гривні
    int unit = grivnas % 10;
    int ten = (grivnas % 100) / 10;
    int hundred = (grivnas % 1000) / 100;
    int thousand = (grivnas % 10000) / 1000;
    int million = grivnas / 1000000;

    if (million > 0) {
        result += hundreds[million] + " ";
        result += millions[million] + " ";
    }
    if (thousand > 0) {
        result += thousands[thousand] + " ";
    }
    if (hundred > 0) {
        result += hundreds[hundred] + " ";
    }
    if (ten > 1) {
        result += tens[ten] + " ";
        result += units[unit] + " ";
    }
    else if (ten == 1) {
        result += teens[unit] + " ";
    }
    else {
        result += units[unit] + " ";
    }

    if (kopecks > 0) {
        result += "griven' ";
        if (kopecks < 10) {
            result += units[kopecks];
        }
        else if (kopecks < 20) {
            result += teens[kopecks - 10];
        }
        else {
            int kopecks_tens = kopecks / 10;
            int kopecks_units = kopecks % 10;
            result += tens[kopecks_tens] + " ";
            result += units[kopecks_units];
        }
        result += " kopeeks";
    }
    else {
        result += "griven'";
    }

    return result;
}
