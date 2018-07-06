//
//  main.cpp
//  Repeatedwords2
//
//  Created by Jake Soffer on 7/6/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"

int main() {
    //detects repeated words
    int number_of_words = 0;
    string previous = " ";
    string current;
    while (cin >> current){
        ++number_of_words;
        if (previous == current)
            cout << "word number " << number_of_words << " repeated: " << current;
        previous = current;
    }
}

