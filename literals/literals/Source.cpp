#include<iostream>
#include<cstdint>
#include<algorithm>

using namespace std;
using namespace std::literals;

class celsius {
	long double temperature;
public:
	explicit celsius(long double t) :temperature(t) {}
	void print() { cout << temperature << " Degree Celsius" << endl; }
};


celsius operator ""_C(long double t) {
	return celsius(t);
}

celsius operator ""_F(long double f) {
	return celsius(5.0/9.0 *(f-32));
}

//String literal
string operator ""_rev(const char* s, size_t sz) {
	string rev_str(s,sz);
	reverse(rev_str.begin(), rev_str.end());
	return rev_str;
}

//Raw literal
class bigint {
	string raw_str;
public: 
	bigint(const char* s) :raw_str(s) {}

	void print()	{
		cout << "Big int value is: " << raw_str << endl;
	};

};

bigint operator ""_big(const char* c)
{
	return bigint(c);
}

int main(int argc, char * argv[])
{

	string url = R"(https://google.com)";
	//string url = R"d(https://(google.com))d";
	cout << url << endl;
	
	
	int one_million = 1'000'000;
	int one_crore = 1'00'00'000;
	int sixteen = 0b10000;
	
	cout << "OneMillion="<< one_million << " OneCrore=" << one_crore << endl;
	cout << "Sixteen=" <<sixteen << endl;

	cout << "First letter in this Sentence is:" << *("First"s.begin()) << endl;

	celsius boiling_pt = 212.0_F;
	celsius freezing_pt = 0.0_C;


	cout << "\nBoiling point of water is ";
	boiling_pt.print();
	cout << "Freezing point of water is ";
	freezing_pt.print();

	//The following will not compile with explicit in place, so better type safety
	//celsius invalid_pt = 0.0;

	cout << R"(Reverse of "Sanjay" is:)" << "Sanjay"_rev << endl;
	
	
	bigint b = 1234567891011121314151617181920_big;
	b.print();

	return 0;

}
