#pragma once
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

struct vertex_t
{

	// TODO set the new layout in vao_t.set_layout when changing fields here
	glm::vec3 position; // position in the space
	glm::vec3 color; // direction of a normal vector from this point (to render lighting)
	glm::vec2 texture_pos; // texture coordinates
};