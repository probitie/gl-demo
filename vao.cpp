#include "vao.h"

#include "error.h"

vao::vao()
	: is_bound{false}
{
	// Generate a vertex array object, not a buffer object
	glGenVertexArrays(1, &id);
}

vao::~vao()
{
	glDeleteVertexArrays(1, &id);
}

// for now it sets layout only for <vertex> type
void vao::set_layout()
{
	ASSERT(is_bound, "you need to bind vao before setting its layout");

	// vertex coordinates

	// position_vec3 and color_vec3
	set_attribute(0, 3, GL_FLOAT, sizeof(vertex), offsetof(vertex, position));
	set_attribute(1, 3, GL_FLOAT, sizeof(vertex), offsetof(vertex, color));
	//vao.setAttribute(2, 2, GL_FLOAT, sizeof(vertex), offsetof(vertex, texcoord));

}

void vao::bind()
{
	is_bound = true;
	glBindVertexArray(id);
}

void vao::unbind()
{
	is_bound = false;
	glBindVertexArray(0);
}

void vao::set_attribute(i32 index, i32 components_count, GLenum data_type, size_t struct_size, size_t offset)
{
	ASSERT(is_bound, "your vao is unbound, so I can non add this attribute");
	glVertexAttribPointer(index, components_count, data_type, GL_FALSE, struct_size, reinterpret_cast<void*>(offset));
	glEnableVertexAttribArray(index);
}
