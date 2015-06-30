#include "shape.hpp"

Shape::Shape():
        name_{},
        material_{}
        {std::cout << "Construct a Shape!" << "\n";}

/* virtual */ Shape::~Shape() {
        std::cout << "Destroy the Shape!" << "\n";
}

Shape::Shape(std::string const& name):
        name_{name},
        material_{}
        {std::cout << "Construct a Shape!" << "\n";}

Shape::Shape(Material const& material):
        name_{},
        material_{material}
        {std::cout << "Construct a Shape!" << "\n";}

Shape::Shape(std::string const& name, Material const& material):
        name_{name},
        material_{material}
        {std::cout << "Construct a Shape!" << "\n";}

std::string const& Shape::getName() const {
        return name_;
}

Material const& Shape::getMaterial() const {
        return material_;
}

/* virtual */ std::ostream& Shape::print(std::ostream& os) const {
        os << "Shape " << name_ << "\n" << material_;
        return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s) {
        s.print(os);
        return os;
}