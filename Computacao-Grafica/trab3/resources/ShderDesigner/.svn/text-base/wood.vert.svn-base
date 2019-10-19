
//
// wood.vert: Simple vertex shader for wood
//
// author: John Kessenich
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying float lightIntensity;
varying vec3 Position;
uniform vec3 LightPosition;
uniform float Scale;

void main(void) {
	vec4 pos = gl_ModelViewMatrix * gl_Vertex;
	Position = vec3(gl_Vertex) * Scale;
	vec3 tnorm = normalize(gl_NormalMatrix * gl_Normal);
	lightIntensity = max(dot(normalize(LightPosition - vec3(pos)), tnorm), 0.0) * 1.5;
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
