#pragma once
#include "libs.h"

#include <vector>

#include "defines.h"
#include "ebo_t.h"
#include "vao_t.h"
#include "vertex_t.h"


class mesh_t
{
public:
	/**
	 * \brief creates mesh with these vertices/indices. 
	 * \param vertices vertices of a mesh
	 * \param indices indices for that vertices
	 *
	 * WARNING: this constructor unbinds previous VAO in purpose to bind itself's
	 */
	mesh_t(std::vector<vertex_t>&& vertices, std::vector<GLuint>&& indices);

	void render();

private:
	vao_t vao;
	vbo_t vbo;
	ebo_t ebo;
	size_t indices_count;
};

