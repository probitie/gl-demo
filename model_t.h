#pragma once
#include "libs.h"
#include "material_t.h"

#include "mesh_t.h"

/**
 * \brief object on a screen
 *
 * Typically is a 3D model_t
 * Has mesh_t(polygons) and material_t(textures, shaders) component
 */

class model_t
{
public:
	/**
	 * \brief Accepts parameters only by perfect forwarding
	 * \param meshes an array of meshes for the model
	 * \param materials and array of materials. Each material will apply on
	 *		  a mesh with the same index (one material per mesh)
	 */
	model_t(std::vector<mesh_t>&& meshes, std::vector<material_t>&& materials)
		: m_meshes(std::move(meshes)), m_materials(std::move(materials))
	{ /* empty */ }

	/**
	 * \brief force user to pass parameters as rvalue
	 */
	model_t(std::vector<mesh_t>& meshes, std::vector<material_t>& materials) = delete;

	~model_t() = default;

	/**
	 * \brief draws the model on a screen
	 */
	void render();

private:
	std::vector<mesh_t> m_meshes;
	std::vector <material_t> m_materials;
};

