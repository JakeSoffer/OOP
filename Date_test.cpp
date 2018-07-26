//
//  Date_test.cpp
//  Date
//
//  Created by Jake Soffer on 7/20/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//


#include "std_lib_facilities.h"
#include "Date.h"




int main(){
    Date today{2020,Month::feb,28};
    Date otherDay{2023,Month::mar,14};
    Date sameOther{2023,Month::mar,14};
    Date novalid{2023,Month(15),1};
    Date noleap{2023,Month::mar,4};
    cout << "'Today': " << today << endl << endl;
    cout << "test add day by adding 3 days to add day" << endl;
    today.add_day(3);
    cout << today << endl << endl;
    cout << "'Today': " << today << endl;
    cout << "test add day by adding 34 days to add day" << endl;
    today.add_day(34);
    cout << today << endl << endl;
    cout << "isLeapYear test (1 = true & 0 = false): " << today.isLeapYear() << endl;
    cout << "isLeapYear test (1 = true & 0 = false): " << noleap.isLeapYear() << endl;
    cout << endl << "Test add month: add 14 months to today" << endl;
    today.add_month(14);
    cout << today << endl << endl;
    cout << "isvalid test (1 = true & 0 = false):" << today.isvalid() << endl;
    cout << "isvalid test (1 = true & 0 = false):" << novalid.isvalid() << endl;
    cout << endl << "test long date form printing:" << endl;
    today.longForm();
    today.add_year(5);
    cout << today << endl;
    cout << endl;
    cout << "Equality test for otherDay & sameOther dates" << endl;
    if(otherDay == sameOther){
        cout << "They are equal dates" << endl;
    }
    else{
        cout << "They are not equal dates" << endl;
    }
    cout << endl << "Equality test for today & sameOther dates" << endl;
    if(today == sameOther){
        cout << "They are equal dates" << endl;
    }
    else{
        cout << "They are not equal dates" << endl;
    }
    cout << endl << "Test wrap around month by adding 364 days to today:" << endl;
    today.add_day(364);
    cout << today << endl;
    return 0;
}
