#version 330 core
out vec4 result_color;  
in vec3 color;
in vec2 texuv;
in vec3 normal;
in vec3 pxpos; // fragment (pixel) position in world-space

uniform vec3 ambient_light_color;
uniform vec3 a_diffuse_light_color; // just one of (intensivity)
uniform vec3 diffuse_light_pos; // just one of (intensivity) 

// uniform vec3 a_specular_light
uniform vec3 a_specular_light_pos;
uniform sampler2D the_texture;
 

void main()
{
    float ambient_strength = 0.2f;
    float diffuse_strength = 1.0f;

    vec3 ambient_light = ambient_strength * ambient_light_color;

    vec3 norm = normalize(normal);
    vec3 light_ray_direction = normalize(diffuse_light_pos - norm);

    float diffuse_impact_ratio = max(dot(norm, light_ray_direction), 0.0f);


    vec3 diffuse_light = diffuse_impact_ratio * a_diffuse_light_color;

    vec4 texel = texture(the_texture, texuv);

    // intensivity (another uniform) depends on 
    // max(diffuse_light, max(ambient_light, specular_light))

    result_color = vec4(diffuse_light, 1.0f) * texel; // * vec4(ourColor, 1.0f));
}