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
	std::vector<mesh> msh{};
	std::vector<material> mat{};
#error "material and mesh are not set"



	model m{ std::move(msh), std::move(mat) };
	return std::move(m);
}
