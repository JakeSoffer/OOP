//
//  mem_test.cpp
//  mem_test
//
//  Created by Jake Soffer on 8/1/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"

int main() {
    // mem_test
    int i =0;
    while(true){
        double *dptr = new double[10000];
        cout << "Loop " << i << endl;
        cout << "dptr[0] = " << dptr[0] << endl;
        i++;
    }
}
