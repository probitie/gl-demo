#pragma once
#include <cstdint>
// do not include "libs.h" as this file is included in libs.h

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using raw_str = const char*;

#define rdflush = "\n" // or std::endl; etc

#define WINDOW_W 800
#define WINDOW_H 800

/**
 * \brief break program if there any errors
 */
#define RD_TERMINATE_ON_ERROR



#define RD_V_SHADER_PATH R"(D:\projects\gl\YoutubeOpenGL\vertex.vs)"
#define RD_F_SHADER_PATH R"(D:\projects\gl\YoutubeOpenGL\fragment.fs)"

enum MESHES
{
	RD_CUBE,
	RD_PYRO
};

enum MATERIALS
{
	RD_DEFAULT
};
