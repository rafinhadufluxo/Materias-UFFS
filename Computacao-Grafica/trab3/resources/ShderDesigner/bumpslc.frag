//
// bumpslc.frag: Fragment shader for bump mapping in surface local coordinates
//
// author: Randi Rost
//
// Copyright (c) 2002: 3Dlabs, Inc.
//
uniform sampler2D sampler2d0; // value of sampler2d = 3
varying vec3 lightDir; 	  // interpolated surface  local coordinate light direction 
varying vec3 viewDir;     // interpolated surface local coordinate view direction

const float diffuseFactor  = 0.7;
const float specularFactor = 0.7;
const vec3 basecolor = vec3 (0.8, 0.7, 0.3);

float patatin();
void main (void)
{
    vec3 norm;
    vec3 r;
    vec3 color;
    float intensity;
    float spec;
    float d;

    // Fetch normal from normal map

    norm = vec3(texture2D(sampler2d0, vec2 (gl_TexCoord[0])));
    norm = (norm - 0.5) * 2.0;
   // norm.y = -norm.y;

    intensity = max(dot(lightDir, norm), 0.0) * diffuseFactor;

    // Compute specular reflection component

    d = 2.0 * dot(lightDir, norm);
    r = d * norm;
    r = lightDir - r;
    spec = pow(max(dot(r, viewDir), 0.0) , 6.0) * specularFactor;
    intensity += min (spec, 1.0);

     // Compute final color value

    color = clamp(basecolor * intensity, 0.0, 1.0);
 
    // Write out final fragment color

    gl_FragColor = vec4 (color, 1.0);
    
}
