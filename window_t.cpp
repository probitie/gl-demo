#include "window_t.h"


#include "error.h"

window_t::window_t(const i16 width, const i16 height, raw_str title)
	: width_{ width }, height_{ height }
{
	glfwInit();

	window_pointer = glfwCreateWindow(width_, height_, title, NULL, NULL);

	// Error check if the window_t fails to create
	CHECK_NOT_NULLPTR(window_pointer, "GLFW: failed to create a window_t (did you init GLFW?)");
}

window_t::~window_t()
{
	// Error check if the window_t somehow became nullptr before the destructor
	CHECK_NOT_NULLPTR(window_pointer, "GLFW: failed to destruct a window_t - it seems to be already destructed");

	glfwDestroyWindow(window_pointer);
}

GLFWwindow* window_t::ptr() const
{
    return window_pointer;
}
