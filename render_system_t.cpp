#include "render_system_t.h"

#include "error.h"
#include "logger.h"

render_system_t::render_system_t(const window_t& win)
	: window_(win.ptr())
{
	// do not forget to init glfw

	// set openGL API version exactly 3.3 CORE PROFILE
	// this is minimal version to have access to modern functions
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// set this window_t as main for opengl
	win.activate();

	//Load GLAD so it configures OpenGL
	gladLoadGL();

	// TODO move window_t parameters to constructor or move window_t creation to another block of code (maybe no)
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = window_width, y = window_height

	DBG(glViewport(0, 0, win.width(), win.height()));

}

render_system_t::~render_system_t() noexcept(false)
{
	// Terminate GLFW before ending the program
	glfwTerminate();
}

void render_system_t::draw_context()
{
	// Specify the color of the background
	DBG(glClearColor(0.07f, 0.13f, 0.17f, 1.0f));
	// Clean the back buffer and assign the new color to it
	DBG(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

	// TODO draw here all models like for(model_t in models) -> model_t.render()
}

void render_system_t::swap_buffers() const
{
	glfwSwapBuffers(window_);
}
