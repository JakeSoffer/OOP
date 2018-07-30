//
//  Date2_test.cpp
//  Date2
//
//  Created by Jake Soffer on 7/27/18.
//  Copyright © 2018 Jake Soffer. All rights reserved.
//

#include "std_lib_facilities.h"
#include "Date2.h"




int main(){
    Date userDate;
    while(true){
        try{
            cout << "Please enter a valid date in the format 'yyyy mm dd'. No characters just separated by spaces, for example: 2018 3 21 " << endl;
            cin >> userDate;
            break;
        }
        catch(...){
            cout << endl << "Invalid date" << endl << "Try again:" << endl << endl;
        }
    }
    
    
    cout << endl << "This is the date you entered: " << userDate << endl;
    
    cout << "Here's your date in longform: ";
    userDate.longForm();
    cout << endl;
    
    
    Date today{2020,Month::feb,28};
    Date otherDay{2023,Month::mar,14};
    Date sameOther{2023,Month::mar,14};
    
    cout << "Let's test add day by adding days to the date you created previosuly." << endl;
    cout << endl << "How many days would you like to add? Please enter a valid integer: ";
    int newdays;
    cin >> newdays;
    userDate.add_day(newdays);
    cout << endl;
    cout << "'New Date': " << userDate << endl;
    
    //here continue
    cout << endl << "Let's test add months by adding months to the date you created previosuly." << endl;
    cout << endl << "How many months would you like to add? Please enter a valid integer: ";
    int newmonths;
    cin >> newmonths;
    userDate.add_month(newmonths);
    cout << endl << "Here is your new date: " << endl;
    cout << userDate << endl;
    
    
    cout << endl << "Now, let's test adding years to your date. Please enter a valid integer of years to add: " << endl;
    int newyears;
    cin >> newyears;
    userDate.add_year(newyears);
    cout << "Here's your new date with the added years: " << userDate << endl;
    cout << endl;
    cout << "Here it is in long form: ";
    userDate.longForm();
    
    cout << endl;
    cout << "Lets test if 2/28/2020 is a leap year. We know it is:  " << endl;
    cout << "isLeapYear test (1 = true & 0 = false): " << isLeapYear(today.year()) << endl;
    
    cout << endl << "Lets test if 3/4/2023 is a leap year. We know it is NOT:  " << endl;
    Date noleap{2023,Month::mar,4};
    cout << "isLeapYear test (1 = true & 0 = false): " << isLeapYear(noleap.year()) << endl;
    
    cout << endl << "Lets test if your date is a leap year.:  " << endl;
    cout << "isLeapYear test (1 = true & 0 = false): " << isLeapYear(userDate.year()) << endl;
    
    cout << endl << "Lets test the date validity function: " << endl << endl;
    cout << "Let's test your date, which should be valid: " << endl;
    cout << "isvalid test (1 = true & 0 = false):" << isvalid(userDate) << endl << endl;
    
//    cout << endl << "Now, lets test if 15/1/2023 is a valid date. We know it IS NOT because 15 is not a valid month: " << endl;
//    Date novalid{2023,Month(15),1};
    
    cout << endl << endl << "Let's do an equality test for dates of March 14, 2023 & March 14, 2023" << endl;
    if(otherDay == sameOther){
        cout << "They are equal dates" << endl;
    }
    else{
        cout << "They are NOT equal dates" << endl;
    }
    cout << endl << "Let's do an equality test for dates of YOUR DATE & March 14, 2023" << endl;
    if(userDate == sameOther){
        cout << "They are equal dates" << endl;
    }
    else{
        cout << "They are not equal dates" << endl;
    }
    cout << endl << "Thank you for testing my program Vivek :) I Hope you enjoyed it!";
    return 0;
}
