#pragma once
#include <string>
#include <sstream> 
using namespace std;

class Money {
private:
    int banknotes500;
    int banknotes200;
    int banknotes100;
    int banknotes50;
    int banknotes20;
    int banknotes10;
    int banknotes5;
    int banknotes2;
    int banknotes1;
    int coins50;
    int coins25;
    int coins10;
    int coins5;
    int coins2;
    int coins1;

public:
    Money(int b500 = 0, int b200 = 0, int b100 = 0, int b50 = 0, int b20 = 0, int b10 = 0, int b5 = 0, int b2 = 0, int b1 = 0,
        int c50 = 0, int c25 = 0, int c10 = 0, int c5 = 0, int c2 = 0, int c1 = 0);

    void Init(int b500, int b200, int b100, int b50, int b20, int b10, int b5, int b2, int b1,
        int c50, int c25, int c10, int c5, int c2, int c1);

    void setB500(int banknotes500) { this->banknotes500 = banknotes500; }
    void setB200(int banknotes200) { this->banknotes200 = banknotes200; }
    void setB100(int banknotes100) { this->banknotes100 = banknotes100; }
    void setB50(int banknotes50) { this->banknotes50 = banknotes50; }
    void setB20(int banknotes20) { this->banknotes20 = banknotes20; }
    void setB10(int banknotes10) { this->banknotes10 = banknotes10; }
    void setB5(int banknotes5) { this->banknotes5 = banknotes5; }
    void setB2(int banknotes2) { this->banknotes2 = banknotes2; }
    void setB1(int banknotes1) { this->banknotes1 = banknotes1; }

    void setC50(int coins50) { this->coins50 = coins50; }
    void setC20(int coins25) { this->coins25 = coins25; }
    void setC10(int coins10) { this->coins10 = coins10; }
    void setC5(int coins5) { this->coins5 = coins5; }
    void setC2(int coins2) { this->coins2 = coins2; }
    void setC1(int coins1) { this->coins1 = coins1; }


    int getB500() const { return banknotes500; }
    int getB200() const { return banknotes200; }
    int getB100() const { return banknotes100; }
    int getB50() const { return banknotes50; }
    int getB20() const { return banknotes20; }
    int getB10() const { return banknotes10; }
    int getB5() const { return banknotes5; }
    int getB2() const { return banknotes2; }
    int getB1() const { return banknotes1; }

    int getC50() const { return coins50; }
    int getC20() const { return coins25; }
    int getC10() const { return coins10; }
    int getC5() const { return coins5; }
    int getC2() const { return coins2; }
    int getC1() const { return coins1; }

    void Display() const;
    void Read();
    string toString() const;
    double AllBalance() const;

    bool vidniatyGroshi(double amount);
    void dodatyGroshi(double amount);
    void mnogGroshi(double rate);

    void dileniaD();
    void dileniaE();

    bool operator==(const Money& other) const;
    bool operator!=(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator<=(const Money& other) const;
    bool operator>(const Money& other) const;
    bool operator>=(const Money& other) const;

};