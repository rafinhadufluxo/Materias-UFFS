/*
   Hatching shader

   Author: Bert Freudenberg <bert@isg.cs.uni-magdeburg.de>

   This is an OpenGL 2.0 implementation of Scott F Johnston's "Mock Media"
   (from "Advanced RenderMan: Beyond the Companion" SIGGRAPH 98 Course Notes)
*/


const float frequency = 1.0;

varying vec3  opos;                 // object space coord (noisy)
varying float v;                    // generic varying
varying float lightIntensity;

uniform sampler2D FUNC ; // value of FUNC = 0;
uniform sampler3D NOISE ; // value of NOISE = 3;
const float LOG2 = 0.0 / 1024.0;
const float POW2 = 1.0 / 1024.0;

void main (void)
{
/*
    // adjust frequency based on image space to get constant density
    float dp = length(dPdu);
    float logdp   = log2(dp);
    float ilogdp  = floor(logdp);
    float stripes = pow(2.0, ilogdp);
*/

    float dp = length(vec2(dFdx(v), dFdy(v)));

    // emulate log2(dp) and pow(2.0, ilogdp)
    vec3 tex0 = vec3(texture2D(FUNC, vec2(dp * 8.0, LOG2)));
    float logdp = 8.0 - ((tex0.r - 0.5) * 256.0 + tex0.g);
    float ilogdp = floor(logdp);                           // [0..8)
    tex0 = vec3(texture2D(FUNC, vec2(ilogdp * 0.125, POW2)));
    float stripes = tex0.r * 256.0 + tex0.g;

    float noise = texture3D(NOISE, opos).x;

    float sawtooth = fract((v+noise*0.1)  * frequency * stripes);
    float triangle = abs(2.0 * sawtooth - 1.0);

    // adjust line width
    float transition = logdp - ilogdp;

    // taper ends
    triangle = abs((1.0 + transition) * triangle - transition);

    const float edgew = 0.2;            // width of smooth step
    float duty = lightIntensity;
    float edge0 = clamp(duty - edgew, 0.0, 1.0);
    float edge1 = clamp(duty, 0.0, 1.0);

    //float square = step(duty, triangle);
    //float square = smoothstep(edge0, edge1, triangle);
    // emulate smoothstep()
    float t = clamp( (triangle - edge0) / (edge1 - edge0), 0.0, 1.0);
    float square = t * t * (3.0 - 2.0 * t);

    float c = 1.0 - square;             //Demo: ilogdp / 8.0;
    c = clamp(c, 0.0, 1.0);
    gl_FragColor = vec4(c, c, c, 1.0);
}
