#include "renderer.h"

#include "error.h"
#include "logger.h"

renderer::renderer(const window& win)
	: window_(win.ptr())
{
	// do not forget to init glfw

	// set openGL API version exactly 3.3 CORE PROFILE
	// this is minimal version to have access to modern functions
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// set this window as main for opengl
	win.activate();

	//Load GLAD so it configures OpenGL
	gladLoadGL();

	// TODO move window parameters to constructor or move window creation to another block of code (maybe no)
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = window_width, y = window_height

	glViewport(0, 0, win.width(), win.height());

}

renderer::~renderer() noexcept(false)
{
	// Terminate GLFW before ending the program
	glfwTerminate();
}

void renderer::draw_context()
{
	// Specify the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clean the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
}

void renderer::swap_buffers() const
{
	glfwSwapBuffers(window_);
}
