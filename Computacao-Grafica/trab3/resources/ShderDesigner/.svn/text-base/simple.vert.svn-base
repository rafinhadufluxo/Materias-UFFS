
//
// simple.vert: Extremely simple OGL2 vertex shader
//
// author: Steve Koren
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

const vec3 triangleColor = vec3(0.3, 0.6, 0.9);
varying vec3 tc;

void main(void)
{
	tc = triangleColor;
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
