#version 330 core
out vec4 FragColor;  
in vec3 ourColor;
in vec2 texCoord;
in vec3 ourNormal;

uniform vec3 ambient_light;
uniform sampler2D ourTexture;

  
void main()
{                                                                    // disabled color
    
    vec4 texel;
    
    // TODO implement diffuse lighting with ourNormal


    texel = texture(ourTexture, texCoord);


    FragColor = vec4(ambient_light, 1.0f) * texel; // * vec4(ourColor, 1.0f));
}