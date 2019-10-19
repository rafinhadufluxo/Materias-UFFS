
//
// texture.frag: Fragment shader for wobbling a texture
//
// author: Antonio Tejada
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying float lightIntensity;
varying vec2 TexCoord;

/* Constants */
const float C_PI = 3.1415;
const float C_2PI = (2.0*C_PI);
const float C_2PI_I = (1.0/(2.0*C_PI));
const float C_PI_2 = C_PI / 2.0;
uniform sampler2D sampler2d0; 
uniform sampler2D sampler2d1; 
void main (void)
{
    vec2 perturb;
    float rad;
    float r = 0.3 / 250.0;
	
    rad = (TexCoord.x + TexCoord.y) - 1.0 + r *4.0;

    /* Wrap to -2.0*PI, 2*PI */
    rad = rad*C_2PI_I;
    rad = fract(rad);
    rad = rad*C_2PI;

    /* Center in -PI, PI */
    if (rad > C_PI) rad = rad - C_2PI;
    if (rad < -C_PI) rad = rad + C_2PI;

    /* Center in -PI/2, PI/2 */
    if (rad > C_PI_2) rad = C_PI-rad;
    if (rad < -C_PI_2) rad = -C_PI - rad;

    perturb.x  = (8.0 - rad*rad)/8.0;
    perturb.x  = rad * perturb.x/32.0;

    rad = (TexCoord.x - TexCoord.y + 0.3) * 4.0;

    /* Wrap to -2*PI, 2*PI */
    rad = rad*C_2PI_I;
    rad = fract(rad);
    rad = rad*C_2PI;

    /* Center in -PI, PI */
    if (rad > C_PI) rad = rad - C_2PI;
    if (rad < -C_PI) rad = rad + C_2PI;

    /* Center in -PI/2, PI/2 */
    if (rad > C_PI_2) rad = C_PI-rad;
    if (rad < -C_PI_2) rad = -C_PI - rad;

    perturb.y  = (8.0 - rad*rad)/8.0;
    perturb.y  = rad * perturb.y/32.0;

    vec2 tc = perturb + TexCoord;

    vec3 lightColor;

    if(tc.x < 0.5)
	lightColor = vec3(texture2D(sampler2d0, tc)) * lightIntensity;
    else
	lightColor = vec3(texture2D(sampler2d1, tc)) * lightIntensity;

    vec3 ct = clamp(lightColor, 0.0, 1.0);

    gl_FragColor = vec4 (ct, 1.0);
}

