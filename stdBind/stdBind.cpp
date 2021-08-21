// stdBind.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<functional> //Needed for bind
using namespace std;
using namespace std::placeholders; //Need for _1 , _2 etc

//Main predicate function
bool match_substring(const string& str) {
    if (str.find("one") != string::npos) return true;
    return false;
}
bool match_substring_generic(const string& str, const string& sub = "one") {
    if (str.find(sub) != string::npos) return true;
    return false;
}


int main()
{
    std::cout << "Hello World!\n";

    //Problem find all the string in a given vector of string which contains a substring
    vector<string> input{"one", "two", "onetwo", "onetwothree", "three", "twoone"};
    cout << "Inputs Array is:";
    for (auto s : input) { cout << s << " "; }
        
    cout << "\nNumber of string with substrigs " << "one" << 
            " = " << std::count_if(input.begin(), input.end(), match_substring) << endl;

    string subs = "";
    cout << "\nEnter the substring(ctrl+d or 'done' to exit):";
    while ((cin >> subs) && (subs!="done")) {
        //cannot use match_substring_generic as predicate can take only one parameter    
        
        //Hence create a new function with bind
        auto match_custom = std::bind(match_substring_generic, _1, subs);

        cout << "Number of string with substrigs " << subs << 
            " = " << std::count_if(input.begin(), input.end(), match_custom);
        cout << "\nEnter the substring(ctrl+d or 'done' to exit):";
    }

}

