#pragma once
#include <vector>
#include <glad/glad.h>

#include "vbo.h"
#include "vertex.h"
#include <cassert>
#include <type_traits>

#include "defines.h"

// TODO move common logic between vao vbo ebo into a superclass
class vao
{
	/**
	 * \brief writes the layout to vao and raw array to vbo
	 */
public:
	explicit vao();
	~vao();

	/**
	 * \brief sets a layout for vao. YOU NEED TO BIND VAO BEFORE CALLING THIS FUNC
	 */
	void set_layout();

	void bind();
	void unbind();

private:
	GLuint id;

	// to check if this vao is bind now
	// TODO do more safe check
	bool is_bind;

	/**
	 * \brief sets attribute for bound vao
	 * \param index index of an attribute. is used in shaders ("layout(0)" - for index 0 etc.)
	 * \param components_count how many components in this attribute (ex.: attribute is vec3, so component count is 3)
	 * \param data_type a type of the components
	 * \param struct_size size of one data chunk (like VBO represents array<chunk>)
	 * \param offset offset from chunk beginning
	 */
	void set_attribute(int index, int components_count, GLenum data_type, size_t struct_size, size_t offset);

};

