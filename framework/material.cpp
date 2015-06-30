#include "material.hpp"

Material::Material():
        name{},
        ka{0,0,0},
        kd{0,0,0},
        ks{0,0,0},
        m{0}
        {}

Material::Material(std::string const& name, Color const& ka, Color const& kd,
                Color const& ks, float m):
        name{name},
        ka{ka},
        kd{kd},
        ks{ks},
        m{m}
        {}

std::string const& Material::getName() const {
        return name;
}

Color const& Material::getColorKa() const {
        return ka;
}

Color const& Material::getColorKd() const {
        return kd;
}

Color const& Material::getColorKs() const {
        return ks;
}

float const Material::getM() const {
        return m;
}

std::ostream& operator<<(std::ostream& os, Material const& m) {
        os << "--------" << "\n" << "Material " << "\n" << "--------" << "\n" 
                << "Name: " << m.getName() << "\n" << "Colors (RGB):" << "\n" 
                << "        ka: " << m.getColorKa() << "        kd: " 
                << m.getColorKd() << "        ks: " << m.getColorKs() 
                << "m: " << m.getM();
        return os;
}