#include "eventer.h"
#include "libs.h"
#include "mesh.h"

#include "renderer.h"
#include "resourcer.h"

#define LIGHT_CUBE_MESH "models/light_cube.gltf"
#define FLOOR_MESH "models/floor.gltf"

int main()
{

	renderer render{};
	resourcer resource_manager{};

	mesh light_cube = resource_manager.load_mesh(LIGHT_CUBE_MESH);
	mesh floor = resource_manager.load_mesh(FLOOR_MESH);

	render.add(light_cube);
	render.add(floor);

	eventer events{};
	while( ! events.should_close_app() )
	{
		events.poll();
		render.fov.move(events.get_camera_movement());
		render.draw_context();
		render.swap_buffers();
	}
	
	return 0;
}
