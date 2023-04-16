#include "camera_t.h"

camera_t::camera_t(GLint width, GLint height, glm::vec3 position)
	:	view{ 1.f },
		proj{ 1.f },
		position{ position },
		direction{ 0.f, 0.f, 1.f},
		up{ 0.f, 1.f, 0.f },
		vertical_perspective_degrees{ 45.f },
		zoom{ 1.f},
		width{ width },
		height{ height },
		max_clip{ 100.f },
		min_clip{ .1f }
{
	view = glm::translate(glm::mat4{ 1.0f }, position);
	proj = glm::perspective(
		glm::radians(vertical_perspective_degrees),
		static_cast<GLfloat>(width) / height,
		min_clip,
		max_clip
	);
}

void camera_t::go(const glm::vec3& destination)
{}

void camera_t::move(const glm::vec3& on)
{
	position += on;
}

void camera_t::move_forward(const float speed)
{
	position += direction * speed;
}

void camera_t::move_backward(const float speed)
{
	position -= direction * speed;
}

void camera_t::move_left(const float speed)
{
	auto left = get_left_vector();
	position += left * speed;
}

glm::vec3 camera_t::get_left_vector()
{
	glm::vec3 left = glm::cross(up, direction);
	left = glm::normalize(left);
	return left;
}

void camera_t::move_right(const float speed)
{
	auto left = get_left_vector();
	position -= left * speed;
}

void camera_t::rotate(GLfloat angle_degrees, const glm::vec3& axis)
{
	auto rads = glm::radians(angle_degrees);
	glm::quat rotation_quat = glm::angleAxis(rads, axis);
	direction = glm::rotate(rotation_quat, direction);
	up = glm::rotate(rotation_quat, up);
}
void camera_t::rotate_roll(GLfloat angle_degrees) // Z
{
	debuglog("rotating roll on " << angle_degrees << "degrees");
	rotate(angle_degrees, direction);
}
void camera_t::rotate_pitch(GLfloat angle_degrees) // rotate around X 
{
	debuglog("rotating pitch on " << angle_degrees << "degrees");
	rotate(angle_degrees, get_left_vector());
}
void camera_t::rotate_yaw(GLfloat angle_degrees) // rotate around Y 
{
	debuglog("rotating yaw on " << angle_degrees << "degrees");
	rotate(angle_degrees, {0.f, 1.f, 0.f} /*perpendicular to horizon*/);
}

void camera_t::look_at(const glm::vec3& target)
{}

void camera_t::apply(
	shader_program_t& shader_program,
	raw_str proj_uniform_name,
	raw_str view_uniform_name)
{
	glm::mat4 view = glm::lookAt(position, position + direction, up);
	glm::mat4 proj = glm::perspective(
		glm::radians(vertical_perspective_degrees),
		static_cast<GLfloat>(width) / height,
		min_clip,
		max_clip
	);

	// pushing uniforms to the shader
	int view_loc, projection_loc;
	DBG(view_loc = glGetUniformLocation(shader_program.ID, view_uniform_name));
	DBG(projection_loc = glGetUniformLocation(shader_program.ID, proj_uniform_name));

	DBG(glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view)));
	DBG(glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(proj)));
}

void camera_t::set_up_direction(const glm::vec3& new_up)
{}