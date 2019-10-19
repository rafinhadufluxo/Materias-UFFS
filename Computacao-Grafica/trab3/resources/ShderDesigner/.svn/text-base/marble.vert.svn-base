
//
// marble.vert: Vertex shader for producing a marble effect
//
// author: Randi Rost
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying float LightIntensity;
varying vec3  MCposition;

uniform vec3  LightPosition;
uniform float Scale;

void main(void)
{
    vec4 ECposition = gl_ModelViewMatrix * gl_Vertex;
    MCposition      = vec3 (gl_Vertex) * Scale;
    vec3 tnorm      = normalize(vec3 (gl_NormalMatrix * gl_Normal));
    LightIntensity  = dot(normalize(LightPosition - vec3 (ECposition)), tnorm) * 1.5;
    gl_Position     = gl_ModelViewProjectionMatrix * gl_Vertex;
}
