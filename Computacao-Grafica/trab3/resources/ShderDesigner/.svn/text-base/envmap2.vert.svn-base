
//
// envmap2.vert: Vertex shader for environment mapping.
//
// author: Randi Rost
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying vec3 Normal;
varying vec3 EyeDir;
varying float LightIntensity;

const vec3 LightPosition = vec3(0.0, 10.0, 4.0);

void main(void) 
{
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    vec3 tnorm = normalize(gl_NormalMatrix * gl_Normal);
    EyeDir = vec3(gl_ModelViewMatrix * gl_Vertex);
    vec4 pos = gl_ModelViewMatrix * gl_Vertex;
    LightIntensity = abs(dot(normalize(LightPosition - vec3(pos)), tnorm));
    Normal = tnorm;
}
