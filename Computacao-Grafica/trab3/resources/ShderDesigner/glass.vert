
//
// glass.vert: Vertex shader for doing a glass-like effect
//
// author: John Kessenich
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying vec3 LightDir;
varying vec3 EyeDir;
varying vec3 Normal;

const vec3 LightPosition = vec3(0.0, 0.0, 0.5);

void main(void) 
{
    gl_Position  =  gl_ModelViewProjectionMatrix * gl_Vertex;
    EyeDir       = -1.0 * normalize(vec3(gl_ModelViewMatrix * gl_Vertex));
    LightDir     =  normalize(LightPosition);
    Normal       =  normalize(gl_NormalMatrix * gl_Normal);
}
