// stdForward.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class myClass {};

void main_function(myClass& lv) {
    cout << "Called lvalue reference function" << endl;
}

void main_function(const myClass& lv) {
    cout << "Called const reference function" << endl;
}

void main_function(myClass&& rv) {
    cout << "Called rvalue reference function" << endl;
}

template<typename T>
void forwarding_imperfect_function(T && obj) {
    main_function(obj);

}

template<typename T>
void forwarding_function(T && obj) {
    main_function(std::forward<T>(obj));

}

int main()
{
    myClass lvclass;
    const myClass clvclass;
    cout << "Directly calling main function, works well " << endl;
    main_function(lvclass);
    main_function(clvclass);
    main_function(std::move(lvclass));

    cout << "\nCalling forwarding function, non perfect version " << endl;
    forwarding_imperfect_function(lvclass);
    forwarding_imperfect_function(clvclass);
    forwarding_imperfect_function(std::move(lvclass));

    cout << "\nCalling forwarding function, perfect version " << endl;
    forwarding_function(lvclass);
    forwarding_function(clvclass);
    forwarding_function(std::move(lvclass));

}

