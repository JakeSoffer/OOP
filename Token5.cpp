#include "std_lib_facilities.h"
#include "Token5.h"

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
