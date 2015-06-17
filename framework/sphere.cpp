#include "sphere.hpp"

Sphere::Sphere(): // default constructor
        center_{0.0, 0.0, 0.0},
        radius_{0.0},
        name_{},
        Color{0.0, 0.0, 0.0}
        {}

Sphere::Sphere(Sphere const& s): // copy constructor
        center_{s.center_},
        radius_{s.radius_},
        name_{s.name_},
        color_{s.color_}
        {}

Sphere::Sphere(Sphere&& s): // move constructor, copy & swap
        Sphere()
        {
                swap(*this, s);
        }

Sphere::Sphere(std::string const& name):
        center_{0.0, 0.0, 0.0},
        radius_{0.0},
        name_{name},
        Color{0.0, 0.0, 0.0}
        {}

Sphere::Sphere(Color const& c):
        center_{0.0, 0.0, 0.0},
        radius_{0.0},
        name_{},
        Color{c}
        {}

Sphere(std::string const& name, Color const& c):
        center_{0.0, 0.0, 0.0},
        radius_{0.0},
        name_{name},
        Color{c}
        {}

Sphere::Sphere(glm::vec3 const& c, double r):
        center_{c},
        radius_{r},
        name_{},
        Color{0.0, 0.0, 0.0}
        {}

Sphere::Sphere(glm::vec3 const& c, double r, std::string const& name):
        center_{c},
        radius_{r},
        name_{name},
        Color{0.0, 0.0, 0.0}
        {}

Sphere::Sphere(glm::vec3 const& c, double r, Color const& c):
        center_{c},
        radius_{r},
        name_{},
        Color{c}
        {}

Sphere::Sphere(glm::vec3 const& c, double r, std::string const& name,
                Color const& c):
        center_{c},
        radius_{r},
        name_{name},
        Color{c}
        {}

Sphere::Sphere(double r):
        center_{0.0, 0.0, 0.0},
        radius_{r},
        name_{},
        Color{0.0, 0.0, 0.0}
        {}

Sphere::Sphere(double r, std::string const& name):
        center_{0.0, 0.0, 0.0},
        radius_{r},
        name_{name},
        Color{0.0, 0.0, 0.0}
        {}

Sphere::Sphere(double r, Color const& c):
        center_{0.0, 0.0, 0.0},
        radius_{r},
        name_{},
        Color{c}
        {}

Sphere::Sphere(double r, std::string const& name, Color const& c):
        center_{0.0, 0.0, 0.0},
        radius_{r},
        name_{name},
        Color{c}
        {}

void Sphere::swap(Sphere & s1, Sphere & s2) {
        std::swap(s1.center_, s2.center_);
        std::swap(s1.radius_, s2.radius_);
        std::swap(s1.name_, s2.name_);
        std::swap(s1.color_, s2.color_);
}

double Sphere::getRadius() const {
        return radius_;
}

glm::vec3 Sphere::getCenter() const {
        return center_;
}

/* virtual */ double Sphere::area() const {
        return (4 * M_PI * radius_ * radius_);
}

/* virtual */ double Sphere::volume() const {
        return ((4.0/3.0) * M_PI * radius_ * radius_ * radius_);
}