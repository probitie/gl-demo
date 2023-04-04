#include "ebo.h"

ebo::ebo(const std::vector<GLuint>& indices)
	: vertices_count{indices.size()}
{
	glGenBuffers(1, &id);
	bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
	unbind();
}

void ebo::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);

}

void ebo::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

GLsizei ebo::get_indices_count() const
{
	return vertices_count;
}
