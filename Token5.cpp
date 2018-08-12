#include "std_lib_facilities.h"
#include "Token5.h"
#include <cmath>

// uncomment this for testing:
//int main()
//{
// vector<Token> tokens;
//    // frazzyswizel!
//    for(Token t = ts.get(); t.kind != 'q'; t = ts.get()) {
//        tokens.push_back(t);
//    }
//
//    for(Token tok : tokens) {
//        if(tok.kind == '8')
//            cout << "A number token with val = " << tok.value << '\n';
//        else if(tok.kind == 'i')
//            cout << "We received an invalid token of value "
//                << char(tok.value) << '\n';
//        else
//            cout << "A token of kind " << tok.kind << '\n';
//    }
//    return 0;
//}

std::ostream &operator<<(std::ostream &os, Token const &t) {
    return os << t.kind;
}

void Token_stream::putback(Token t){
    buffer.push_back(t);
}

Token Token_stream::popback()
{
    Token t = buffer.back();
    buffer.pop_back();
    return t;
}

Token Token_stream::get() {
    if(buffer.size() > 0) {
        Token t = popback();
        return t;
    }
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
        case '^':
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
        case '@':{
            //users the '@' symbol to enter quadratic mode
             float a, b, c, x1, x2, disc, realPart, imaginaryPart; //create the needed holder variables
            cout << endl << "HI! You have entered the quadrtic formula lab. I can find the roots of any quadratic formula. Please enter the variables (i.e: ax1^2 + bx2 + c)." << endl;
            cout << "Enter a, b and then c (the coefficients): ";
            cin >> a >> b >> c;
            disc = b*b - 4*a*c;
            //logic if dic. is > or < than 0
            if (disc > 0) {
                x1 = (-b + sqrt(disc)) / (2*a);
                x2 = (-b - sqrt(disc)) / (2*a);
                cout << " The Roots are real and they are different. " << endl;
                cout << "x1 = " << x1 << "and..." << endl;
                cout << "x2 = " << x2 << endl;
            }
            
            else if (disc == 0) {
                cout << " The roots are the same and they're real. " << endl;
                x1 = (-b + sqrt(disc)) / (2*a);
                cout << "x1 = x2 =" << x1 << endl;
            }
            
            else {
                realPart = -b/(2*a);
                imaginaryPart =sqrt(-disc)/(2*a);
                cout << "The roots are different, and they're also complex."  << endl;
                cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << " and... " << endl;
                cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
            }
            
            return Token{ch};

        }
        default:
            if(isalpha(ch)) {
//                cin.putback(ch);
                string s;
                s += ch;
                while(cin.get(ch) && isalpha(ch)) s += ch;
                cin.putback(ch);
                return Token{name, s};
            }
            return Token{invalid, double(ch)};
    }
    return Token{quit};
}

void Token_stream::ignore(char c)
// c is token kind to look for
{
    // first check buffer:
    while(buffer.size() > 0) {
        Token t = popback();
        if(t.kind == c) return;
    }
    
    // now search input:
    char ch = 0;
    while(cin>>ch)
        if(ch == c) return;
}
