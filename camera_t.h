#pragma once
#include "libs.h"
#include "shader_program_t.h"

/**
 * \brief camera params
 */
class camera_t
{
public:
	/**
	 * \brief creates a camera and initializes it's fields
	 * \param width camera's width. commonly just the value of the window or the viewport
	 * \param height camera's height. commonly just the value of the window or the viewport
	 * \param position where camera should be, just a point
	 */
	camera_t(GLint width, GLint height, glm::vec3 position = {0.f, 0.f, 0.f});

	/**
	 * \brief moves camera to specific point
	 * \param destination vector/point to go to
	 */
	void go(const glm::vec3& destination);

	/**
	 * \brief moves camera on a specified value
	 * \param on vector that shows how much camera should move and on which direction
	 */
	void move(const glm::vec3& on);


	//speed > 0
	void move_forward(const float speed);
	void move_backward(const float speed);
	void move_left(const float speed);
	glm::vec3 get_left_vector();
	void move_right(const float speed);


	void rotate_roll(GLfloat angle);
	void rotate_pitch(GLfloat angle);
	void rotate_yaw(GLfloat angle);

	void look_at(const glm::vec3& target);

	/**
	 * \brief the up vector. commonly it looks at the positive up axis, where should be the sky
	 * \param new_up 1-vector like (0 1 0), but it actually can be anything
	 */
	void set_up_direction(const glm::vec3& new_up);

	/**
	 * \brief resolves VP matrix uniforms in a shader.
	 *	Should be called in a loop to apply camera movement in runtime
	 *
	 *        After applying it the shader will draw
	 *        the object on a screen with a perspective
	 *        of this camera (you also need to apply M
	 *        matrix (object's origin point) and other uniforms
	 *        but this method doesn't give a **** about that)
	 *
	 * \param shader_program shader program (should be enabled)
	 * \param proj_uniform_name name of a projection matrix uniform
	 * \param view_uniform_name name of a view matrix uniform
	 */
	void apply(
		shader_program_t& shader_program,
		raw_str proj_uniform_name = "proj",
		raw_str view_uniform_name = "view"
	);



private:
	glm::mat4 view;
	glm::mat4 proj;

	glm::vec3 position;
	glm::vec3 direction;
	glm::vec3 up;

	// commonly 45 - 90 degrees
	GLfloat vertical_perspective_degrees;

	GLfloat zoom;

	// fov
	GLint width;
	GLint height;

	GLfloat max_clip;
	GLfloat min_clip;


	/// METHODS

	/**
	 * \brief rotates camera on specific angle around an axis
	 * \param angle angle to turn
	 * \param axis any vector (will be normalized)
	 */
	void rotate(GLfloat angle, const glm::vec3& axis);

};

