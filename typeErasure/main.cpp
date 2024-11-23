#include<iostream>
#include<regex>
using namespace std;

void print_matches_v1(string input, std::regex re) 
{
    cout << "This is version 1 of the Match pattern" << endl;
    std::smatch matches;
    std::cout << std::boolalpha;
    std::regex_search(input,matches,re);
    cout << "Is the result ready?" << matches.ready() << std::endl;
    cout << "Is there a match?" << matches.size() << std::endl;
    cout << matches.str() << endl;
    cout << "Prefix:" << matches.prefix() << endl;
    cout <<"Suffix:" << matches.suffix() << std::endl;
    cout << endl;
}

void print_matches_v2(string input, std::regex reg) 
{
    cout << "This is version 2 of the Match pattern" << endl;
    std::sregex_iterator match_itr(input.begin(), input.end(), reg);
    std::sregex_iterator last_match_it;
    while(match_itr != last_match_it) {
        std::smatch match = *match_itr;
        cout << match.str() << endl;
        match_itr++;
    }

}

int main(int argc, char**)
{
    std::string input = "This is an input string thatt will be used for that testing regex";
    std::regex re("that[t]?");
    print_matches_v1(input, re);
    print_matches_v2(input, re);

    return 0;
}