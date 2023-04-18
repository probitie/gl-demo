#version 330 core
out vec4 FragColor;  
in vec3 ourColor;
in vec2 texCoord;

uniform vec3 ambient_light;
uniform sampler2D ourTexture;
  
void main()
{                                                                    // disabled color
    FragColor = vec4(ambient_light, 1.0f) * (texture(ourTexture, texCoord) ); // * vec4(ourColor, 1.0f));
}