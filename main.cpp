
#include "error.h"
#include "libs.h"

#include "event_system_t.h"
#include "mesh_t.h"

#include "render_system_t.h"
#include "resource_system_t.h"
#include "shader_program_t.h"
#include "window_t.h"




int main()
{
	// TODO commented here functions are not implemented yet
	const window_t current_window{ WINDOW_W , WINDOW_H, "openGL demo"};


	render_system_t render{ current_window };
	resource_system_t resources{};

	// move this to resources implementation (it will be like a mock object for now)
	
	std::vector<vertex_t> vertices = {
		// bottom left
		{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
		// top left
		{glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
		// top right
		{glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
		// bottom right
		{glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)}
	};
	std::vector<vertex_t> cube_vertices = {
		// bottom face
		{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 0.0f)},
		{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f)},
		{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.0f, 1.0f)},
		{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 1.0f)},
		// top face
		{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 0.0f)},
		{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 1.0f, 1.0f)},
		{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.5f, 0.5f, 0.0f)},
		{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 1.0f, 0.5f)}
	};
	std::vector<GLuint> indices = {
		0, 1, 2, // first triangle
		2, 3, 0  // second triangle
	};
	std::vector<GLuint> cube_indices = {
		// bottom face
		0, 1, 2,
		2, 3, 0,
		// top face
		4, 5, 6,
		6, 7, 4,
		// left face
		0, 4, 7,
		7, 3, 0,
		// right face
		1, 5, 6,
		6, 2, 1,
		// front face
		0, 1, 5,
		5, 4, 0,
		// back face
		3, 2, 6,
		6, 7, 3
	};
	std::vector<vertex_t> pyro_vertices = {
	{glm::vec3(-0.5f, 0.0f, 0.5f), glm::vec3(0.83f, 0.70f, 0.44f)},
	{glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f)},
	{glm::vec3(0.5f, 0.0f, -0.5f), glm::vec3(0.83f, 0.70f, 0.44f)},
	{glm::vec3(0.5f, 0.0f, 0.5f), glm::vec3(0.83f, 0.70f, 0.44f)},
	{glm::vec3(0.0f, 0.8f, 0.0f), glm::vec3(0.92f, 0.86f, 0.76f)}
	};
	std::vector<GLuint> pyro_indices = {
		0, 1, 2,
		0, 2, 3,
		0, 1, 4,
		1, 2, 4,
		2, 3, 4,
		3, 0, 4
	};
	
	//mesh_t cube = resources.load_mesh(RD_CUBE);
	material_t mat = resources.load_material(RD_DEFAULT);

	event_system_t events{ current_window };

	camera_t camera{WINDOW_W, WINDOW_H, glm::vec3(0.0f, 0.0f, -2.0f)};
	// todo add camera.look_at(mesh) but now for model matrix or origin idk

	// TODO I cannot set up mesh object now because vao should be in main function
	vao_t vao{};
	vao.bind();
	vbo_t vbo(std::move(cube_vertices));
	ebo_t ebo(std::move(cube_indices));
	vao.set_attribute(vbo, 0, 3, GL_FLOAT, sizeof(vertex_t), offsetof(vertex_t, position));
	vao.set_attribute(vbo, 1, 3, GL_FLOAT, sizeof(vertex_t), offsetof(vertex_t, color));
	vao.unbind();
	vbo.unbind();
	ebo.unbind();
	
	GLfloat rotation{};



	while( ! events.should_close_app() )
	{
		render.start_frame();

		auto delta = render.get_time_delta();

		events.update_camera(camera, delta);
		//rotation += 20 * delta;
		//camera.move({ 0.1f * delta, 0.f, 0.f });
		//camera.rotate_roll( 30*delta);
		//camera.rotate_pitch( 30*delta);
		//camera.rotate_yaw( 30*delta);
		mat.enable();
		// TODO pixels per second as a common speed metric
		render.draw_context();

		glm::mat4 model_coords = glm::mat4(1.0f);
		model_coords = glm::rotate(model_coords, glm::radians(rotation), glm::vec3(.0f, 1.f, .0f));

		//glm::mat4 view_coords = glm::mat4(1.0f);
		//view_coords = glm::translate(view_coords, glm::vec3(0.0f, 0.0f, -2.0f)); // vec3 is the camera's position

		//glm::mat4 projection_coords = glm::perspective(glm::radians(45.f), (float)WINDOW_W / WINDOW_H, 0.1f, 100.f);

		int model_loc, view_loc, projection_loc;

		DBG(model_loc = glGetUniformLocation(mat.shader_program.ID, "model"));
		//DBG(view_loc = glGetUniformLocation(mat.shader_program.ID, "view"));
		//DBG(projection_loc = glGetUniformLocation(mat.shader_program.ID, "proj"));

		DBG(glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model_coords)));
		//DBG(glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view_coords)));
		//DBG(glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(projection_coords)));

		camera.apply(mat.shader_program);

		vao.bind();
		DBG(glDrawElements(GL_TRIANGLES, ebo.get_indices_count(), GL_UNSIGNED_INT, 0));
		vao.unbind();

		render.swap_buffers();
		events.poll();
		render.end_frame();
	}
	
	return 0;
}
