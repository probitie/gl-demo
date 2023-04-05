#pragma once

#include "libs.h"

#include "defines.h"

class window
{
public:
	window(const i16 width, const i16 height, raw_str title);
	~window();

	GLFWwindow* ptr() const;

	[[nodiscard]] i16 width()  const { return width_; }
	[[nodiscard]] i16 height() const { return height_; }

	/**
	 * \brief tells openGL to use this window as an output
	 *
	 * you need to call it before loading openGL, otherwise openGL crashes on nullptr
	 */
	void activate() const { glfwMakeContextCurrent(window_pointer); }

private:
	GLFWwindow* window_pointer;
	i16 width_;
	i16 height_;
};

