//
//  main.cpp
//  Token
//
//  Created by Jake Soffer on 7/12/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"

//Token class
class Token{
public:
    char kind;
    double val;
};

int main() {
    // Tokenizer
    
    Token get_token();
    vector<Token> tokens;
    Token t = get_token();
    
    
    
    for(Token t = get_token(); t.kind != 'q'; t = get_token()){
       tokens.push_back(t);
    }
        
        
//    while (t.kind != 'q') {
//        tokens.push_back(t);
//        t = get_token();
//    }
    for (Token tok: tokens) {
        cout<< "Token" << tok.kind << "with val" << tok.val << endl;
    }
}

Token get_token(){
    char ch;
    cin >> ch;
    switch (ch) {
        case ';':
        case 'q':
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
            return Token{ch};
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':{
            cin.putback(ch);
            double val;
            cin>>val;
            return Token{'8',val};
        }
    }
    keep_window_open();
    return Token{'q'};
}

