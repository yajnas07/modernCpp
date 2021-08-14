// lambda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//traditional functor
class is_prime {
public:
    void operator()(const int n) const {
        if (n == 2) { cout << n << " ";  return; }
        for (auto i = 3; i < n / 2; i++) {
            if ((n % i) == 0) return;
        }
        cout << n << " ";
    }
};



bool compare_string_ic(const string& lhs, const string& rhs)
{
    return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), 
        [](char l, char r) { return toupper(l) == toupper(r); });
}

int main()
{
    vector<int> inputs{ 2, 3,7,25,100,41,49 };
    cout << "Inputs values are:";
    for (auto i : inputs) { cout << i << " "; }
    //Find all the prime numbers in vector
    cout << "\nPrime values are:";
    for_each(inputs.begin(), inputs.end(), is_prime());

    
    cout << "\nEven values are:";
    for_each(inputs.begin(), inputs.end(), 
        [](const int n) { if (!(n & 0x1)) cout << n << " "; }
        );

    cout << "\nExample 2: Compare two string ignoring case" << endl;
    string lhs{"Hello"};
    string rhs{ "hello" };
    string eq_str = compare_string_ic(lhs,rhs)? "equal":"not-equal";
    cout << lhs << " and " << rhs << " are :" << eq_str << endl;
    cout << "hellow and hello are :" << (compare_string_ic("hellow","hello")?"equal":"not-equal") << endl;

}

