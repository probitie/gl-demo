#include "event_system_t.h"

event_system_t::event_system_t(const window_t& win) : window_{ win.ptr() }
{
}

void event_system_t::poll()
{
	glfwPollEvents();
}

bool event_system_t::should_close_app()
{
	return glfwWindowShouldClose(window_);
}

void event_system_t::update_camera(camera_t& camera, GLfloat delta)
{
	float speed = 0.001;
	// Handles key inputs
	if (glfwGetKey(window_, GLFW_KEY_W) == GLFW_PRESS)
	{
		camera.move(speed * glm::vec3{ 0.f, 0.f, 1.f });
	}

}
