#pragma once

// TODO rewrite it for my logger library and std::runtime_error
#define CHECK_NOT_NULLPTR(ptr, msg)\
	if ((ptr) == nullptr)\
	{\
		errorlog("nullptr: " << msg);\
		glfwTerminate();\
		throw std::runtime_error(msg);\
	}
