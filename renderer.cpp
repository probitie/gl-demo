#include "renderer.h"

#include "error.h"
#include "logger.h"

renderer::renderer(const i16 window_width, const i16 window_height) noexcept(false)
	: _window(nullptr)
{
	glfwInit();

	// set openGL API version exactly 3.3 CORE PROFILE
	// this is minimal version to have access to modern functions
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// create and set a window
	init_window(window_width, window_height);

	//Load GLAD so it configures OpenGL
	gladLoadGL();

	// TODO move window parameters to constructor or move window creation to another block of code (maybe no)
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = window_width, y = window_height
	glViewport(0, 0, window_width, window_height);

}

renderer::~renderer() noexcept(false)
{
	// Error check if the window somehow became nullptr before the destructor
	CHECK_NOT_NULLPTR(_window, "GLFW: failed to destruct a window - it seems to be already destructed");

	// Delete window before ending the program
	glfwDestroyWindow(_window);

	// Terminate GLFW before ending the program
	glfwTerminate();
}

void renderer::draw_context()
{
}

void renderer::swap_buffers()
{
}

void renderer::init_window(const i16 width, const i16 height)
{
	_window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);

	// Error check if the window fails to create
	CHECK_NOT_NULLPTR(_window, "GLFW: failed to create a window");

	// Introduce the window into the current context
	glfwMakeContextCurrent(_window);
}
