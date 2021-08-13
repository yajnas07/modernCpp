#include<iostream>
using namespace std;

class A {
	int   a = 0;
	float b = 0.0;
public:
	A() {}
	A(int _a) :a(_a), b(0.0) { cout << "Base Constructor with value a:"<< a << endl; }
	A(int _a, float _b) :a(_a), b(_b) { cout << "Base Constructor with values a & b:(" << a << "," << b << ")" << endl; }
	virtual void print() {
		cout << "A=" << a << " B=" << b << " " ;
	}

};

class derivedTraditional :public A {
	string className{ "derivedTraditional" };
public:
	//Traditional way
    derivedTraditional(int _a) :A(_a) {}
	derivedTraditional(int _a, float _b) :A(_a, _b) {}
	virtual void print()  {
		A::print();
		cout << className << endl;
	}

	
};

class derivedInheritingConstructor :public A {
	string className{ "derivedInheritingConstructor" };
public:
	//New way, gets all the constructor from base class
	using A::A;
	//virtual void print() override {
	void print() final {
		A::print();
		cout << className << endl;
	}
	//The following two functions will not compile if uncommneted
	//void print(int a) override {
	//}
	//void printf() final {
	//}
	
};

int main()
{
	derivedTraditional d1(1000);
	derivedTraditional d2(10, 200.5);
	derivedInheritingConstructor d3(300);
	A *d4 = new derivedInheritingConstructor(20, 30.6f);
	d4->print();

}