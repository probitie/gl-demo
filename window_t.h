#pragma once

#include "libs.h"

#include "defines.h"

class window_t
{
public:
	window_t(const i16 width, const i16 height, raw_str title);

	window_t(const window_t&) = delete;
	window_t(window_t&&) = delete;
	window_t& operator=(const window_t&) = delete;
	window_t& operator=(window_t&&) = delete;


	~window_t();

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

