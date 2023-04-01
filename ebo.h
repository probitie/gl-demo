#pragma once
#include <vector>
#include <GL/gl.h>

class ebo
{
public:
	explicit ebo(const std::vector<GLuint>& indices);
	void bind() const;
	void unbind() const;
	[[nodiscard]] GLsizei get_indices_count() const;
};

