#include "box.hpp"

Box::Box(): // default constructor
        min_{0.0, 0.0, 0.0},
        max_{0.0, 0.0, 0.0}
        {}

Box::Box(Box const& b): // copy constructor
        min_{b.min_},
        max_{b.max_}
        {}

Box::Box(Box&& b): // move constructor
        Box()
        {
                swap(*this, b);
        }

Box::Box(glm::vec3 const& min, glm::vec3 const& max):
        min_{min},
        max_{max}
        {}

void Box::swap(Box & b1, Box & b2) {
        std::swap(b1.min_, b2.min_);
        std::swap(b1.max_, b2.max_);
}

glm::vec3 Box::getMin() const {
        return min_;
}

glm::vec3 Box::getMax() const {
        return max_;
}

/* virtual */ double area() const {
        return 0.0;
}

/* virtual */ double volume() const {
        return 0.0;
}