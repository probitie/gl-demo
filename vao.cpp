#include "vao.h"

#include "error.h"

vao::vao()
	: is_bound{false}
{
	// Generate a vertex array object, not a buffer object
	DBG(glGenVertexArrays(1, &id));
	bind();

}

vao::~vao()
{
	DBG(glDeleteVertexArrays(1, &id));
}


void vao::bind()
{
	is_bound = true;
	DBG(glBindVertexArray(id));
}

void vao::unbind()
{
	is_bound = false;
	DBG(glBindVertexArray(0));
}

void vao::set_attribute(vbo& vbo_, i32 index, i32 components_count, GLenum data_type, size_t struct_size, size_t offset)
{
	vbo_.bind();
	RD_ASSERT(is_bound, "your vao is unbound, so I can non add this attribute");
	DBG(glVertexAttribPointer(index, components_count, data_type, GL_FALSE, struct_size, reinterpret_cast<void*>(offset)));
	DBG(glEnableVertexAttribArray(index));
	vbo_.unbind();
}
