



// https://www.youtube.com/watch?v=45MIykWJ-C4
// 22:14 timecode













#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define out std::cout
#define flush "\n"
#define ref GLuint

// USE IN MAIN FUNCTION ONLY
#define CHECK_PTR(ptr, msg){\
	if (ptr == nullptr)\
	{\
		out << msg << flush;\
		glfwTerminate();\
		return -1;\
	}\
}

// -------------------- shaders -----------------------

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n";

// -------------------- ------- -----------------------



int main()
{

	// init glfw - it just handles the window, receives user events etc
	glfwInit();

	// specify the version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// core profile - only 3.3 api and higher - modern and more complex functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

	// create a window
	GLFWwindow* window = glfwCreateWindow(800, 800, "hello there", NULL, NULL);
	CHECK_PTR(window, "failed to create GLFW window");

	// tell glfw to use the window
	glfwMakeContextCurrent(window);



	// ------------- triange vertices ----------------
	GLfloat sqrt3_by_3 = GLfloat(sqrt(3)) / 3;
	GLfloat vertices[] =
	{
		-.5f, -.5f * sqrt3_by_3, .0f,
		 .5f, -.5f * sqrt3_by_3, .0f,
		 .0f,  1.f * sqrt3_by_3, .0f,
	};
	// ------------- ---------------- ----------------




	// ------------- OPENGL --------------
	// init opengl by glad
	gladLoadGL();

	// set current viewport
	glViewport(0, 0, 800, 800);

	
	//		===== compile shaders ======
	
	ref vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// create one vertex shader
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	ref fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// create one fragment shader
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// create a shader program
	ref shaderProgram = glCreateProgram();

	// add compiled shaders to the program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	
	// after linking program we can delete those shaders
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	//		===== =============== ======


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
