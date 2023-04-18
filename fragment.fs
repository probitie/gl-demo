#version 330 core
out vec4 FragColor;  
in vec3 ourColor;
in vec2 texCoord;
in vec3 ourLight;

uniform sampler2D ourTexture;
  
void main()
{                                                                    // disabled color
    FragColor = vec4(ourLight, 1.0f) * (texture(ourTexture, texCoord) ); // * vec4(ourColor, 1.0f));
}