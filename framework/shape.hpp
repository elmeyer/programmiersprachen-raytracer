#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include <string>
#include "color.hpp"

class Shape {
public:
        virtual double area() const = 0;
        virtual double volume() const = 0;
private:
        std::string name_;
        Color color_;
};

#endif