#pragma once
#include "camera_t.h"
#include "mesh_t.h"
#include "defines.h"
#include "model_t.h"
#include "window_t.h"


/**
 * \brief handles rendering on a display
 */
class render_system_t
{
public:

	//***** FIELDS *****//

	// TODO is unused for now, glViewPort is set independently
	/**
	 * \brief camera settings
	 */
	camera_t fov;
	//***** ****** *****//



	//***** METHODS *****//

	render_system_t(const window_t& win) noexcept(false);

	~render_system_t() noexcept(false);

	/**
	 * \brief adds a mesh to the context of render pipeline
	 * \param _model an object to be rendered on a display (if it in camera's fov)
	 */
	void add(const model_t& _model);

	/**
	 * \brief draws added context elements on a screen
	 */
	void draw_context();

	// TODO: do I need it? maybe call it implicitly
	/**
	 * \brief explicitly swaps screen buffers
	 */
	void swap_buffers() const;

private:

	//***** FIELDS *****//

	/**
	 * \brief current window being drawn.
	 * Do not change it,
	 * it is used once in the constructor and once in the destructor
	 */
	GLFWwindow* window_;

	//***** ****** *****//


	//***** METHODS *****//

};

