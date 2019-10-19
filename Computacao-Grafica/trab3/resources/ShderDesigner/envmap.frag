//
// envmap.frag: Fragment shader for bump mapping into an environment map.
//
// author: John Kessenich, Randi Rost
//
// Copyright (c) 2002: 3Dlabs, Inc.
//
uniform sampler2D sampler2d0; // value of sampler2d = 4
const vec3 Xunitvec = vec3(1.0, 0.0, 0.0);
uniform vec3 Yunitvec = vec3(0.0, 1.0, 0.0);

varying vec3 Normal;
varying vec3 EyeDir;

const float Density = 6.0;
const float Coeff1 = 5.0;
const float Size = 0.15;

void main (void)
{
    // Compute reflection vector. Should really normalize
    // EyeDir and Normal, but this is OK for some objects.
    
    vec3 reflectDir = reflect(EyeDir, Normal);

    // Compute altitude and azimuth angles

    vec2 index;
    index[1] = dot(normalize(reflectDir), Yunitvec);
    reflectDir.y = 0.0;
    index[0] = dot(normalize(reflectDir), Xunitvec);

    // Compute bump locations

    vec2 c = Density * vec2(gl_TexCoord[0]);
    vec2 offset = fract(c) - vec2(0.5);
  
    float d = offset.x * offset.x + offset.y * offset.y;
    if (d >= Size)
        offset = vec2(0.0);

    // Translate index values to (0.5, 0.5) and make offset non-linear

    index = (index + 1.0) * 0.5 - Coeff1 * offset * offset * offset;
    
    // Do a lookup into the environment map.

    vec3 envColor = vec3(texture2D(sampler2d0, index));

    gl_FragColor = vec4(envColor, 1.0);
}
