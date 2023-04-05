#include "vbo.h"

vbo::vbo(const std::vector<vertex>& vertices)
{
	glGenBuffers(1, &id);

	bind();
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex), vertices.data(), GL_STATIC_DRAW);
}

vbo::~vbo()
{
	glDeleteBuffers(1, &id);
}

void vbo::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void vbo::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
