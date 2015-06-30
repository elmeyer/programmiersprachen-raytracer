#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include <iostream>
#include <string>
#include "material.hpp"

class Shape {
public:
        Shape();
        /* virtual */ ~Shape();
        Shape(std::string const& name);
        Shape(Material const& material);
        Shape(std::string const& name, Material const& material);

        std::string const& getName() const;
        Material const& getMaterial() const;

        virtual double area() const = 0;
        virtual double volume() const = 0;

        virtual std::ostream& print(std::ostream& os) const;
private:
        std::string name_;
        Material material_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif