#pragma once
#include "libs.h"

/**
 * \brief handles window events
 */
class eventer
{

public:
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
};

