#pragma once
#include "libs.h"
#include "material.h"

#include "mesh.h"

/**
 * \brief object on a screen
 *
 * Typically is a 3D model
 * Has mesh(polygons) and material(textures, shaders) component
 */

class model
{
public:
	/**
	 * \brief Accepts parameters only by perfect forwarding
	 * \param meshes an array of meshes for the model
	 * \param materials and array of materials. Each material will apply on
	 *		  a mesh with the same index (one material per mesh)
	 */
	model(std::vector<mesh>&& meshes, std::vector<material>&& materials)
		: m_meshes(std::move(meshes)), m_materials(std::move(materials))
	{ /* empty */ }

	/**
	 * \brief force user to pass parameters as rvalue
	 */
	model(std::vector<mesh>& meshes, std::vector<material>& materials) = delete;

	~model() = default;

	/**
	 * \brief draws the model on a screen
	 */
	void render();

private:
	std::vector<mesh> m_meshes;
	std::vector <material> m_materials;
};

