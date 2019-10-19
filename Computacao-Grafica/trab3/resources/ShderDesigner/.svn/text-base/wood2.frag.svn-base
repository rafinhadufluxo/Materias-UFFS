
//
// wood2.frag: Fragment shader for redwood effect
//
// author: Randi Rost
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying float lightIntensity; 
varying vec3 Position;

uniform vec3  LightWood;
uniform vec3  DarkWood;
uniform float RingNoise;
uniform float RingFreq;
uniform float LightGrains;
uniform float DarkGrains;
uniform float GrainThreshold;
uniform vec3  NoiseScale;
uniform float Noisiness;
uniform float GrainScale;
uniform sampler3D noiseSampler;

void main (void)
{
    vec3 noisevec = vec3(texture3D(noiseSampler, Position * NoiseScale)) * Noisiness;
    vec3 location = vec3(Position + noisevec);
    
    float dist = sqrt(location.x * location.x + location.z * location.z) * RingFreq;
    float r = fract(dist + noisevec[0] + noisevec[1] + noisevec[2]) * 2.0;

    r = 1.0 - abs(r - 1.0);
 
    float rNoise = noisevec[2]; 

    float g = fract((Position.x + Position.z) * GrainScale + 0.5);
    rNoise *= g;
    vec3 color = mix(LightWood, DarkWood, r);
    if (g < GrainThreshold)
        color += LightWood * LightGrains * rNoise;
    else
        color -= LightWood * DarkGrains * rNoise;

    color = clamp(color * lightIntensity, 0.0, 1.0); 

    gl_FragColor = vec4(color, 1.0);
}
