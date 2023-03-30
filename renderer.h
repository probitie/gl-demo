#pragma once
#include "camera.h"
#include "mesh.h"
#include "defines.h"
#include "window.h"


/*
 *
 *

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		
		// Tell OpenGL which Shader Program we want to use
		
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
 */


/**
 * \brief handles rendering on a display
 */
class renderer
{
public:

	//***** FIELDS *****//

	// TODO is unused for now, glViewPort is set independently
	/**
	 * \brief camera settings
	 */
	camera fov;
	//***** ****** *****//



	//***** METHODS *****//

	renderer(const window& win) noexcept(false);

	~renderer() noexcept(false);

	/**
	 * \brief adds a mesh to the context of render pipeline
	 * \param mesh an object to be rendered on a display (if it in camera's fov)
	 */
	void add(const mesh& mesh);

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

