#version 330 core
out vec4 FragColor;  
in vec3 color;
in vec2 texuv;
in vec3 normal;

uniform vec3 ambient_light;
uniform vec3 a_diffuse_light; // just one of (intensivity)
uniform vec3 a_diffuse_light_pos; // just one of (intensivity)

uniform sampler2D the_texture;
  
void main()
{                                                                    // disabled color
    
    // TODO implement diffuse lighting with normal vec
    // so if angle between light source and normal is 90 deg - 0 diffuse lighting
    //    if angle between ... is 0 - full diffuse lighting
    // ???? 
    // diffuse_light_intencity = cos(source, normal)
    // diffuse_light = d_l_source * normalize(diffuse_light_intencity)
    //
    //float cosine = dot(a_diffuse_light_pos, normal) /
    //(length(a_diffuse_light_pos) * length(normal));

    //vec3 diffuse_light = cosine * a_diffuse_light;

    vec4 texel = texture(the_texture, texuv);

    // intensivity (another uniform) depends on 
    FragColor = vec4(ambient_light, 1.0f) * texel; // * vec4(ourColor, 1.0f));
}