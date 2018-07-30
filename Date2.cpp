//
//  main.cpp
//  Date2
//
//  Created by Jake Soffer on 7/27/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

#include "Date2.h"
#include <iostream>
using namespace std;
#include "std_lib_facilities.h"


vector<int> max_days = {0,31,28,31,30,31,30,31,30,31,30,31,30};
vector<int> leap_max_days = {0,31,29,31,30,31,30,31,30,31,30,31,30};


//    if(m>12){
//        throw "Month exceeds max of 12 months in a year";
//    }

Date::Date(int yy, Month mm, int dd) //constuctor
:y{yy}, m{mm}, d{dd}
{
    if(!isvalid(*this)){
        throw Invalid{};
    }
}

Date::Date():y(2018),m(Month(1)),d(1){}

ostream& operator << (ostream& os, const Date& d){
    return os << '(' <<d.year() << ',' << d.month() << ',' << d.day() << ')';
}

istream& operator >> (istream& is,  Date& userDate){
    int day;
    int mo;
    int year;
    is >> year >> mo >> day;
    userDate =  Date{year,Month(mo),day};
    return is;
}

void Date::add_year(int n){
    y += n;
}

void Date::add_month(int n){
    int x = int(m);
    x += n;
    int moreyears = x /12;
    if(x > 12){
        x = x % 12;
        add_year(moreyears);
    }
    if(x==0){
        x = 12;
    }
    m = Month(x);
}

void Date::add_day(int n)
{
    d +=n;
    while(d > max_days[int(m)]){
        d -= max_days[int(m)];
        add_month(1);
    }
    //    switch(m){
    //        case Month::jan: case Month::mar: case Month::may: case Month::jul: case Month::sep: case Month::nov:{
    //            if(d > 31){
    //                add_month(1);
    //                d = d % 31;
    //            }
    //            break;
    //        }
    //        case Month::apr: case Month::jun: case Month::aug: case Month::oct: case Month::dec:{
    //            if(d>30){
    //                add_month(1);
    //                d = d % 30;
    //            }
    //            break;
    //        }
    //        default:
    //            if(isLeapYear()){
    //                if(d>29){
    //                    add_month(1);
    //                    d = d % 29;
    //                }
    //            }
    //            else{
    //                if(d>28){
    //                    add_month(1);
    //                    d = d % 28;
    //            }
    //    }
    //    }
}

bool isLeapYear(int y){
    //check if leap year
    if((y%4)==0 && (y%100) != 0 || (y%400)==0){
        return true;
    }
    return false;
}

bool isvalid(const Date& curr){
    //check for valid month
    if(int(curr.month()) < 1 || int(curr.month()) > 12)
        return false;
    //check for valid day, not less than 1
    if(curr.day()<1)
        return false;
    //check for valid day for EACH month
    if(isLeapYear(curr.year())){
        if(curr.day() > leap_max_days[int(curr.month())]){
            return false;
        }
        else{
            if(curr.day() > max_days[int(curr.month())]){
                return false;
            }
        }
    }
    return true;
}

void Date::longForm(){
    //format date into long form, switch used to get full month name
    string mo;
    switch (m) {
        case Month::jan:{
            mo = "January";
        }
            break;
        case Month::feb:{
            mo = "February";
        }
            break;
        case Month::mar:{
            mo = "March";
        }
            break;
        case Month::apr:{
            mo = "April";
        }
            break;
        case Month::may:{
            mo = "May";
        }
            break;
        case Month::jun:{
            mo = "June";
        }
            break;
        case Month::jul:{
            mo = "July";
        }
            break;
        case Month::aug:{
            mo = "August";
        }
            break;
        case Month::sep:{
            mo = "September";
        }
            break;
        case Month::oct:{
            mo = "October";
        }
            break;
        case Month::nov:{
            mo = "November";
        }
            break;
        case Month::dec:{
            mo = "December";
        }
            break;
    }
    cout << mo << " " << d << ", " << y;
    cout << endl;
}

bool operator==(const Date& lval, const Date& rval){
    //equality override
    if (lval.year() != rval.year()|| lval.month() != rval.month() || lval.day() != rval.day()){
        return false;
    }
    return true;
}

bool operator!=(const Date& lval, const Date& rval){
    //inequality override
    if (lval.year() == rval.year()|| lval.month() == rval.month() || lval.day() == rval.day()){
        return false;
    }
    return true;
}
