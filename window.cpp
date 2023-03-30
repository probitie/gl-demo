#include "window.h"


#include "error.h"

window::window(const i16 width, const i16 height, raw_str title)
	: width_{ width }, height_{ height }
{
	glfwInit();

	window_pointer = glfwCreateWindow(width_, height_, title, NULL, NULL);

	// Error check if the window fails to create
	CHECK_NOT_NULLPTR(window_pointer, "GLFW: failed to create a window (did you init GLFW?)");
}

GLFWwindow* window::ptr() const
{
    return window_pointer;
}