
//
// psycho.frag: A colorful swirl
//
// author: Randi Rost
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying float lightIntensity; 
varying vec3 Position;

uniform vec3  NoiseScale;
uniform vec3  Offset;
uniform sampler3D sampler3d; // value of sampler3d = 6
void main (void)
{
    vec3 noisevec;
    vec3 color;
 
    noisevec = vec3(texture3D(sampler3d, vec3 (Position * NoiseScale + Offset))) * 3.0;

    color = clamp(noisevec * lightIntensity, 0.0, 1.0); 

    gl_FragColor = vec4(color, 1.0);
}
