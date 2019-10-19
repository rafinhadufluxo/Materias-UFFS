//
// envmap2.frag: Fragment shader for environment mappping.
//
// author: Randi Rost
//
// Copyright (c) 2002: 3Dlabs, Inc.
//
// note: This fragment shader does the environment mapping
//       "more correctly" than does the bumpy/shiny fragment
//       shader. The index values used when the reflection
//       angle has a negative z value are properly computed.
//
uniform sampler2D sampler2d; // value of sampler2d = 4
const vec3 Xunitvec = vec3(1.0, 0.0, 0.0);
const vec3 Yunitvec = vec3(0.0, 1.0, 0.0);
const vec3 BaseColor = vec3(0.4, 0.4, 1.0);
const float MixRatio = 0.8;

varying vec3 Normal;
varying vec3 EyeDir;
varying float LightIntensity;

const float Density = 6.0;
const float Coeff1 = 5.0;
float Size = 0.15;

void main (void)
{
    // Compute reflection vector
    
    vec3 reflectDir = reflect(EyeDir, Normal);

    // Compute altitude and azimuth angles

    vec2 index;

    index[1] = dot(normalize(reflectDir), Yunitvec);
    reflectDir.y = 0.0;
    index[0] = dot(normalize(reflectDir), Xunitvec) * 0.5;

    // Translate index values into proper range


    if (reflectDir.z >= 0.0)
        index = (index + 1.0) * 0.5;
    else
    {
        index.t = (index.t + 1.0) * 0.5;
	index.s = (-index.s) * 0.5 + 1.0;
    }
    
    // if reflectDir.z >= 0.0, s will go from 0.25 to 0.75
    // if reflectDir.z <  0.0, s will go from 0.75 to 1.25, and
    // that's OK, because we've set the texture to wrap.
  
    // Do a lookup into the environment map.

    vec3 envColor = vec3(texture2D(sampler2d, index));

    // Add lighting to base color and mix

    vec3 base = LightIntensity * BaseColor;
    envColor = mix(envColor, base, MixRatio);

    gl_FragColor = vec4(envColor, 1.0);
}
