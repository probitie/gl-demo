#include "error.h"

std::string rd_get_gl_error_name(const GLenum error)
{
	switch (error) {
	case GL_NO_ERROR:
		return "GL_NO_ERROR";
	case GL_INVALID_ENUM:
		return "GL_INVALID_ENUM";
	case GL_INVALID_VALUE:
		return "GL_INVALID_VALUE";
	case GL_INVALID_OPERATION:
		return "GL_INVALID_OPERATION";
	case GL_OUT_OF_MEMORY:
		return "GL_OUT_OF_MEMORY";
	case GL_INVALID_FRAMEBUFFER_OPERATION:
		return "GL_INVALID_FRAMEBUFFER_OPERATION";
	default:
		return "Unknown error";
	}
}


void rd_check_errors(const std::string& place, const std::string& context, const std::string& func_name, bool terminate_on_error)
{
	const GLenum init_error = glGetError();
	GLenum error = init_error;
	while (error != GL_NO_ERROR) {
		errorlog("OpenGL error [ " << context << " " << func_name << " ]: (error code) " \
			<< error << " - " << rd_get_gl_error_name(error) \
			<< " in " << place);
		error = glGetError();
	}

	if (init_error != GL_NO_ERROR && terminate_on_error) {
		std::terminate();
	}
}