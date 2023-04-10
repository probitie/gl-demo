#include "material_t.h"

material_t::material_t(raw_str vertex_path, raw_str fragment_path)
	: shader_program{ vertex_path, fragment_path }
{}


void material_t::enable()
{
	shader_program.activate();
}

void material_t::disable()
{
	shader_program.deactivate();
}
