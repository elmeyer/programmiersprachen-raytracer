#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include <glm/vec3.hpp>

class Sphere: public Shape {
public:
        Sphere(): // default constructor
                center_{0.0, 0.0, 0.0},
                radius_{0.0}
                {}
        Sphere(Sphere const& s): // copy constructor
                center_{s.center_},
                radius_{s.radius_}
                {}
        Sphere(Sphere&& s): // move constructor, copy & swap
                Sphere()
                {
                        swap(*this, s);
                }
        Sphere(glm::vec3 const& c, double r):
                center_{c},
                radius_{r}
                {}

        friend void swap(Sphere & s1, Sphere & s2) {
                std::swap(s1.center_, s2.center_);
                std::swap(s1.radius_, s2.radius_);
        }

        double getRadius() const {
                return radius_;
        }

        glm::vec3 getCenter() const {
                return center_;
        }
private:
        glm::vec3 center_;
        double radius_;
};

#endif