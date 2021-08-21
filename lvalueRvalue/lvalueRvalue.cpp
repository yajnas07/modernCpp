// lvalueRvalue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
using namespace std;

class myClass {
};

void func(myClass& obj) {
    cout << "Inside Lvalue ref function" << endl;
}

void func(const myClass& obj) {
    cout << "Inside const Lvalue ref function" << endl;
}

void func(myClass && obj) {
    cout << "Inside Rvalue ref function" << endl;
}

int main()
{
    myClass lv_obj;
    const myClass clv_obj;
    cout << "Calling with lv_obj" << endl;
    func(lv_obj);

    cout << "Calling with clv_obj" << endl;
    func(clv_obj);

    cout << "Calling with a temporary obj of myClass" << endl;
    func(myClass());

    cout << "Calling with a std::move of myClass" << endl;
    func(std::move(lv_obj));

}

