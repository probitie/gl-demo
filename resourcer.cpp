#include "resourcer.h"

#include "defines.h"
#include "ebo.h"
#include "shader_program.h"
#include "vao.h"
#include "vbo.h"


raw_str vs = "";
raw_str fs = "";


// TODO only for testing for now
model&& resourcer::load_model(const std::string& resource_path)
{
	// TODO implement - one material and one mesh

    std::vector<vertex> vertices = {
        // bottom left
        {glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        // top left
        {glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        // top right
        {glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        // bottom right
        {glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)}
    };

    std::vector<GLuint> indices = {
        0, 1, 2, // first triangle
        2, 3, 0  // second triangle
    };

	std::vector<mesh> msh{
        {vertices, indices}
	};
	std::vector<material> mat{};

	return { std::move(msh), std::move(mat) };
}
