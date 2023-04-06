#pragma once

#include "libs.h"


#include <stdexcept>
#include "logger.h"
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

/**
 * \brief error name of a gl error macro
 * \param error gl error code
 * \return error name
 */
std::string rd_get_gl_error_name(GLenum error);

/**
 * \brief check for all gl errors
 * \param place exact place in the code (file/function/line) 
 * \param context - before or after api call or additional info
 * \param func_name name of the function (that is important for a context)
 *        there are two main context cases - check errors before api call
 *        and check errors after api call
 * \param terminate_on_error should it break program if there are one or more errors
 */
void rd_check_errors(const std::string& place, const std::string& context,const std::string & func_name, bool terminate_on_error);



#ifdef RD_TERMINATE_ON_ERROR
constexpr bool rd_terminate_on_error = true;
#else
constexpr bool rd_terminate_on_error = false;
#endif

/**
 * \brief adds error checking to any gl api function
 * \param gl_api_call your function with params
 */
#define RD_DBG(gl_api_call) \
{ \
    rd_check_errors(RD_GET_PLACE_IN_CODE(1), "Before", #gl_api_call, rd_terminate_on_error); \
    gl_api_call; \
    rd_check_errors(RD_GET_PLACE_IN_CODE(-1), "After", #gl_api_call, rd_terminate_on_error); \
}

/**
 * \brief a shortcut for RD_DBG
 */
#define DBG RD_DBG
