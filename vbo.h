#pragma once
#include <vector>
#include "libs.h"
#include "vertex.h"
#include "error.h"

class vbo
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
	explicit vbo(const std::vector<vertex>& vertices);

	~vbo();
	void bind();
	void unbind();

private:
	GLuint id;
};

