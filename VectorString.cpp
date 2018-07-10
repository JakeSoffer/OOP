//
//  VectorString.cpp
//  VectorString
//
//  Created by Jake Soffer on 7/10/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"

int main() {
    // vector of strings sorted: steps: 1) sort & print, 2) eliminate duplicates, 3) count duplicates
    vector<string> text;
    for(string word; cin>>word;)
        text.push_back(word);
    sort(text);
    
    //print out words
//    for(int i = 0; i<text.size(); i++)
//        cout << text[i] << "\n";
    
//    cout << endl << "break" << endl;
    //
    string previous = text[0];
    int wordCount = 0;
    for(int i = 0; i<text.size(); i++){
        if(text[i] == previous){
            wordCount+=1;
        }
        else{
            cout << previous << " is stated " << wordCount << " times." <<endl;
            wordCount = 1;
            previous = text[i];
        }
    }
    keep_window_open();
    return 0;
}
