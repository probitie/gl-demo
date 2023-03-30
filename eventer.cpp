#include "eventer.h"

void eventer::poll()
{
	glfwPollEvents();
}

bool eventer::should_close_app()
{
	return glfwWindowShouldClose(window_);
}
