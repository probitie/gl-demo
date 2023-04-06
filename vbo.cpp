#include "vbo.h"

vbo::vbo(const std::vector<vertex>& vertices)
{
	DBG(glGenBuffers(1, &id));

	bind();
	DBG(glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex), vertices.data(), GL_STATIC_DRAW));
}

vbo::~vbo()
{
	DBG(glDeleteBuffers(1, &id));
}

void vbo::bind()
{
	DBG(glBindBuffer(GL_ARRAY_BUFFER, id));
}

void vbo::unbind()
{
	DBG(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
