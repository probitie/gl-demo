#pragma once
#include "libs.h"
#include "shader_program_t.h"

class material_t
{
public:
	material_t(raw_str vertex_path, raw_str fragment_path);

	void enable();
	void disable();

	// TODO make shader_program private
// private:
	shader_program_t shader_program;
};

