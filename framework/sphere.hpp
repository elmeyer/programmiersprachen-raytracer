#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include <utility>
#include <math.h>
#include <glm/vec3.hpp>
#include "shape.hpp"

class Sphere: public Shape {
public:
        Sphere(); // default constructor
        Sphere(Sphere const& s); // copy constructor
        Sphere(Sphere&& s); // move constructor, copy & swap
        Sphere(std::string const& name);
        Sphere(Color const& c);
        Sphere(std::string const& name, Color const& c);
        Sphere(glm::vec3 const& c, double r);
        Sphere(glm::vec3 const& c, double r, std::string const& name);
        Sphere(glm::vec3 const& c, double r, Color const& c);
        Sphere(glm::vec3 const& c, double r, std::string const& name,
                Color const& c);
        Sphere(double r);
        Sphere(double r, std::string const& name);
        Sphere(double r, Color const& c);
        Sphere(double r, std::string const& name, Color const& c);

        void swap(Sphere & s1, Sphere & s2);
        
        double getRadius() const;

        glm::vec3 getCenter() const;

        /* virtual */ double area() const;

        /* virtual */ double volume() const;
private:
        glm::vec3 center_;
        double radius_;
};

#endif