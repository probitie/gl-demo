#include "ebo_t.h"


ebo_t::ebo_t(std::vector<GLuint>&& indices)
	: vertices_count{indices.size()}
{
	DBG(glGenBuffers(1, &id));
	bind();
	DBG(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW));
}

void ebo_t::bind() const
{
	DBG(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id));

}

void ebo_t::unbind() const
{
	DBG(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

}

GLsizei ebo_t::get_indices_count() const
{
	return vertices_count;
}
