#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include <utility>
#include <math.h>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "shape.hpp"

class Sphere: public Shape {
public:
        Sphere(); // default constructor
        ~Sphere(); // destructor
        Sphere(Sphere const& s); // copy constructor
        // Sphere(Sphere&& s); // move constructor, copy & swap
        Sphere(std::string const& name);
        Sphere(Material const& material);
        Sphere(std::string const& name, Material const& material);
        Sphere(glm::vec3 const& c, double r);
        Sphere(glm::vec3 const& c, double r, std::string const& name);
        Sphere(glm::vec3 const& c, double r, Material const& material);
        Sphere(glm::vec3 const& c, double r, std::string const& name,
                Material const& material);
        Sphere(double r);
        Sphere(double r, std::string const& name);
        Sphere(double r, Material const& material);
        Sphere(double r, std::string const& name, Material const& material);

        // void swap(Sphere & s1, Sphere & s2);
        
        double const getRadius() const;

        glm::vec3 const& getCenter() const;

        /* virtual */ double area() const;

        /* virtual */ double volume() const;

        /* virtual */ std::ostream& print(std::ostream& os) const;

        bool intersect(Ray const& r, float & d);
private:
        glm::vec3 center_;
        double radius_;
};

#endif