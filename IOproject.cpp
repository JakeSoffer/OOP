//
//  main.cpp
//  IOproject
//
//  Created by Jake Soffer on 7/26/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"

struct Reading { // a temperature reading
    int hour; // hour after midnight [0:23]
    double temperature; // in Fahrenheit
    double pressure;
};

int main() {
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist {iname}; // ist reads from the file named iname
    if (!ist) error("can't open input file ",iname);

    string oname;
    cout << "Please enter name of output file: ";
    cin >> oname;
    ofstream ost {oname}; // ost writes to a file named oname
    if (!ost) error("can't open output file ",oname);

    char sep;

    vector<Reading> temps; // store the readings here
    int hour;
    double temperature;
    double pressure;
    while (ist >> hour >> sep >> temperature >> sep >> pressure) {
        temps.push_back(Reading{hour,temperature,pressure});
        //cout << "this is a while loop";
    }
    for (int i=0; i<temps.size(); ++i){
        ost << temps[i].hour << "\t" << temps[i].temperature <<  "\t" << temps[i].pressure << "\n";
    }
}

