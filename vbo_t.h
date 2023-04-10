#pragma once
#include <vector>
#include "libs.h"
#include "vertex_t.h"
#include "error.h"

class vbo_t
{
public:
	/**
	 * \brief initializes the buffer and writes vertices to it
	 *
	 * WARNING: it binds and unbinds glBuffer,
	 *          so make sure you didn't bind any buffer before creating this object
	 *
	 * \param vertices vector of vertices
	 */
	explicit vbo_t(std::vector<vertex_t>&& vertices);

	void bind();
	void unbind();

private:
	GLuint id;
};

