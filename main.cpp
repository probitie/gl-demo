#include "eventer.h"
#include "libs.h"
#include "mesh.h"

#include "renderer.h"
#include "resourcer.h"

#define LIGHT_CUBE_MESH "models/light_cube.gltf"
#define FLOOR_MESH "models/floor.gltf"

int main()
{
	// TODO commented here functions that are not implemented yet
	renderer render{};
	//resourcer resource_manager{};

	//const mesh light_cube = resource_manager.load_mesh(LIGHT_CUBE_MESH);
	//const mesh floor = resource_manager.load_mesh(FLOOR_MESH);

	//render.add(light_cube);
	//render.add(floor);

	//eventer events{};
	while( 1 )//! events.should_close_app() )
	{
		//events.poll();
		//render.fov.move(events.get_camera_movement());
		render.draw_context();
		render.swap_buffers();
	}
	
	return 0;
}
