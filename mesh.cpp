#include "mesh.h"

#include "error.h"

mesh::mesh(const std::vector<vertex>& vertices, const std::vector<GLuint>& indices)
	: indices_count{ indices.size() }
{

	m_vao.bind();
	vbo vbo_{ vertices };
	ebo ebo_{ indices };

	m_vao.set_layout();

	m_vao.unbind();
	vbo_.unbind();
	ebo_.unbind();
}

void mesh::render()
{
	m_vao.bind();

	ASSERT((indices_count < std::numeric_limits<GLuint>::max())
		, "too many vertex indices (int type overflow)");

	glDrawElements(GL_TRIANGLES, indices_count, GL_UNSIGNED_INT, 0);

	m_vao.unbind();
}
