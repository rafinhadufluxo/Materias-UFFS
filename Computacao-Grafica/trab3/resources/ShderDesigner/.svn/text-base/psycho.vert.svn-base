
//
// psycho.vert: warping vertex shader for a psychedelic effect
//
// author: Randi Rost, John Kessenich
//
// Copyright (c) 2002-2003: 3Dlabs, Inc.
//

varying float lightIntensity;
varying vec3 Position;
uniform vec3 LightPosition;
uniform float Scale;

const float effect = 0.2;

void main(void) {
	vec4 pos = gl_ModelViewMatrix * gl_Vertex;
	Position = vec3(gl_Vertex) * Scale;
	vec3 tnorm = normalize(gl_NormalMatrix * gl_Normal);
	lightIntensity = abs(dot(normalize(LightPosition - vec3(pos)), tnorm) * 1.5);
	
	//
	// Perturb the vertices.
	//
	vec4 transPos = gl_ModelViewProjectionMatrix * gl_Vertex;
	vec3 transLoc = vec3(transPos);
	float s = transLoc.y;
	s *= s;
	transLoc = transLoc + effect * s * transLoc;
	transLoc /= (1.0 + effect);
	
	gl_Position = vec4(transLoc, transPos.w);
}
