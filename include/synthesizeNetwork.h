#pragma once

// read file and create a road network from it
#include <fstream>
#include <memory>
#include <nlohmann/json.hpp>
#include <stdexcept>
#include <unordered_map>
#include "../include/roadNetwork.h"

void synthesizeNetworkFromFile(const std::string& filename, RoadNetwork& g);