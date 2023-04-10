#pragma once
#include "libs.h"
#include "model_t.h"

/**
 * \brief loads resources and other objects
 */
class resource_system_t
{
public:
	mesh_t&& load_mesh(MESHES mesh_id) const;
	material_t&& load_material(MATERIALS material_id) const;

};

