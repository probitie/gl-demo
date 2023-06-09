#pragma once
#include "camera_t.h"
#include "libs.h"
#include "window_t.h"

/**
 * \brief handles window events
 */
class event_system_t
{

public:

	event_system_t(const window_t& win);

	/**
	 * \brief parses user input
	 */
	void poll();

	/**
	 * \brief checks user input for closing the window
	 * \return if user sent an interruption to close the window
	 */
	bool should_close_app();

	// TODO change return type for passing vector or matrix
	/**
	 * \brief checks parsed user input for movement keys
	 */
	std::vector<int> get_camera_movement();

	// TODO make it as Observer pattern

	void update_camera(camera_t& camera, GLfloat delta);

private:
	/**
	 * \brief receive 99% of events from this window (maybe even 100%)
	 */
	GLFWwindow* window_;

	void reset_cursor_position()
	{
		glfwSetCursorPos(window_, 0, 0);
	};

};

