#pragma once
#include <stdexcept>
#include "logger.h"
#include "libs.h"
#include "defines.h"
#include <sstream>

#define ASSERT(condition, msg)\
	if(!(condition))\
	{\
		\
			errorlog(msg); \
			glfwTerminate(); \
			std:abort();\
	}

#define CHECK_NOT_NULLPTR(ptr, msg)\
	ASSERT((ptr) == nullptr)
