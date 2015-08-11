#ifndef BUW_SCENE_HPP
#define BUW_SCENE_HPP

#include <vector>
#include <map>
#include "material.hpp"
#include "sphere.hpp"
#include "box.hpp"
// #include "light.hpp"
// #include "camera.hpp"

struct Scene {
        std::map<std::string, Material> materials;
        std::vector<Shape*> shapes;
        // std::vector<Light> lights;
        // Camera camera;
};

#endif