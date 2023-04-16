#include "event_system_t.h"

event_system_t::event_system_t(const window_t& win) : window_{ win.ptr() }
{
	// hide cursor in this project
	glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if(glfwRawMouseMotionSupported())
	{
		glfwSetInputMode(window_, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
	}

	/* TODO
	 * set cursor on 0.0 pos as default in constructor
	 *
	 * in each frame - get absolute position of cursor
	 * use it as an offset to rotate to
	 */

	reset_cursor_position();
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
	float speed = 0.008;
	float rotation_speed = 0.8;
	// Handles key inputs

	// TODO move_forward / backward / right / left + assert that move_on param is greater than 0
	if (glfwGetKey(window_, GLFW_KEY_W) == GLFW_PRESS)
	{
		camera.move(speed * glm::vec3{ 0.f, 0.f, 1.f });
	}
	if (glfwGetKey(window_, GLFW_KEY_A) == GLFW_PRESS)
	{
		camera.move(speed * glm::vec3{ 1.f, 0.f, 0.f });
	}
	if (glfwGetKey(window_, GLFW_KEY_S) == GLFW_PRESS)
	{
		camera.move(speed * -glm::vec3{ 0.f, 0.f, 1.f });
	}
	if (glfwGetKey(window_, GLFW_KEY_D) == GLFW_PRESS)
	{
		camera.move(speed * -glm::vec3{ 1.f, 0.f, 0.f });
	}

	// handles mouse
	double xpos{}, ypos{};

	glfwGetCursorPos(window_, &xpos, &ypos);
	infolog("mouse x " << xpos << "; y " << ypos);

	float pitch_angle = rotation_speed * ypos * delta; //y
	float yaw_angle = -rotation_speed * xpos * delta; //x

	infolog("pitch " << pitch_angle << "; yaw " << yaw_angle);

	camera.rotate_pitch(pitch_angle); 
	camera.rotate_yaw(yaw_angle);

	reset_cursor_position();
}
