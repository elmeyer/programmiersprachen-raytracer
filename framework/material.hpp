#ifndef BUW_MATERIAL_HPP
#define BUW_MATERIAL_HPP

#include "color.hpp"
#include <string>
#include <iostream>

class Material {
public:
        Material();
        Material(std::string const& name, Color const& ka, Color const& kd,
                Color const& ks, float m);

        std::string const& getName() const;
        Color const& getColorKa() const;
        Color const& getColorKd() const;
        Color const& getColorKs() const;
        float const getM() const;
private:
        std::string name;
        Color ka;
        Color kd;
        Color ks;
        float m;
};

std::ostream& operator<<(std::ostream& os, Material const& m);

#endif