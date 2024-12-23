
#include<iostream>
#include<memory>
#include<functional>
#include <memory>
#include <type_traits>
#include <utility>

#include<vector>
#include "circle.hh"
#include "square.hh"
#include "rectangle.hh"
#include "shape.hh"

using namespace std;



int main()
{
    Circle c{3};
    const Circle cc{3};
    Shape s1{c};
    Shape s2{Circle{3.0}};
    Shape s4{Shape{Circle{3.0}}};
    Shape s5{std::move(s2)};
    Shape s6 = s5;

    draw(s6);

    std::vector<Shape> shapes;
    shapes.emplace_back(Circle{1.0});
    shapes.emplace_back(Square{2.0});
    for(auto shp: shapes){
        draw(shp);
    }

    return 0;
}


