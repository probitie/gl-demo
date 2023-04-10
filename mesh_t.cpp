#include "mesh_t.h"

#include "error.h"

mesh_t::mesh_t(std::vector<vertex_t>&& vertices, std::vector<GLuint>&& indices)
	: indices_count{ indices.size() }, vbo{ std::move(vertices) }, ebo{ std::move(indices) }
{
	vao.bind();

	// vao layout
	vao.set_attribute(vbo, 0, 3, GL_FLOAT, sizeof(vertex_t), offsetof(vertex_t, position));
	vao.set_attribute(vbo, 1, 3, GL_FLOAT, sizeof(vertex_t), offsetof(vertex_t, color));

	vao.unbind();
	vbo.unbind();
	ebo.unbind();

	RD_ASSERT((indices_count < std::numeric_limits<GLuint>::max())
		, "too many vertex_t indices (int type overflow)");
}

void mesh_t::render()
{
	vao.bind();
	DBG(glDrawElements(GL_TRIANGLES, indices_count, GL_UNSIGNED_INT, 0));  // NOLINT(bugprone-narrowing-conversions, clang-diagnostic-shorten-64-to-32)
	vao.unbind();
}
