#pragma once
#include <vector>
#include <GL/gl.h>
#include "libs.h"

class ebo
{
public:
	explicit ebo(const std::vector<GLuint>& indices);
	void bind() const;
	void unbind() const;
	[[nodiscard]] GLsizei get_indices_count() const;

private:
	GLuint id;
	size_t vertices_count;
};

