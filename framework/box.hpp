#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

#include <glm/vec3.hpp>
#include <math.h>

class Box: public Shape {
public:
        Box(); // default constructor
        Box(Box const& b); // copy constructor
        Box(Box&& b); // move constructor, copy & swap
        Box(glm::vec3 const& min, glm::vec3 const& max);

        friend void swap(Box & b1, Box & b2);

        glm::vec3 getMin() const;

        glm::vec3 getMax() const;

        /* virtual */ double area() const;

        /* virtual */ double volume() const;
private:
        glm::vec3 min_;
        glm::vec3 max_;
};

#endif