#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

class Shape {
public:
        Shape();
        Shape(Shape const& s);
        Shape(Shape&& s);
        virtual double area() const = 0;
        virtual double volume() const = 0;
};

#endif