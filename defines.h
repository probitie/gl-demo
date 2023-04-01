#pragma once
#include <cstdint>

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using raw_str = const char*;

#define flush = "\n" // or std::endl; etc

#define LIGHT_CUBE_MODEL "models/light_cube.gltf"
#define FLOOR_MODEL "models/floor.gltf"
#define PYRAMID_MODEL "models/pyramid.gltf"

#define WINDOW_W 800
#define WINDOW_H 800