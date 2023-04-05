#pragma once

#include "libs.h"


#include <stdexcept>
#include "logger.h"
#include "defines.h"
#include <sstream>

#define RD_ASSERT(condition, msg)\
	if(!(condition))\
	{\
		\
			errorlog(msg); \
			glfwTerminate(); \
			std:abort();\
	}

#define CHECK_NOT_NULLPTR(ptr, msg)\
	RD_ASSERT((ptr) != nullptr, (msg))
