#version 330 core
out vec4 result_color;  
in vec3 color;
in vec2 texuv;
in vec3 normal;
in vec3 pxpos;
uniform vec3 camera_pos;



void main()
{
    result_color = vec4(1.0f);
}