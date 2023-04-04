#include "eventer.h"
#include "libs.h"
#include "mesh.h"

#include "renderer.h"
#include "resourcer.h"
#include "window.h"


int main()
{
	// TODO commented here functions are not implemented yet
	const window current_window{ WINDOW_W , WINDOW_H, "openGL demo"};
	renderer render{ current_window };
	resourcer resource_manager{};

	model a_model = resource_manager.load_model("");
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

	eventer events{ current_window };
	while( ! events.should_close_app() )
	{
		// scene.update() // TODO do i need this ?? | scene is like a model but with multiple meshes/materials in tree order
		render.draw_context();
		a_model.render();
		render.swap_buffers();
		events.poll();
		//render.fov.move(events.get_camera_movement());
	}
	
	return 0;
}
