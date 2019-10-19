
//
// mandel.vert: Vertex shader for drawing the Mandelbrot set
//
// author: Dave Baldwin, Steve Koren
//         based on a shader by Michael Rivero
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying float lightIntensity;
varying vec3 Position;
uniform vec3 LightPosition;

const float specularContribution = 0.2;
const float diffuseContribution  = (1.0 - specularContribution);

void main(void) {
    vec4 pos        = gl_ModelViewMatrix * gl_Vertex;
    Position        = vec3(gl_Vertex);
    vec3 tnorm      = normalize(gl_NormalMatrix * gl_Normal);
    vec3 lightVec   = normalize(LightPosition - vec3(pos));
    vec3 reflectVec = reflect(lightVec, tnorm);
    vec3 viewVec    = normalize(vec3(pos));

    float spec = pow(clamp(dot(reflectVec, viewVec), 0.0, 1.0), 16.0);

    lightIntensity = max(diffuseContribution * dot(lightVec, tnorm), 0.0) +
                     specularContribution * spec;
    
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
