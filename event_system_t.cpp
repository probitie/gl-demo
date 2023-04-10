#include "event_system_t.h"

void event_system_t::poll()
{
	glfwPollEvents();
}

bool event_system_t::should_close_app()
{
	return glfwWindowShouldClose(window_);
}
