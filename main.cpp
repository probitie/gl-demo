
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

	std::vector<GLuint> indices = {
		0, 1, 2, // first triangle
		2, 3, 0  // second triangle
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

	/*float vertices[] = {
    // positions         // colors
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
}; */

	raw_str vs = "D:\\projects\\gl\\YoutubeOpenGL\\vertex.vs";
	raw_str fs = "D:\\projects\\gl\\YoutubeOpenGL\\fragment.fs";

	shader_program shader{vs, fs};




	// debug -> DBG(glBindBuffer(...))
    // 3d matrices, a cube on a screen
	// moving camera, camera object
	// refactor code



	eventer events{ current_window };

	vao vao_{};
	vao_.bind();

	vbo vbo_(vertices);
	ebo ebo_(indices);

	vao_.set_attribute(vbo_, 0, 3, GL_FLOAT, sizeof(vertex), offsetof(vertex, position));
	vao_.set_attribute(vbo_, 1, 3, GL_FLOAT, sizeof(vertex), offsetof(vertex, color));

	vao_.unbind();
	vbo_.unbind();
	ebo_.unbind();

	debuglog("test debug");
	infolog("test info");
	errorlog("test error");

	while( ! events.should_close_app() )
	{
		// scene.update() // TODO do i need this ?? | scene is like a model but with multiple meshes/materials in tree order
		render.draw_context();
		//a_model.render();

		shader.activate();
		vao_.bind();
		DBG(glDrawElements(GL_TRIANGLES, ebo_.get_indices_count(), GL_INT, 0));
		vao_.unbind();

		render.swap_buffers();
		events.poll();
		//render.fov.move(events.get_camera_movement());
	}
	
	return 0;
}
