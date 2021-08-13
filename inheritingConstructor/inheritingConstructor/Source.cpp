#include<iostream>
using namespace std;

class A {
	int   a = 0;
	float b = 0.0;
public:
	A() {}
	A(int _a) :a(_a), b(0.0) { cout << "Base Constructor with value a:"<< a << endl; }
	A(int _a, float _b) :a(_a), b(_b) { cout << "Base Constructor with values a & b:(" << a << "," << b << ")" << endl; }

};

class derivedTraditional :public A {
public:
	//Traditional way
    derivedTraditional(int _a) :A(_a) {}
	derivedTraditional(int _a, float _b) :A(_a, _b) {}
	
};

class derivedInheritingConstructor :public A {
public:
	//Traditional way
	using A::A;
	
};

int main()
{
	derivedTraditional d1(1000);
	derivedTraditional d2(10, 200.5);
	derivedInheritingConstructor d3(300);
	derivedInheritingConstructor d4(20, 30.6f);

}