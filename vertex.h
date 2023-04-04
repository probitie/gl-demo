#pragma once
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

struct vertex
{

	// TODO set the new layout in vao.set_layout when changing fields here
	glm::vec3 position; // position in the space
	glm::vec3 normal; // direction of a normal vector from this point (to render lighting)
	// glm::vec2 texture_pos; // texture coordinates // dunno if I need it
};