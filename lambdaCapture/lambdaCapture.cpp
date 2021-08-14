// lambdaCapture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//This is what compiler generates
class is_substring {
	string substring;
	size_t &index;
public:
	is_substring(string substring,size_t & index):substring(substring), index(index){}
	bool operator()(const string& st)  {
			index = st.find(substring);
			return (index != std::string::npos); 
	}
};


int main()
{
	vector<string> inputs{"aishi-sanjay", "aishitishyasanjay", "aishitishya", "tishyaaishi", "hi"};
	//Find all the first strings which contain a substring(Without passing it as parameter)
	string substring = "aishi";
	if(inputs[0].find("abc") != std::string::npos) { cout << "found"; }
	
	//local variable substring captured in lambda function implementation
	auto res = std::find_if(inputs.begin(), inputs.end(),
		[substring](const string& st) { return (st.find(substring) != std::string::npos); });
	if (res != inputs.end()) {
		cout << substring << " found in " << *res << endl;
	}
	else {
		cout << "None of the strings in input contain " << substring << endl;
	}


	//Now if found also report the position at which the substring is found
	auto index = string::npos;
	substring = "tishya";



	//Capture index by reference, the lambda become mutable 
	auto lambda = [substring, &index] (const string& st)  { 
			index = st.find(substring);
			return (index != std::string::npos); };

	res = std::find_if(inputs.begin(), inputs.end(), lambda);
	//The commneted code below is inline version of above
	//res = std::find_if(inputs.begin(), inputs.end(),
	//	[substring, &index] (const string& st)  { 
	//		index = st.find(substring);
	//		return (index != std::string::npos); });
	if (res != inputs.end()) {
		cout << substring << " found in " << *res << " at index " << index << endl;
	}
	else {
		cout << "None of the strings in input contain " << substring << endl;
	}


	substring = "sanjay";
	//Version of implementation with functor that compiler is going to generate
	res = std::find_if(inputs.begin(), inputs.end(), is_substring(substring,index));
	if (res != inputs.end()) {
		cout << substring << " found in " << *res << " at index " << index << endl;
	}
	else {
		cout << "None of the strings in input contain " << substring << endl;
	}
}

