// stdFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional> //Needed for std::function
using namespace std;
using namespace std::placeholders; //Need for _1 , _2 etc

//Function variant
bool match_substring_generic(const string& str, const string& sub) {
    if (str.find(sub) != string::npos) return true;
    return false;
}




//Functor variant
class exact_string_matcher {
    string to_match_with = "";
    public:
        exact_string_matcher(string & st):to_match_with(st){}
        bool operator()(const string& str) {
            return (to_match_with == str);
        }
};

int counter(std::vector<string>& v, std::function< bool(const string& match_element) > predicate) {
	auto count = 0;
	for (auto element : v) {
		if (predicate(element)) count++;
	}
	return count;

}

int main()
{
	vector<string> input{"one", "two", "onetwo", "twoonetoone", "three", "onethree", "four"};
    cout << "Inputs Array is:";
    for (auto s : input) { cout << s << " "; }
        

    string subs = "";
    cout << "\nEnter the substring(ctrl+d or 'done' to exit):";
    while ((cin >> subs) && (subs!="done")) {
        
        auto match_custom = std::bind(match_substring_generic, _1, subs);

        cout << "Number of string with substrigs " << subs << 
            " = " << counter(input, match_custom) << endl;

        exact_string_matcher matcher(subs);
        auto count = counter(input,matcher);
        cout <<"Number of string exactly match with " << subs << " = " << count << endl;

        //Lambda equivalent, find string with same size
        auto string_withsame_size = counter(input,
            [value = subs](const string& str) { return str.size() == value.size(); }
            );
        cout <<"Number of string having same length as " << subs << " = " << string_withsame_size << endl;

        cout << "\nEnter the substring(ctrl+d or 'done' to exit):";
    }

}

