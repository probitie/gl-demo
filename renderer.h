#pragma once
#include "camera.h"
#include "mesh.h"
#include "defines.h"


/*
 *
 * // Initialize GLFW

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(800, 800, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, 800, 800);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
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

	renderer(const i16 window_width, const i16 window_height) noexcept(false);

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
	void swap_buffers();

private:

	//***** FIELDS *****//

	/**
	 * \brief current window being drawn.
	 * Do not change it,
	 * it is used once in the constructor and once in the destructor
	 */
	GLFWwindow* _window;

	//***** ****** *****//


	//***** METHODS *****//
	/**
	 * \brief creates a window and sets it as current context for OpenGL
	 */
	void init_window(const i16 width, const i16 height);

};

