#ifndef BUW_SDFLOADER_HPP
#define BUW_SDFLOADER_HPP

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "material.hpp"

std::vector<Material> loadSDF(std::string const& file);

#endif