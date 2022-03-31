#include <ranges>
#include <iostream>
 
int main()
{
    auto const ints = {0,1,2,3,4,5};
    auto even = [](int i) { return 1 == i % 2; };
    auto cube = [](int i) { return i * i * i; };
 
    // "pipe" syntax of composing the views:
    for (int i : ints | std::views::filter(even) | std::views::transform(cube)) {
        std::cout << i << ' ';
    }
 
    std::cout << '\n';
 
    // a traditional "functional" composing syntax:
    for (int i : std::views::transform(std::views::filter(ints, even), cube)) {
        std::cout << i << ' ';
    }
}
