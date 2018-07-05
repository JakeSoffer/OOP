//
//  main.cpp
//  First input program
//
//  Created by Jake Soffer on 7/5/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"

int main() {
    // takes in a person's name and outputs a statement of hello to the person
    cout << "Please enter your name.";
    string firstName;
    cin >> firstName;
    cout << "Hello " << firstName;
    return 0;
}
