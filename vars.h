//
//  vars.hpp
//  Calc5
//
//  Created by Jake Soffer on 7/19/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

class Variable {
public:
    string name;
    double value;
};

double get_value(string s);
void set_value(string s, double d);
