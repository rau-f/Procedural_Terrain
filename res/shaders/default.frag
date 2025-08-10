#version 330 core

layout(location = 0) out vec4 color;
in float v_Height;
in vec3 v_Normal;
in vec3 v_FragPos;

uniform vec3 u_LightDir;
uniform vec3 u_LightColor;
uniform vec3 u_ObjectColor;

void main()
{
    vec3 N = normalize(v_Normal);
    vec3 L = normalize(-u_LightDir);

    vec3 ambient = 1.0 * u_LightColor;

    float diff = max(dot(N, L), 0.0);
    float shadowGlow = 0.2 * (1 - diff);
    vec3 diffuse = diff * u_LightColor + shadowGlow * u_LightColor;

    float waterLevel = 0.8;
    float sandLevel  = 0.805;
    float grassLevel = 1.1;
    float rockLevel  = 1.35;
    float snowLevel  = 1.8;

    vec3 water = vec3(60/255.0, 166/255.0, 235/255.0);
    vec3 sand  = vec3(194/255.0, 178/255.0, 128/255.0);
    vec3 grass = vec3(0.1, 0.7, 0.3);
    vec3 rock  = vec3(171/255.0, 194/255.0, 156/255.0);
    vec3 snow  = vec3(1.0, 1.0, 1.0);

    vec3 finalColor;

    float scaledHeight = v_Height * 2;

    if (scaledHeight <= waterLevel)
    {
        finalColor = water;
    }
    else if (scaledHeight < sandLevel)
    {
        finalColor = sand;
    }
    else if (scaledHeight < grassLevel)
    {
        finalColor = grass;
    }
    else if (scaledHeight < rockLevel)
    {
        finalColor = rock;
    }
    else if (scaledHeight < snowLevel)
    {
        finalColor = snow;
    }
    else
    {
        finalColor = snow / 1.5;
    }

   vec3 light = (ambient + diffuse) * u_ObjectColor * 1.8;

   vec3 result = finalColor * light;
   color = vec4(result, 1.0f);
}