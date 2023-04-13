#pragma once
#include "libs.h"

#include "event_system_t.h"

/**
 * \brief camera params
 */
class camera_t
{
public:
	/*
	 * we need
	 * current positon
	 * up vector
	 * direction vector
	 * zoom
	 * fov
	 * min max distance
	 *
	 * also move the camera, rotate it and get VP matrix
	 */
	void move(std::vector<int> camera_movement);
};

