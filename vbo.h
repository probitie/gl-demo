#pragma once
#include <vector>

#include "vertex.h"

class vbo
{
public:
	explicit vbo(const std::vector<vertex>& vertices);
	void unbind();
};

