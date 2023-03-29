#pragma once
#include "libs.h"
#include "mesh.h"

/**
 * \brief loads resources and other objects
 */
class resourcer
{
public:
	mesh load_mesh(const std::string& str);
};

