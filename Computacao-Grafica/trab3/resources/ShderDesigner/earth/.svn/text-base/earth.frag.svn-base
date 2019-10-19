// earth.frag

uniform sampler2D sampler2d0; //EarthDay;
uniform sampler2D sampler2d1; //EarthNight;
uniform sampler2D sampler2d2; //EarthCloudGloss;

varying float Diffuse;
varying vec3  Specular;
varying vec2  TexCoord;

const float Terminator = 0.3;
const float InvTerminator = 1.0 / (2.0 * Terminator);

void main (void)
{
    // separate maps are packed into the color components of this texture
    // clouds.r = cloud opacity
    // clouds.g = water glossiness
    vec2 clouds    = texture2D(sampler2d2, TexCoord).rg;

    vec3 daytime   = mix(texture2D(sampler2d0, TexCoord).rgb * Diffuse + Specular * clouds.g,
                         vec3(abs(Diffuse)), 
                         clouds.r);

    // the night image, modulated by cloud opacity
    vec3 nighttime = texture2D(sampler2d1, TexCoord).rgb * (1.0 - clouds.r);

    vec3 color = daytime;

    if (Diffuse < -Terminator)
        color = nighttime;

    if (abs(Diffuse) < Terminator )
        color = mix(nighttime, daytime, (Diffuse + Terminator) * InvTerminator);

    gl_FragColor = vec4 (color, 1.0);
}
