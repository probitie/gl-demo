
#include "error.h"
#include "libs.h"

#include "eventer.h"
#include "mesh.h"

#include "renderer.h"
#include "resourcer.h"
#include "shader_program.h"
#include "window.h"




int main()
{
	// TODO commented here functions are not implemented yet
	const window current_window{ WINDOW_W , WINDOW_H, "openGL demo"};
	renderer render{ current_window };
	//resourcer resource_manager{};

	std::vector<vertex> vertices = {
		// bottom left
		{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
		// top left
		{glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
		// top right
		{glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
		// bottom right
		{glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)}
	};

	std::vector<vertex> cube_vertices = {
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

	std::vector<vertex> pyro_vertices = {
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

	//std::vector<mesh> msh{
	//	{vertices, indices}
	//};
	std::vector<material> mat{};

	//model a_model{std::move(msh), std::move(mat)};//resource_manager.load_model("");
	//const mesh light_cube = resource_manager.load_mesh(LIGHT_CUBE_MESH);
	//const mesh floor = resource_manager.load_mesh(FLOOR_MESH);

	//render.add(a_model);
	//render.add(light_cube);
	//render.add(floor);


	raw_str vs = R"(D:\projects\gl\YoutubeOpenGL\vertex.vs)";
	raw_str fs = R"(D:\projects\gl\YoutubeOpenGL\fragment.fs)";

	shader_program shader{vs, fs};




    // 3d matrices, a spinning cube on the screen
	// moving camera, camera object
	// refactor code



	eventer events{ current_window };

	vao vao_{};
	vao_.bind();

	vbo vbo_(cube_vertices);
	ebo ebo_(cube_indices);

	vao_.set_attribute(vbo_, 0, 3, GL_FLOAT, sizeof(vertex), offsetof(vertex, position));
	vao_.set_attribute(vbo_, 1, 3, GL_FLOAT, sizeof(vertex), offsetof(vertex, color));

	vao_.unbind();
	vbo_.unbind();
	ebo_.unbind();

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

		// scene.update() // TODO do i need this ?? | scene is like a model but with multiple meshes/materials in tree order
		render.draw_context();
		//a_model.render();

		shader.activate();

		auto model_coords = glm::mat4(1.0f);
		auto world_coords = glm::mat4(1.0f);
		auto projection_coords = glm::mat4(1.0f);

		model_coords = glm::rotate(model_coords, glm::radians(rotation), glm::vec3(.0f, 1.f, .0f));
		world_coords = glm::translate(world_coords, glm::vec3(0.0f, .0f, -2.0f));
		projection_coords = glm::perspective(glm::radians(45.f), (float)WINDOW_W / WINDOW_H, 0.1f, 100.f);

		int model_loc, world_loc, projection_loc;

		DBG(model_loc = glGetUniformLocation(shader.ID, "model"));
		DBG(world_loc = glGetUniformLocation(shader.ID, "world"));
		DBG(projection_loc = glGetUniformLocation(shader.ID, "proj"));

		DBG(glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model_coords)));
		DBG(glUniformMatrix4fv(world_loc, 1, GL_FALSE, glm::value_ptr(world_coords)));
		DBG(glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(projection_coords)));
		vao_.bind();
		DBG(glDrawElements(GL_TRIANGLES, ebo_.get_indices_count(), GL_UNSIGNED_INT, 0));
		vao_.unbind();

		render.swap_buffers();
		events.poll();
		//render.fov.move(events.get_camera_movement());
	}
	
	return 0;
}
