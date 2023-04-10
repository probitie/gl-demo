
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

	mesh_t mesh = resources.load_mesh(RD_CUBE);
	material_t material = resources.load_material(RD_DEFAULT);

	event_system_t events{ current_window };

	// todo create camera class and move time count nad other things to render class


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

		material.enable();

		auto model_coords = glm::mat4(1.0f); // world
		auto world_coords = glm::mat4(1.0f); // camera
		auto projection_coords = glm::mat4(1.0f); // perspective

		model_coords = glm::rotate(model_coords, glm::radians(rotation), glm::vec3(.0f, 1.f, .0f));
		world_coords = glm::translate(world_coords, glm::vec3(0.0f, .0f, -2.0f)); // vec3 is the camera's position
		projection_coords = glm::perspective(glm::radians(45.f), (float)WINDOW_W / WINDOW_H, 0.1f, 100.f);

		int model_loc, world_loc, projection_loc;

		
		DBG(model_loc = glGetUniformLocation(material.shader_program.ID, "model_t"));
		DBG(world_loc = glGetUniformLocation(material.shader_program.ID, "world"));
		DBG(projection_loc = glGetUniformLocation(material.shader_program.ID, "proj"));

		DBG(glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model_coords)));
		DBG(glUniformMatrix4fv(world_loc, 1, GL_FALSE, glm::value_ptr(world_coords)));
		DBG(glUniformMatrix4fv(projection_loc, 1, GL_FALSE, glm::value_ptr(projection_coords)));
		
		mesh.render();

		render.swap_buffers();
		events.poll();
		//render.fov.move(events.get_camera_movement());
	}
	
	return 0;
}
