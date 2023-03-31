#pragma once
#include <vector>

#include "vertex.h"

class vao
{
	/**
	 * \brief writes the layout to vao and raw array to vbo
	 * \param vertices its class describes layout
	 */
	explicit vao(const std::vector<vertex>& vertices);
};

