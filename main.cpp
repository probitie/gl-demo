



// https://www.youtube.com/watch?v=45MIykWJ-C4
// 22:14 timecode   / from 12-30 to 15-30













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
	// Vertices coordinates
	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
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



	//		===== create vertex object ======

	// only one object - a triangle, so we ain't need an array of VBO
	// it stores actual info about a figure (vertices, colors etc)
	ref VAO, VBO;


	// add VAO - to tell gpu how to interpret VBO - what are vertices, what are colors
	// it can be used for multiple VBO's
	// WARNING: it should be generated BEFORE VBO, the ordering is really important
	glGenVertexArrays(1, &VAO);

	// ask opengl about creating a buffer object
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	// setting the object as a current operated object (can be only one)
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// write to binded object his data
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	// specify how to interpret the data in VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);
	
	// unbind previous buffers as they are already configured
	// to prevent accidental changing the data
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//		===== ==================== ======



	// write a color to the back buffer
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// make back buffer front and show it on the screen
	glfwSwapBuffers(window);

	// ------------- ------ --------------



	// main loop
	while (!glfwWindowShouldClose(window)) // quit the loop only if such message was received
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glfwSwapBuffers(window);

		// draw to the back buffer 3 vertices starting from 0 and make one triangle from them
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// read messages
		glfwPollEvents();

	}

	// free gpu memory
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);


	// end of the program
	glfwDestroyWindow(window);
	glfwTerminate();



	return 0;
}
