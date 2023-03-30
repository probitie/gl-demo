#include "eventer.h"
#include "libs.h"
#include "mesh.h"

#include "renderer.h"
#include "resourcer.h"
#include "window.h"


int main()
{
	// TODO commented here functions are not implemented yet
	window current_window{ WINDOW_W , WINDOW_H, "openGL demo"};
	renderer render{ current_window };
	//resourcer resource_manager{};

	//const mesh light_cube = resource_manager.load_mesh(LIGHT_CUBE_MESH);
	//const mesh floor = resource_manager.load_mesh(FLOOR_MESH);

	//render.add(light_cube);
	//render.add(floor);

	eventer events{ current_window };
	while( ! events.should_close_app() )
	{
		render.draw_context();
		render.swap_buffers();
		events.poll();
		//render.fov.move(events.get_camera_movement());
	}
	
	return 0;
}
