#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include <glm/vec3.hpp>
#include <math.h>

class Sphere: public Shape {
public:
        Sphere();
        Sphere(Sphere const& s);
        Sphere(Sphere&& s);
        Sphere(glm::vec3 const& c, double r);

        friend void swap(Sphere & s1, Sphere & s2);
        
        double getRadius() const;

        glm::vec3 getCenter() const;

        /* virtual */ double area() const;

        /* virtual */ double volume() const;
private:
        glm::vec3 center_;
        double radius_;
};

#endif