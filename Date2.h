//
//  Date2.h
//  Date2
//
//  Created by Jake Soffer on 7/27/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

enum class Month{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

class Date{
public:
    class Invalid {};
    Date(int y, Month m, int d); //constructor
    Date();
    void add_day(int n); // increase day by n days
    void add_month(int n);//increase month by n months
    void add_year(int n);//increase year by n years
    int month() const{return int(m);}
    int year() const{return y;}
    int day() const{return d;}
    void longForm();
private:
    int y,d; //year and day
    Month m;
};

bool isvalid(const Date& curr);
bool isLeapYear(int y);

ostream& operator << (ostream& os, const Date& d);
istream& operator >> (istream& is, Date& userDate);
bool operator==(const Date& left, const Date& right);
