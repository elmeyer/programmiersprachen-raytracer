#include "sphere.hpp"
#include <string>

Sphere::Sphere(): // default constructor
        Shape(),
        center_{0.0, 0.0, 0.0},
        radius_{0.0}
        {std::cout << "Construct a Sphere!" << "\n";}

/* virtual */ Sphere::~Sphere() { // destructor
        std::cout << "Destroy the Sphere!" << "\n";
}

Sphere::Sphere(Sphere const& s): // copy constructor
        Shape(s.getName(), s.getColor()),
        center_{s.center_},
        radius_{s.radius_}
        {std::cout << "Construct a Sphere!" << "\n";}
/*
Sphere::Sphere(Sphere&& s): // move constructor, copy & swap
        Sphere()
        {
                swap(*this, s);
        }
*/
Sphere::Sphere(std::string const& name):
        Shape(name),
        center_{0.0, 0.0, 0.0},
        radius_{0.0}
        {std::cout << "Construct a Sphere!" << "\n";}

Sphere::Sphere(Color const& color):
        Shape(color),
        center_{0.0, 0.0, 0.0},
        radius_{0.0}
        {std::cout << "Construct a Sphere!" << "\n";}

Sphere::Sphere(std::string const& name, Color const& color):
        Shape(name, color),
        center_{0.0, 0.0, 0.0},
        radius_{0.0}
        {std::cout << "Construct a Sphere!" << "\n";}

Sphere::Sphere(glm::vec3 const& c, double r):
        Shape(),
        center_{c},
        radius_{r}
        {std::cout << "Construct a Sphere!" << "\n";}

Sphere::Sphere(glm::vec3 const& c, double r, std::string const& name):
        Shape(name),
        center_{c},
        radius_{r}
        {std::cout << "Construct a Sphere!" << "\n";}

Sphere::Sphere(glm::vec3 const& c, double r, Color const& color):
        Shape(color),
        center_{c},
        radius_{r}
        {std::cout << "Construct a Sphere!" << "\n";}

Sphere::Sphere(glm::vec3 const& c, double r, std::string const& name,
                Color const& color):
        Shape(name, color),
        center_{c},
        radius_{r}
        {std::cout << "Construct a Sphere!" << "\n";}

Sphere::Sphere(double r):
        Shape(),
        center_{0.0, 0.0, 0.0},
        radius_{r}
        {std::cout << "Construct a Sphere!" << "\n";}

Sphere::Sphere(double r, std::string const& name):
        Shape(name),
        center_{0.0, 0.0, 0.0},
        radius_{r}
        {std::cout << "Construct a Sphere!" << "\n";}

Sphere::Sphere(double r, Color const& color):
        Shape(color),
        center_{0.0, 0.0, 0.0},
        radius_{r}
        {std::cout << "Construct a Sphere!" << "\n";}

Sphere::Sphere(double r, std::string const& name, Color const& color):
        Shape(name, color),
        center_{0.0, 0.0, 0.0},
        radius_{r}
        {std::cout << "Construct a Sphere!" << "\n";}
/*
void Sphere::swap(Sphere & s1, Sphere & s2) {
        std::swap(s1.center_, s2.center_);
        std::swap(s1.radius_, s2.radius_);
        std::swap(s1.name_, s2.name_);
        std::swap(s1.color_, s2.color_);
}
*/
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

/* virtual */ std::ostream& Sphere::print(std::ostream& os) const {
        os << "Sphere " << getName() << ", Center (" << center_.x << "," 
                << center_.y << "," << center_.z << "), Radius " << radius_ 
                << ", ColorRGB " << getColor();
        return os;
}

bool Sphere::intersect(Ray const& r, float & d) const {
        auto v = glm::normalize(r.direction);

        return glm::intersectRaySphere(r.origin, v, center_,
                radius_, d);
}