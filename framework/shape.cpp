#include "shape.hpp"

Shape::Shape():
        name_{},
        color_{0.0, 0.0, 0.0}
        {std::cout << "Construct a Shape!" << "\n";}

/* virtual */ Shape::~Shape() {
        std::cout << "Destroy the Shape!" << "\n";
}

Shape::Shape(std::string const& name):
        name_{name},
        color_{1.0, 1.0, 1.0}
        {std::cout << "Construct a Shape!" << "\n";}

Shape::Shape(Color const& color):
        name_{},
        color_{color}
        {std::cout << "Construct a Shape!" << "\n";}

Shape::Shape(std::string const& name, Color const& color):
        name_{name},
        color_{color}
        {std::cout << "Construct a Shape!" << "\n";}

std::string const& Shape::getName() const {
        return name_;
}

Color const& Shape::getColor() const {
        return color_;
}

/* virtual */ std::ostream& Shape::print(std::ostream& os) const {
        os << "Shape " << name_ << ", RGB: " << color_;
        return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s) {
        s.print(os);
        return os;
}