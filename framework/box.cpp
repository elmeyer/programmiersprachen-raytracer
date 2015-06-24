#include "box.hpp"

Box::Box(): // default constructor
        Shape(),
        min_{0.0, 0.0, 0.0},
        max_{0.0, 0.0, 0.0}
        {}

Box::Box(Box const& b): // copy constructor
        Shape(b.getName(), b.getColor()),
        min_{b.min_},
        max_{b.max_}
        {}
/*
Box::Box(Box&& b): // move constructor
        Box()
        {
                swap(*this, b);
        }
*/
Box::Box(glm::vec3 const& min, glm::vec3 const& max):
        Shape(),
        min_{min},
        max_{max}
        {}

Box::Box(std::string const& name):
        Shape(name),
        min_{0.0, 0.0, 0.0},
        max_{0.0, 0.0, 0.0}
        {}

Box::Box(Color const& color):
        Shape(color),
        min_{0.0, 0.0, 0.0},
        max_{0.0, 0.0, 0.0}
        {}

Box::Box(std::string const& name, Color const& color):
        Shape(name, color),
        min_{0.0, 0.0, 0.0},
        max_{0.0, 0.0, 0.0}
        {}

Box::Box(glm::vec3 const& min, glm::vec3 const& max,
        std::string const& name):
        Shape(name),
        min_{min},
        max_{max}
        {}

Box::Box(glm::vec3 const& min, glm::vec3 const& max,
        Color const& color):
        Shape(color),
        min_{min},
        max_{max}
        {}

Box::Box(glm::vec3 const& min, glm::vec3 const& max,
        std::string const& name, Color const& color):
        Shape(name, color),
        min_{min},
        max_{max}
        {}
/*
void Box::swap(Box & b1, Box & b2) {
        std::swap(b1.min_, b2.min_);
        std::swap(b1.max_, b2.max_);
}
*/
glm::vec3 Box::getMin() const {
        return min_;
}

glm::vec3 Box::getMax() const {
        return max_;
}

/* virtual */ double Box::area() const {
        return (2 * (((max_.y - min_.y) * (max_.x - min_.x)) + 
                (((max_.y - min_.y) * (max_.z - min_.z)) + 
                        ((max_.x - min_.x) * (max_.z - min_.z)))));
        // x = depth = b, y =  width = a, z = height = c
}

/* virtual */ double Box::volume() const {
        return ((max_.y - min_.y) * (max_.x - min_.x) * (max_.z - min_.z));
}

/* virtual */ std::ostream& Box::print(std::ostream& os) const {
        os << "Box " << getName() << ", Minimum (" << min_.x << "," << min_.y
                << "," << min_.z << "), Maximum (" << max_.x << "," << max_.y
                << "," << max_.z << "), ColorRGB " << getColor();
        return os;
}