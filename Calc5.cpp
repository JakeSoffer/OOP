#include "std_lib_facilities.h"
#include "Token5.h"
#include "vars.h"
//#include "parser.h"

const char prompt = '>';
const string result = "= ";

double expression(Token_stream& ts);
double term(Token_stream& ts);
double expon(Token_stream& ts);
double primary(Token_stream& ts);


double statement(Token_stream& ts)
{
    /* grammar recognized:
     Statement:
     Var "=" Expression
     Var ";"
     Expression
     */
    Token t = ts.get();
    if(t.kind == name) {
        Token var = t;
        //        cout << "Got a var with name " << var.name << endl;
        t = ts.get();
        if(t.kind == '=') {  // an assignment
            double d = expression(ts);
            set_value(var.name, d);
            return d;
        }
        else if(t.kind == print) {
            ts.putback(t);
            return get_value(var.name);
        }
        ts.putback(t);
        ts.putback(var);
        return expression(ts);
    }
    ts.putback(t);
    return expression(ts);
}


double expression(Token_stream& ts){
    double left = term(ts);
    Token t = ts.get();
//    cout << "in expression " << endl;
//    cout << "we are in expression with token of " << t.kind << endl;
    while(true){
        switch(t.kind){
            case '+':
//                cout << "in case + " << endl;
                left += term(ts);
                t = ts.get();
                break;
            case '-':
                left -= term(ts);
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

double term(Token_stream& ts)
{
    /* grammar recognized:
     Term:
     Primary
     Term "*" Primary
     Term "/" Primary
     Term "%" Primary
     */
    double left = expon(ts);
    Token t = ts.get();        // get the next token from token stream
    
    while(true) {
        switch (t.kind) {
            case '*':
                left *= expon(ts);
                t = ts.get();
                break;
            case '/':
            {
                double d = expon(ts);
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            case '%':
            {
                double d = expon(ts);
                if (d == 0) error("divide by zero");
                left = fmod(left, d);
                t = ts.get();
                break;
            }
            case '2':
            {
                break;
            }
            case '@':
            {
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);     // put t back into the token stream
                return left;
        }
    }
    
}

double expon(Token_stream& ts)
{
    /* grammar recognized:
     Exp:
     Primary
     Primary "^" Primary
     */
    double left = primary(ts);
    Token t = ts.get();
    if(t.kind == power) {
        double d = primary(ts);
        return pow(left, d);
    }
    else {
        ts.putback(t);     // put t back into the token stream
        return left;
    }
}

double primary(Token_stream& ts)
{
    Token t = ts.get();
    switch (t.kind) {
        case '(':    // handle '(' expression ')'
        {
            double d = expression(ts);
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case number:
            return t.value;  // return the number's value
        case '-':
            return -primary(ts);
        case '+':
            return primary(ts);
        case name:
//            cout << "in this case!" << "with value " << get_value(t.name);
            return get_value(t.name);
        case '@':
            t.value = 0;
            return t.value;
        default:
            error("primary expected");
    }
    return 0.0;
}


void clean_up_mess(Token_stream& ts){
    ts.ignore(print);
}

void calculate(Token_stream& ts)
{
    while(cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            // this output is for debugging:
            //            cout << "in main(), got token: " << t.kind
            //                << " with val of " << t.value << '\n';
            while(t.kind == print) t = ts.get();
            if(t.kind == quit) return;
            ts.putback(t);
            cout << setprecision(8) << result << statement(ts) << '\n';
        }
        catch(exception& e) {
            cerr << e.what() << '\n';
            clean_up_mess(ts);
        }
    }
    
}

int main()
{
    Token_stream ts;
    
    try {
        calculate(ts);
        // keep_window_open();   // only if needed!
        return 0;
    }
    catch(...) {
        cerr << "unknown exception \n";
        return 2;
    }
}
