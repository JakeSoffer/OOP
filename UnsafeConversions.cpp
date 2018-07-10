//
//  main.cpp
//  HW1_UnsafeConversions
//
//  Created by Jake Soffer on 7/6/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"

int main() {
    // unsafe conversions from int
    int a = 30000000;
    cout << a << endl;
    char c = a;
    bool d = a;
    cout << c << endl;
    cout << d << endl;
    int e = c;
    int f = d;
    cout << e << endl;
    cout << f << endl;
    //unsafe conversions from double
    double db = 31048.4;
    cout << db << endl;
    int x = db;
    char y = db;
    bool z = db;
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    double bc = x;
    double ef = y;
    double fg = z;
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    //unsafe conversions from char
    char l = 'a';
    cout << l << endl;
    bool m = l;
    cout << m << endl;
    char p = m;
    cout << p << endl;
    return 0;
}
