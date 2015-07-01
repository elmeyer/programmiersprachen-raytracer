#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

#include <utility>
#include <math.h>
#include <glm/vec3.hpp>
#include "shape.hpp"

class Box: public Shape {
public:
        Box(); // default constructor
        Box(Box const& b); // copy constructor
        // Box(Box&& b); // move constructor, copy & swap
        Box(glm::vec3 const& min, glm::vec3 const& max);
        Box(std::string const& name);
        Box(Material const& material);
        Box(std::string const& name, Material const& material);
        Box(glm::vec3 const& min, glm::vec3 const& max,
                std::string const& name);
        Box(glm::vec3 const& min, glm::vec3 const& max,
                Material const& material);
        Box(glm::vec3 const& min, glm::vec3 const& max,
                std::string const& name, Material const& material);

        // void swap(Box & b1, Box & b2);

        glm::vec3 const& getMin() const;

        glm::vec3 const& getMax() const;

        /* virtual */ double area() const;

        /* virtual */ double volume() const;

        /* virtual */ std::ostream& print(std::ostream& os) const;

        /* virtual */ bool intersect(Ray const& r, float& t);
private:
        glm::vec3 min_;
        glm::vec3 max_;
};

#endif