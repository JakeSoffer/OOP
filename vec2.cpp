//
//  vec2.cpp
//  vec2
//
//  Created by Jake Soffer on 8/7/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

#include "std_lib_facilities.h"

//using namespace std;

class vect {
public:
    vect(int s) : sz{ s }, elem{ new double[s] } {}
    
    vect(const vect& arg)
    // allocate space, then initialize via copy
    :sz{ arg.sz }, elem{ new double[arg.sz] }
    {
        copy(arg.elem, arg.elem + arg.sz, elem);  // from std lib
    }
    
    ~vect() { delete[] elem; }
    
    double& operator[](int n) {
        return elem[n];
    }
    
    //no need for get and set with bracket overloading
//    double get(int i) { return elem[i]; }
//    void set(int i, double d) { elem[i] = d; }
    
   
private:
    int sz;
    double* elem;
};

//vect::vect(const vect& arg)
//// allocate space, then initialize via copy
//    :sz{ arg.sz }, elem{ new double[arg.sz] }
//{
//    copy(arg.elem, arg.elem + arg.sz, elem);  // from std lib
//}
//
//vect& vect::operator=(const vect& a) {
//    double* p = new double[a.sz];
//    copy(a.elem, a.elem + a.sz, p);
//    delete[] elem;
//    elem = p;
//    sz = a.sz;
//    return *this;
//}

void f(int n) {
    vect v(3);
    v[2] = 3.8;
    vect v2 = v;
    v[1] = 7.7;
    v2[0] = 4.4;
    cout << v[0] << ' ' << v2[1];
}

int main() {
    //while (true) f(10);
    int i;
    while (i < 10000) {
        f(10);
        i++;
    }
    keep_window_open();
}
