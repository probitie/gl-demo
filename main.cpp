#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define out std::cout
#define flush "\n"

// USE IN MAIN FUNCTION ONLY
#define CHECK_PTR(ptr, msg){\
	if (ptr == nullptr)\
	{\
		out << msg << flush;\
		glfwTerminate();\
		return -1;\
	}\
}

int main()
{

	// https://www.youtube.com/watch?v=45MIykWJ-C4
	// (was) 6:38 timecode
	// (now) ???

	// init glfw - it just handles the window, receives user events etc
	glfwInit();

	// specify the version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// create a window
	GLFWwindow* window = glfwCreateWindow(800, 800, "hello there", NULL, NULL);
	CHECK_PTR(window, "failed to create GLFW window");

	// tell glfw to use the window
	glfwMakeContextCurrent(window);


	// ------------- OPENGL --------------
	// init opengl by glad
	gladLoadGL();

	// set current viewport
	glViewport(0, 0, 800, 800);

	// write a color to the back buffer
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// make back buffer front and show it on the screen
	glfwSwapBuffers(window);

	// ------------- ------ --------------


	// main loop
	while (!glfwWindowShouldClose(window)) // quit the loop only if such message was received
	{
		// read messages
		glfwPollEvents();

	}


	// end of the program
	glfwDestroyWindow(window);
	glfwTerminate();



	return 0;
}
