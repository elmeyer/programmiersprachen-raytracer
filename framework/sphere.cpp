#include "sphere.hpp"
#include <math.h>

Sphere::Sphere(): // default constructor
        center_{0.0, 0.0, 0.0},
        radius_{0.0}
        {}

Sphere::Sphere(Sphere const& s): // copy constructor
        center_{s.center_},
        radius_{s.radius_}
        {}

Sphere::Sphere(Sphere&& s): // move constructor, copy & swap
        Sphere()
        {
                swap(*this, s);
        }

Sphere::Sphere(glm::vec3 const& c, double r):
        center_{c},
        radius_{r}
        {}

friend void Sphere::swap(Sphere & s1, Sphere & s2) {
        std::swap(s1.center_, s2.center_);
        std::swap(s1.radius_, s2.radius_);
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