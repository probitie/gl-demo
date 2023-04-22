#pragma once
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

// TODO delete when finish with diffuse lighting
struct vertex_t
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texture_pos;
};


