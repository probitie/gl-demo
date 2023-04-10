#include "resource_system_t.h"

#include "defines.h"
#include "ebo_t.h"
#include "shader_program_t.h"
#include "vao_t.h"
#include "vbo_t.h"


// TODO only for testing for now
mesh_t&& resource_system_t::load_mesh(MESHES mesh_id) const
{
	std::vector<vertex_t> cube_vertices {
		// bottom face
		{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 0.0f)},
		{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f)},
		{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.0f, 1.0f)},
		{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 1.0f)},
		// top face
		{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 0.0f)},
		{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 1.0f, 1.0f)},
		{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.5f, 0.5f, 0.0f)},
		{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 1.0f, 0.5f)}
	};
	std::vector<GLuint> cube_indices {
		// bottom face
		0, 1, 2,
		2, 3, 0,
		// top face
		4, 5, 6,
		6, 7, 4,
		// left face
		0, 4, 7,
		7, 3, 0,
		// right face
		1, 5, 6,
		6, 2, 1,
		// front face
		0, 1, 5,
		5, 4, 0,
		// back face
		3, 2, 6,
		6, 7, 3
	};
	std::vector<vertex_t> pyro_vertices {
	{glm::vec3(-0.5f, 0.0f, 0.5f), glm::vec3(0.83f, 0.70f, 0.44f)},
	{glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f)},
	{glm::vec3(0.5f, 0.0f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f)},
	{glm::vec3(0.5f, 0.0f, 0.5f), glm::vec3(0.83f, 0.70f, 0.44f)},
	{glm::vec3(0.0f, 0.8f, 0.0f), glm::vec3(0.92f, 0.86f, 0.76f)}
	};
	std::vector<GLuint> pyro_indices {
		0, 1, 2,
		0, 2, 3,
		0, 1, 4,
		1, 2, 4,
		2, 3, 4,
		3, 0, 4
	};

	if (mesh_id == RD_CUBE)
	{
		return mesh_t{ std::move(cube_vertices), std::move(cube_indices) };
	}
	if (mesh_id == RD_PYRO)
	{
		return mesh_t{ std::move(pyro_vertices), std::move(pyro_indices) };
	}

	RD_TERMINATE(false, "unknown mesh id, cannot load it");
}

material_t&& resource_system_t::load_material(MATERIALS material_id) const
{
	if(material_id == RD_DEFAULT)
	{
		return material_t{RD_V_SHADER_PATH, RD_F_SHADER_PATH};
	}
	RD_TERMINATE(false, "unknown material id, cannot load it");
}
