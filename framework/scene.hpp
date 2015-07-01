#ifndef BUW_SCENE_HPP
#define BUW_SCENE_HPP

#include <vector>
#include <unordered_map>

struct Scene {
        std::vector<Material> materials;
        std::vector<Sphere> spheres;
        std::vector<Box> boxes;
        std::vector<Light> lights;
        std::unordered_map<Camera> cameras;
};