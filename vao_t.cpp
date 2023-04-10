#include "vao_t.h"

#include "error.h"

vao_t::vao_t()
	: is_bound{false}
{
	// Generate a vertex_t array object, not a buffer object
	DBG(glGenVertexArrays(1, &id));
	bind();

}

vao_t::~vao_t()
{
	DBG(glDeleteVertexArrays(1, &id));
}


void vao_t::bind()
{
	is_bound = true;
	DBG(glBindVertexArray(id));
}

void vao_t::unbind()
{
	is_bound = false;
	DBG(glBindVertexArray(0));
}

void vao_t::set_attribute(vbo_t& vbo_, i32 index, i32 components_count, GLenum data_type, size_t struct_size, size_t offset)
{
	vbo_.bind();
	RD_ASSERT(is_bound, "your vao_t is unbound, so I can non add this attribute");
	DBG(glVertexAttribPointer(index, components_count, data_type, GL_FALSE, struct_size, reinterpret_cast<void*>(offset)));
	DBG(glEnableVertexAttribArray(index));
	vbo_.unbind();
}
