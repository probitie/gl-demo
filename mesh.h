#pragma once
#include <vector>
#include <glad/glad.h>

#include "ebo.h"
#include "vao.h"
#include "vertex.h"


class mesh
{
public:

	mesh(const std::vector<vertex>& vertices, const std::vector<GLuint>& indices)
		: m_vao(vertices), m_ebo(indices)
	{ /* empty */ }

	~mesh() = default;

	[[nodiscard]] GLsizei get_index_count() const;
	void render() const;

private:
	vao m_vao;
	ebo m_ebo;
};

