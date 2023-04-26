#version 330 core
out vec4 result_color;  
in vec3 color;
in vec2 texuv;
in vec3 normal;
in vec3 pxpos; // fragment (pixel) position in world-space

uniform vec3 ambient_light_color;
uniform vec3 a_diffuse_light_color; // just one of (intensivity)
uniform vec3 diffuse_light_pos; // just one of (intensivity) 

uniform vec3 a_specular_light;
uniform vec3 a_specular_light_pos;
uniform sampler2D the_texture;
uniform vec3 camera_pos;
 

void main()
{
    vec3 norm = normalize(normal);
    vec3 light_ray_direction = normalize(a_specular_light_pos - pxpos);

    vec4 texel = texture(the_texture, texuv);



    float ambient_strength = 0.3f;
    vec3 ambient_light = ambient_strength * ambient_light_color;



    float diffuse_strength = 0.5f;
    float diffuse_impact_ratio = max(dot(norm, light_ray_direction), 0.0f);
    vec3 diffuse_light = diffuse_impact_ratio * a_diffuse_light_color * diffuse_strength;


    float specular_strength = 0.6f;

    // 2 - more like diffuse - 256 - more like just a light dot
    float specular_beam_size_ratio = 64; 
    vec3 view_dir = normalize(camera_pos - pxpos);
    vec3 reflected_beam = reflect(-light_ray_direction, norm);

    float specular_distribution = pow(max(dot(view_dir, reflected_beam), 0.0f), specular_beam_size_ratio);
    
    vec3 specular_light = specular_strength * specular_distribution * a_specular_light;


    result_color = vec4(ambient_light + diffuse_light + specular_light, 1.0f) * texel; // * vec4(ourColor, 1.0f));
}