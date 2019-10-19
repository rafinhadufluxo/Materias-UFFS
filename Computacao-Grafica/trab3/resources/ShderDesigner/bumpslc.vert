
//
// bumpslc.vert: Vertex shader for bump mapping in surface local coordinates
//
// author: Randi Rost
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying vec3 lightDir; 	  // interpolated surface local coordinate light direction 
varying vec3 viewDir;     // interpolated surface local coordinate view direction

const vec3 LightPosition = vec3(0.0, 4.0, 4.0);  // eye space position of light

void main(void)
{
    vec3 b;
    vec3 n;
    vec3 t;
    vec3 pos;
    vec3 lightVec;
    vec3 r;
    vec3 v;

    // Do standard vertex stuff

    gl_Position  = gl_ModelViewProjectionMatrix * gl_Vertex;
    gl_TexCoord[0] = gl_MultiTexCoord0;

    // Compute the binormal

    n = normalize(gl_NormalMatrix * gl_Normal);
    t = normalize(gl_NormalMatrix * vec3 (gl_Color));
    b = cross(n, t);

    // Transform light position into surface local coordinates

    v.x = dot(LightPosition, t);
    v.y = dot(LightPosition, b);
    v.z = dot(LightPosition, n);

    lightDir = normalize(v);

    pos      = vec3 (gl_ModelViewMatrix * gl_Vertex);

    v.x = dot(pos, t);
    v.y = dot(pos, b);
    v.z = dot(pos, n);

    viewDir = normalize(v);

}
