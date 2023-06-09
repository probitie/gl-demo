#version 330 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec3 aNormal; // the color variable has attribute position 1
layout (location = 2) in vec3 aColor;
layout (location = 3) in vec2 aTexuv; // texture pos

out vec3 color; // output a color to the fragment shader
out vec2 texuv;
out vec3 normal;

// uniform float scale; // unused
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
    gl_Position = proj * view * model * vec4(aPos, 1.0);
    color = aColor; // set ourColor to the input color we got from the vertex data
    texuv = aTexuv;
    normal = aNormal;
} 