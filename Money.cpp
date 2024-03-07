#include "Money.h"
#include <iostream>
using namespace std;

Money::Money(int b500, int b200, int b100, int b50, int b20, int b10, int b5, int b2, int b1,
    int c50, int c25, int c10, int c5, int c2, int c1)
    : banknotes500(b500), banknotes200(b200), banknotes100(b100), banknotes50(b50),
    banknotes20(b20), banknotes10(b10), banknotes5(b5), banknotes2(b2), banknotes1(b1),
    coins50(c50), coins25(c25), coins10(c10), coins5(c5), coins2(c2), coins1(c1) {}

void Money::Init(int b500, int b200, int b100, int b50, int b20, int b10, int b5, int b2, int b1,
    int c50, int c25, int c10, int c5, int c2, int c1)
{
    setB500(b500);
    setB200(b200);
    setB100(b100);
    setB50(b50);
    setB20(b20);
    setB10(b10);
    setB5(b5);
    setB2(b2);
    setB1(b1);

    setC50(c50);
    setC20(c25);
    setC10(c10);
    setC5(c5);
    setC2(c2);
    setC1(c1);
}

double Money::AllBalance() const {
    int total_cents = banknotes500 * 50000 + banknotes200 * 20000 + banknotes100 * 10000 + banknotes50 * 5000 +
        banknotes20 * 2000 + banknotes10 * 1000 + banknotes5 * 500 + banknotes2 * 200 +
        banknotes1 * 100 + coins50 * 50 + coins25 * 25 + coins10 * 10 + coins5 * 5 + coins2 * 2 +
        coins1;

    double balance = static_cast<double>(total_cents) / 100.0;

    return balance;
}

void Money::Display() const {
    cout << "Balance: " << endl;
    cout << "500 - " << banknotes500 << endl;
    cout << "200 - " << banknotes200 << endl;
    cout << "100 - " << banknotes100 << endl;
    cout << "50 - " << banknotes50 << endl;
    cout << "20 - " << banknotes20 << endl;
    cout << "10 - " << banknotes10 << endl;
    cout << "5 - " << banknotes5 << endl;
    cout << "2 - " << banknotes2 << endl;
    cout << "1 - " << banknotes1 << endl;
    cout << "Cents 50 - " << coins50 << endl;
    cout << "Cents 25 - " << coins25 << endl;
    cout << "Cents 10 - " << coins10 << endl;
    cout << "Cents 5 - " << coins5 << endl;
    cout << "Cents 2 - " << coins2 << endl;
    cout << "Cents 1 - " << coins1 << endl;
}

string Money::toString() const
{
    stringstream sout;
    sout << "Money - " << Money::AllBalance();
    return sout.str();
}


void Money::Read() {
    int b500, b200, b100, b50, b20, b10, b5, b2, b1,
        c50, c25, c10, c5, c2, c1;
    
    cout << "500 = "; cin >> b500;
    cout << "200 = "; cin >> b200;
    cout << "100 = "; cin >> b100;
    cout << "50 = "; cin >> b50;
    cout << "20 = "; cin >> b20;
    cout << "10 = "; cin >> b10;
    cout << "5 = "; cin >> b5;
    cout << "2 = "; cin >> b2;
    cout << "1 = "; cin >> b1;

    cout << "cent 50 = "; cin >> c50;
    cout << "cent 25 = "; cin >> c25;
    cout << "cent 10 = "; cin >> c10;
    cout << "cent 5 = "; cin >> c5;
    cout << "cent 2 = "; cin >> c2;
    cout << "cent 1 = "; cin >> c1;

    Init(b500, b200, b100, b50, b20, b10, b5, b2, b1,
         c50, c25, c10, c5, c2, c1);
}

