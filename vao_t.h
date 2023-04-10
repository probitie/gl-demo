#pragma once
#include <vector>
#include "libs.h"

#include "vbo_t.h"
#include "vertex_t.h"
#include <cassert>
#include <type_traits>

#include "defines.h"

// TODO move common logic between vao_t vbo_t ebo_t into a superclass
class vao_t
{
	/**
	 * \brief writes the layout to vao and raw array to vbo
	 */
public:
	explicit vao_t();
	~vao_t();


	void bind();
	void unbind();

	/**
	 * \brief sets attribute for bound vao
	 * \param index index of an attribute. is used in shaders ("layout(0)" - for index 0 etc.)
	 * \param components_count how many components in this attribute (ex.: attribute is vec3, so component count is 3)
	 * \param data_type a type of the components
	 * \param struct_size size of one data chunk (like VBO represents array<chunk>)
	 * \param offset offset from chunk beginning
	 */
	void set_attribute(vbo_t& vbo_, int index, int components_count, GLenum data_type, size_t struct_size, size_t offset);


private:
	GLuint id;

	// to check if this vao_t is bind now
	// TODO do more safe check
	bool is_bound;

};

