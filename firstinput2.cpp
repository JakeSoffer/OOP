//
//  main.cpp
//  firstinput2
//
//  Created by Jake Soffer on 7/5/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"

int main() {
    // takes in a person's name & age and outputs a statement of hello to the person
    cout << "Please enter your name.";
    string firstName;
    int age;
    cin >> firstName;
    cout << "Please enter your age";
    cin >> age;
    cout << "Hello " << firstName << ". Your age is " << age;
    return 0;
}
