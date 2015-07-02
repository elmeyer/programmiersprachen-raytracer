#ifndef BUW_SCENE_HPP
#define BUW_SCENE_HPP

#include <vector>
#include "material.hpp"
#include "sphere.hpp"
#include "box.hpp"
// #include "light.hpp"
// #include "camera.hpp"

struct Scene {
        std::vector<Material> materials;
        std::vector<Sphere> spheres;
        std::vector<Box> boxes;
        // std::vector<Light> lights;
        // Camera camera;
};

#endif