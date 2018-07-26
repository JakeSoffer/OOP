//
//  main.cpp
//  Date
//
//  Created by Jake Soffer on 7/20/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

#include "Date.h"
#include <iostream>
using namespace std;
#include "std_lib_facilities.h"



    

//    if(m>12){
//        throw "Month exceeds max of 12 months in a year";
//    }

Date::Date(int yy, Month mm, int dd) //constuctor
:y{yy}, m{mm}, d{dd}
{
    switch(m){
        case Month::jan: case Month::mar: case Month::may: case Month::jul: case Month::sep: case Month::nov:{
            if(d > 31){
                throw "Max days, 31, exceeded for the month";
            }
            break;
            
        }
        case Month::apr: case Month::jun: case Month::aug: case Month::oct: case Month::dec:{
            if(d>30){
                throw "Max days, 31, exceeded for the month";
            }
            break;
        }
        default:
            if (isLeapYear()){
                if(d>29){
                    throw "Max days, 29, exceeded for the month of february in a leap year";
                }
            }
            else{
                if(d>28){
                    throw "Max days, 29, exceeded for the month of february in a leap year";
                }
            }
    }
}

ostream& operator << (ostream& os, const Date& d){
    return os << '(' <<d.year() << ',' << d.month() << ',' << d.day() << ')';
}

void Date::add_year(int n){
    y += n;
}

void Date::add_month(int n){
    int x = int(m);
    x += n;
    if(x>12){
        x = x % 12;
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

bool Date::isLeapYear(){
    if((y%4)==0 && (y%100) != 0 || (y%400)==0){
        return true;
    }
    return false;
}

bool Date::isvalid(){
    if(int(m) < 1 || int(m) > 12)
        return false;
    return true;
}

void Date::longForm(){
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
    if (lval.year() != rval.year()|| lval.month() != rval.month() || lval.day() != rval.day()){
        return false;
    }
    return true;
}

bool operator!=(const Date& lval, const Date& rval){
    if (lval.year() == rval.year()|| lval.month() == rval.month() || lval.day() == rval.day()){
        return false;
    }
    return true;
}
