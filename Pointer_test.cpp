//
//  main.cpp
//  Pointer
//
//  Created by Jake Soffer on 7/31/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"

int main() {
    char c = 'a';
    int i = 4092;
    double d = 3.14;
    char* cp = &c;
    int* ip = &i;
    double* dp = &d;
    cout << "cp = " << cp << " and its value is " << *cp << endl;
    cout << "ip = " << ip << " and its value is " << *ip << endl;
    cout << "dp = " << dp << " and its value is " << *dp << endl;
    cout << " Size of cp is " << sizeof(cp) << endl;
    cout << " Size of ip is " << sizeof(ip) << endl;
    cout << " Size of dp is " << sizeof(dp) << endl;
    cout << " Size of c is " << sizeof(c) << endl;
    cout << " Size of i is " << sizeof(i) << endl;
    cout << " Size of d is " << sizeof(d) << endl;
    return 0;
}
