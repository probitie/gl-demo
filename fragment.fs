#version 330 core
out vec4 FragColor;  
in vec3 ourColor;
in vec2 texCoord;

uniform vec3 ambient_light;
uniform sampler2D ourTexture;
uniform bool use_texture;
  
void main()
{                                                                    // disabled color
    
    vec4 texel;
    if(use_texture)
    {
        texel = texture(ourTexture, texCoord);
    }
    else
    {
        texel = vec4(1.0f, 1.0f, 1.0f, 1.0f);
    }

    FragColor = vec4(ambient_light, 1.0f) * texel; // * vec4(ourColor, 1.0f));
}