
//
// marble.frag: Fragment shader for producing a marble effect
//
// author: Randi Rost
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying float LightIntensity; 
varying vec3  MCposition;

uniform sampler3D Noise;
uniform vec3 MarbleColor;
uniform vec3 VeinColor;

uniform sampler1D Sine;
uniform vec3 Offset;

void main (void)
{
    vec4 noisevec   = texture3D(Noise, MCposition + Offset.yzx);

    float intensity = abs(noisevec[0] - 0.25) +
                      abs(noisevec[1] - 0.125) +
                      abs(noisevec[2] - 0.0625) +
                      abs(noisevec[3] - 0.03125);

    vec4 unswiz = texture1D(Sine, MCposition.y + intensity * 2.0);
    float sineval = unswiz.s;
    vec3 color   = mix(VeinColor, MarbleColor, sineval);
    color       *= LightIntensity;
    color = clamp(color, 0.0, 1.0);
    gl_FragColor = vec4 (color, 1.0);
}