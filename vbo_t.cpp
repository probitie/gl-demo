#include "vbo_t.h"

vbo_t::vbo_t(std::vector<vertex_t>&& vertices)
{
	DBG(glGenBuffers(1, &id));

	bind();
	DBG(glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex_t), vertices.data(), GL_STATIC_DRAW));
}

void vbo_t::bind()
{
	DBG(glBindBuffer(GL_ARRAY_BUFFER, id));
}

void vbo_t::unbind()
{
	DBG(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
