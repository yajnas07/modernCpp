// genericLambda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Compiler generates something like below 
// for adder_lambda 
class adder_functor {
public:
    template<typename T>
    T operator()(T lhs, T rhs) { return lhs + rhs; }
    //int operator()(int lhs, int rhs) { return lhs + rhs; }
};


// Compiler generates something like below 
// for addZsquare_lambda
template<typename T>
class addZsquare_functor {
    T y;
public:
    addZsquare_functor(T Z):y(Z*Z){}
    T operator()(T input) { return input + y; }

};

int main()
{
    auto adder_lambda = [](auto v1, auto v2) { return v1 + v2; };
    cout << "4 + 5 = " << adder_lambda(4,5) << endl;
    cout << "11.5 + 10.7 = " << adder_lambda(11.5,10.7) << endl;
    string s1 = "Hello";
    string s2 = "Worlds";
    std::cout << adder_lambda(s1,s2) << endl;


    //cout << adder_functor()(1,1);
    cout << "1.5 + 1.6 = " << adder_functor()(1.5,1.6) << endl;

    vector<int> Zs{ 1,2,4,8,16 };
    for (auto z : Zs) {
        //Intialize a local lambda variable from a captured value z
        auto addZsquare_lambda = [y = z * z](auto input) { return input + y; };
        cout << "100 + "<< z <<" square = " << addZsquare_lambda(100) << endl;

        //The below commnetd code produces same result, this is what compiler does
        //addZsquare_functor<int> func(z);
        //cout << "100 + "<< z <<" square = " << func(100) << endl;
    }
}