bool Money::vidniatyGroshi(double amount) {
    int total_cents = banknotes500 * 50000 + banknotes200 * 20000 + banknotes100 * 10000 + banknotes50 * 5000 +
        banknotes20 * 2000 + banknotes10 * 1000 + banknotes5 * 500 + banknotes2 * 200 +
        banknotes1 * 100 + coins50 * 50 + coins25 * 25 + coins10 * 10 + coins5 * 5 + coins2 * 2 +
        coins1;

    int amount_in_cents = static_cast<int>(amount * 100);

    if (total_cents < amount_in_cents) {
        cout << "Insufficient funds." << endl;
        return false;
    }

    int b500 = amount_in_cents / 50000;
    amount_in_cents %= 50000;
    int b200 = amount_in_cents / 20000;
    amount_in_cents %= 20000;
    int b100 = amount_in_cents / 10000;
    amount_in_cents %= 10000;
    int b50 = amount_in_cents / 5000;
    amount_in_cents %= 5000;
    int b20 = amount_in_cents / 2000;
    amount_in_cents %= 2000;
    int b10 = amount_in_cents / 1000;
    amount_in_cents %= 1000;
    int b5 = amount_in_cents / 500;
    amount_in_cents %= 500;
    int b2 = amount_in_cents / 200;
    amount_in_cents %= 200;
    int b1 = amount_in_cents / 100;
    amount_in_cents %= 100;

    int c50 = amount_in_cents / 50;
    amount_in_cents %= 50;
    int c25 = amount_in_cents / 25;
    amount_in_cents %= 25;
    int c10 = amount_in_cents / 10;
    amount_in_cents %= 10;
    int c5 = amount_in_cents / 5;
    amount_in_cents %= 5;
    int c2 = amount_in_cents / 2;
    amount_in_cents %= 2;
    int c1 = amount_in_cents;

    banknotes500 -= b500;
    banknotes200 -= b200;
    banknotes100 -= b100;
    banknotes50 -= b50;
    banknotes20 -= b20;
    banknotes10 -= b10;
    banknotes5 -= b5;
    banknotes2 -= b2;
    banknotes1 -= b1;

    coins50 -= c50;
    coins25 -= c25;
    coins10 -= c10;
    coins5 -= c5;
    coins2 -= c2;
    coins1 -= c1;

    cout << "Withdrawal successful." << endl;
    return true;
}


void Money::dodatyGroshi(double amount) {
    int amount_in_cents = static_cast<int>(amount * 100);

    int b500 = amount_in_cents / 50000;
    amount_in_cents %= 50000;
    int b200 = amount_in_cents / 20000;
    amount_in_cents %= 20000;
    int b100 = amount_in_cents / 10000;
    amount_in_cents %= 10000;
    int b50 = amount_in_cents / 5000;
    amount_in_cents %= 5000;
    int b20 = amount_in_cents / 2000;
    amount_in_cents %= 2000;
    int b10 = amount_in_cents / 1000;
    amount_in_cents %= 1000;
    int b5 = amount_in_cents / 500;
    amount_in_cents %= 500;
    int b2 = amount_in_cents / 200;
    amount_in_cents %= 200;
    int b1 = amount_in_cents / 100;
    amount_in_cents %= 100;

    int c50 = amount_in_cents / 50;
    amount_in_cents %= 50;
    int c25 = amount_in_cents / 25;
    amount_in_cents %= 25;
    int c10 = amount_in_cents / 10;
    amount_in_cents %= 10;
    int c5 = amount_in_cents / 5;
    amount_in_cents %= 5;
    int c2 = amount_in_cents / 2;
    amount_in_cents %= 2;
    int c1 = amount_in_cents;

    banknotes500 += b500;
    banknotes200 += b200;
    banknotes100 += b100;
    banknotes50 += b50;
    banknotes20 += b20;
    banknotes10 += b10;
    banknotes5 += b5;
    banknotes2 += b2;
    banknotes1 += b1;

    coins50 += c50;
    coins25 += c25;
    coins10 += c10;
    coins5 += c5;
    coins2 += c2;
    coins1 += c1;

    cout << " successful." << endl;
}


void Money::mnogGroshi(double rate) {
    double interest = AllBalance() * (rate / 100); 
    dodatyGroshi(interest);
    cout << "Interest accrued: " << interest << endl;
}

void Money::dileniaD()
{
    double dollars = AllBalance() / 38.98;
    cout << " Money in Dollar: " << dollars << endl;
}
void Money::dileniaE()
{
    double euros = AllBalance() / 41.22;
    cout << " Money in Euro: " << euros << endl;
}

bool Money::operator==(const Money& other) const {
    return (banknotes500 == other.banknotes500 &&
        banknotes200 == other.banknotes200 &&
        banknotes100 == other.banknotes100 &&
        coins50 == other.coins50 &&
        coins25 == other.coins25 &&
        coins10 == other.coins10);
}

bool Money::operator!=(const Money& other) const {
    return !(*this == other);
}

bool Money::operator<(const Money& other) const {
    int total1 = banknotes500 * 500 + banknotes200 * 200 + banknotes100 * 100 +
        coins50 * 50 + coins25 * 25 + coins10 * 10;
    int total2 = other.banknotes500 * 500 + other.banknotes200 * 200 + other.banknotes100 * 100 +
        other.coins50 * 50 + other.coins25 * 25 + other.coins10 * 10;
    return total1 < total2;
}

bool Money::operator<=(const Money& other) const {
    return (*this < other || *this == other);
}

bool Money::operator>(const Money& other) const {
    return !(*this <= other);
}

bool Money::operator>=(const Money& other) const {
    return !(*this < other);
}
