
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
	
	const mesh_t cube = resources.load_mesh(RD_CUBE);
	const material_t mat = resources.load_material(RD_DEFAULT);

	// move to resources load_material and use RD_V_SHADER etc
	//shader_program_t shader{vs, fs};

	event_system_t events{ current_window };

	// move to mesh class
	
	vao_t vao{};
	vao.bind();
	vbo_t vbo(std::move(cube_vertices));
	ebo_t ebo(std::move(cube_indices));
	vao.set_attribute(vbo, 0, 3, GL_FLOAT, sizeof(vertex_t), offsetof(vertex_t, position));
	vao.set_attribute(vbo, 1, 3, GL_FLOAT, sizeof(vertex_t), offsetof(vertex_t, color));
	vao.unbind();
	vbo.unbind();
	ebo.unbind();
	


	// todo create camera class and move time count nad other things to render class

	shader_program_t shader{ RD_V_SHADER_PATH, RD_F_SHADER_PATH };
	// timer for rotation
	float rotation{};
	double prevTime = glfwGetTime();

	// Enable depth testing
	DBG(glEnable(GL_DEPTH_TEST));
	while( ! events.should_close_app() )
	{
		// Simple timer
		double crntTime = glfwGetTime();
		if (crntTime - prevTime >= 1 / 30)
		{
			rotation += 0.1f;
			prevTime = crntTime;
		}

		// move camera VP matrices to camera class. Move applying camera to objects to render class

		// scene.update() // TODO do i need this ?? | scene is like a model_t but with multiple meshes/materials in tree order
		render.draw_context();
		//a_model.render();

		shader.activate();

		glm::mat4 model_coords = glm::mat4(1.0f);
		model_coords = glm::rotate(model_coords, glm::radians(rotation), glm::vec3(.0f, 1.f, .0f));

		glm::mat4 view_coords = glm::mat4(1.0f);
		view_coords = glm::translate(view_coords, glm::vec3(0.0f, 0.0f, -2.0f)); // vec3 is the camera's position

		glm::mat4 projection_coords = glm::perspective(glm::radians(45.f), (float)WINDOW_W / WINDOW_H, 0.1f, 100.f);

		int model_loc, view_loc, projection_loc;

		DBG(model_loc = glGetUniformLocation(shader.ID, "model"));
		DBG(view_loc = glGetUniformLocation(shader.ID, "view"));
		DBG(projection_loc = glGetUniformLocation(shader.ID, "proj"));

		DBG(glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model_coords)));
		DBG(glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view_coords)));
		DBG(glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(projection_coords)));
		vao.bind();
		DBG(glDrawElements(GL_TRIANGLES, ebo.get_indices_count(), GL_UNSIGNED_INT, 0));
		vao.unbind();

		render.swap_buffers();
		events.poll();
		//render.fov.move(events.get_camera_movement());
	}
	
	return 0;
}
