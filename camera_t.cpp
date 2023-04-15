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
	view = glm::translate(glm::mat4{ 1.0f }, position); // vec3 is the camera's position
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
	debuglog("moved to " << RD_VEC3_TO_STR(position));
}

void camera_t::rotate(GLfloat angle_degrees, const glm::vec3& axis)
{
	auto rads = glm::radians(angle_degrees);
	debuglog("rotation degrees to radians " << rads);
	glm::quat rotation_quat = glm::angleAxis(rads, axis);
	direction = glm::rotate(rotation_quat, direction);
	up = glm::rotate(rotation_quat, up);
	debuglog("rotation quaternion: " << RD_VEC3_TO_STR(direction));
	debuglog("new direction: " << RD_VEC3_TO_STR(direction));
	debuglog("new up: " << RD_VEC3_TO_STR(up));
}
void camera_t::rotate_roll(GLfloat angle_degrees) // Z
{
	debuglog("rotating roll on " << angle_degrees << "degrees");
	glm::vec3 axis = { 0.f, 0.f, 1.f };
	rotate(angle_degrees, axis);
}
void camera_t::rotate_pitch(GLfloat angle_degrees) // X
{
	debuglog("rotating pitch on " << angle_degrees << "degrees");
	glm::vec3 axis = { 1.f, 0.f, 0.f };
	rotate(angle_degrees, axis);
}
void camera_t::rotate_yaw(GLfloat angle_degrees) // Y
{
	debuglog("rotating yaw on " << angle_degrees << "degrees");
	glm::vec3 axis = { 0.f, 1.f, 0.f };
	rotate(angle_degrees, axis);
}

void camera_t::look_at(const glm::vec3& target)
{}

void camera_t::apply(
	shader_program_t& shader_program,
	raw_str proj_uniform_name,
	raw_str view_uniform_name)
{

	//glm::mat4 view = glm::translate(glm::mat4{ 1.0f }, position); // vec3 is the camera's position

	glm::mat4 view = glm::lookAt(position, position + direction, up);

	// this is a way to read camera's direction from view 
	// glm::vec3 dir{ view[2][0], view[2][1], view[2][2] };
	// infolog("look direction: " << RD_VEC3_TO_STR(dir));

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