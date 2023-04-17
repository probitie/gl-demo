
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
	
	/*std::vector<vertex_t> vertices = {
		// bottom left
		{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
		// top left
		{glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
		// top right
		{glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
		// bottom right
		{glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)}
	};*/
	std::vector<vertex_t> cube_vertices = {
		// 
		{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.f, 0.f)}, //tl
		{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.f, 1.f)},  //bl
		{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.f, 1.f)},   //tr
		{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(1.f, 0.f)},  //br
		// 
		{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(0.f, 0.f)},
		{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(0.f, 1.f)},
		{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.5f, 0.5f, 0.0f), glm::vec2(1.f, 1.f)},
		{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.0f, 1.0f, 0.5f), glm::vec2(1.f, 0.f)}
	};
	/*std::vector<GLuint> indices = {
		0, 1, 2, // first triangle
		2, 3, 0  // second triangle
	};*/
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
	/*std::vector<vertex_t> pyro_vertices = {
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
	};*/
	
	//mesh_t cube = resources.load_mesh(RD_CUBE);
	material_t mat = resources.load_material(RD_DEFAULT);

	event_system_t events{ current_window };

	camera_t camera{WINDOW_W, WINDOW_H, glm::vec3(0.0f, 0.0f, -2.0f)};

	// TODO I cannot set up mesh object now because vao should be in main function
	vao_t vao{};
	vao.bind();
	vbo_t vbo(std::move(cube_vertices));
	ebo_t ebo(std::move(cube_indices));
	vao.set_attribute(vbo, 0, 3, GL_FLOAT, sizeof(vertex_t), offsetof(vertex_t, position));
	vao.set_attribute(vbo, 1, 3, GL_FLOAT, sizeof(vertex_t), offsetof(vertex_t, color));
	vao.set_attribute(vbo, 2, 2, GL_FLOAT, sizeof(vertex_t), offsetof(vertex_t, texture_pos));
	vao.unbind();
	vbo.unbind();
	ebo.unbind();
	
	GLfloat rotation{};

	// TODO pixels per second as a common speed metric

	/// textures

	/// load one

	//"D:\\projects\\gl\\YoutubeOpenGL\\wall.jpg";
	//"D:\\projects\\gl\\YoutubeOpenGL\\gl_demo_ref.png";
	raw_str texture_path = "D:\\projects\\gl\\YoutubeOpenGL\\gl_demo_ref.png";
	int texture_width, texture_height, texture_channels;

	stbi_set_flip_vertically_on_load(true);
	stbi_uc* texture_source = stbi_load(
		texture_path,
		&texture_width,
		&texture_height,
		&texture_channels,
		0
	);
	RD_ASSERT(texture_source, "can't load a texture - pointer is nullprt");

	// set texture parameters

	// how to deal with out-of-range pixels on S (x axis)
	DBG(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT));

	// how to deal with out-of-range pixels on T (y axis)
	DBG(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT));

	// handle a case when a surface to be bound with texture is bigger that texture itself
	// so the texture considers low-quality there
	DBG(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

	// when doing the opposite - scaling down the texture
	// but if we are using mipmaps there we should tell opengl also interpolate between
	// two closest mipmaps for the texture. Because when opengl changes a texture to
	// its next mipmap when downscaling, a texture image suddenly might become with better
	// quality or like so // TODO test this assumption
	DBG(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));

	// generate openlg texture object
	GLuint texture;
	DBG(glGenTextures(1, &texture));

	// enable that created texture to apply further operations to it
	DBG(glBindTexture(GL_TEXTURE_2D, texture));

	// load texture data to GRAM
	DBG(glTexImage2D(
		GL_TEXTURE_2D, 0 /*mipmap lvl, specify if want to draw each mipmap manually*/,
		GL_RGB /*store the texture in this layout (important for shaders)*/,
		texture_width,
		texture_height, 0, GL_RGBA /*source texture layout*/,
		GL_UNSIGNED_BYTE, texture_source
	));

	// generate mipmap for bound texture 2D
	// (means other currently bound 1D and 3D textures will not be touched)
	DBG(glGenerateMipmap(GL_TEXTURE_2D));

	// free image from main RAM as it is already loaded into GRAM
	stbi_image_free(texture_source);

	while( ! events.should_close_app() )
	{
		render.start_frame();

		auto delta = render.get_time_delta();

		events.update_camera(camera, delta);
		mat.enable();
		render.draw_context();

		glm::mat4 model_coords = glm::mat4(1.0f);
		model_coords = glm::rotate(model_coords, glm::radians(rotation), glm::vec3(.0f, 1.f, .0f));

		int model_loc;

		camera.apply(mat.shader_program);

		DBG(model_loc = glGetUniformLocation(mat.shader_program.ID, "model"));


		DBG(glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model_coords)));

		DBG(glBindTexture(GL_TEXTURE_2D, texture));
		vao.bind();
		DBG(glDrawElements(GL_TRIANGLES, ebo.get_indices_count(), GL_UNSIGNED_INT, 0));
		vao.unbind();

		// draw it like a second cube
		model_coords = glm::rotate(model_coords, glm::radians(45.f), glm::vec3(.0f, 1.f, .0f));
		model_coords = glm::translate(model_coords, glm::vec3{ 0.f, 0.f, 2.f });
		DBG(glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model_coords)));
		vao.bind();
		DBG(glDrawElements(GL_TRIANGLES, ebo.get_indices_count(), GL_UNSIGNED_INT, 0));
		vao.unbind();

		render.swap_buffers();
		events.poll();
		render.end_frame();
	}
	
	return 0;
}
