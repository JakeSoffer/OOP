//
//  main.cpp
//  Token
//
//  Created by Jake Soffer on 7/12/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"

const char invalid = 'i';
const char name = 'a';
const char number = '8';
const char quit = 'q';
const char print = ';';

class Token {
public:
    char kind;
    double value;
    string name;
    Token(char ch) :kind{ch} {}
    Token(char ch, double val) :kind{ch}, value{val} {}
    Token(char ch, string n) :kind{ch}, name{n} {}
};


std::ostream &operator<<(std::ostream &os, Token const &t) {
    return os << t.kind;
}

int main(){
    
        Token get_token();
        vector<Token> tokens;
//        Token t = get_token();
    
    for(Token t = get_token(); t.kind != 'q'; t = get_token()) {
        tokens.push_back(t);
        
    }

    for(Token tok : tokens) {
        if(tok.kind == '8')
            cout << "A number token with val = " << tok.value << '\n';
        else if(tok.kind == 'i')
            cout << "We received an invalid token of value "
                << char(tok.value) << '\n';
        else
            cout << "A token of kind " << tok.kind << '\n';
    }
    return 0;
}

//std::ostream &operator<<(std::ostream &os, Token const &t) {
//    return os << t.kind;
//}

//int main() {
//    // Tokenizer
//
//    Token get_token();
//    vector<Token> tokens;
////    Token t = get_token();
//
//
//        for(Token t = get_token(); t.kind != quit; t = get_token()) {
//            tokens.push_back(t);
//        }
//
//        for(Token tok : tokens) {
//            if(tok.kind == number)
//                cout << "A number token with val = " << tok.val << '\n';
//            else if(tok.kind == 'i')
//                cout << "We received an invalid token of value "
//                    << char(tok.val) << '\n';
//            else
//                cout << "A token of kind " << tok.kind << '\n';
//        }
//        return 0;
//
//
//    //    while (t.kind != 'q') {
//    //        tokens.push_back(t);
//    //        t = get_token();
//    //    }
//}




Token get_token(){
    char ch;
    cin >> ch;
    switch(ch) {
        case print:
        case quit:
        case '(':
        case ')':
        case '+':
        case '-':
        case '/':
        case '*':
        case '%':
        case '=':
            return Token{ch};
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);
            double val;
            cin >> val;
            return Token{number, val};
        }
        default:
//            if(isalpha(ch)) {
//                cin.putback(ch);
//                string s;
//                s += ch;
//                while(cin.get(ch) && isalpha(ch)) s += ch;
//                cin.putback(ch);
//                return Token{name, s};
//            }
            return Token{invalid, double(ch)};
    }
    
    return Token{quit};
    keep_window_open();
}

