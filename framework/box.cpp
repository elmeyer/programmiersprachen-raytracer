#include "box.hpp"

Box::Box(): // default constructor
        Shape(),
        min_{0.0, 0.0, 0.0},
        max_{0.0, 0.0, 0.0}
        {}

Box::Box(Box const& b): // copy constructor
        Shape(b.getName(), b.getMaterial()),
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

Box::Box(Material const& material):
        Shape(material),
        min_{0.0, 0.0, 0.0},
        max_{0.0, 0.0, 0.0}
        {}

Box::Box(std::string const& name, Material const& material):
        Shape(name, material),
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
        Material const& material):
        Shape(material),
        min_{min},
        max_{max}
        {}

Box::Box(glm::vec3 const& min, glm::vec3 const& max,
        std::string const& name, Material const& material):
        Shape(name, material),
        min_{min},
        max_{max}
        {}
/*
void Box::swap(Box & b1, Box & b2) {
        std::swap(b1.min_, b2.min_);
        std::swap(b1.max_, b2.max_);
}
*/
glm::vec3 const& Box::getMin() const {
        return min_;
}

glm::vec3 const& Box::getMax() const {
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
                << "," << max_.z << ")" << "\n" << getMaterial();
        return os;
}

bool Box::intersect(Ray const& r, float& t) {
        auto v = glm::normalize(r.direction);

        t = (min_.x - r.origin.x) / v.x;
        glm::vec3 s = r.origin + (t * v);

        if ((s.y >= min_.y && s.y <= max_.y) && (s.z >= min_.z 
                && s.z <= max_.z)) {
                return true;
        }
        else {
                return false;
        }
}