#pragma once
#include "libs.h"

#include <vector>

#include "defines.h"
#include "ebo.h"
#include "vao.h"
#include "vertex.h"


class mesh
{
public:

	mesh(const std::vector<vertex>& vertices, const std::vector<GLuint>& indices);

	~mesh() = default;

	void render();

private:
	vao m_vao;
	size_t indices_count;
};

