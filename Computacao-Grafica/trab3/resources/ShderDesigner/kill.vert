
//
// kill.vert: Vertex shader for testing the "discard" command
//            in a fragment shader
//
// author: Randi Rost
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying float lightIntensity;
varying vec3  Position;
uniform vec3  LightPosition;

const float specularContribution = 0.5;
const float diffuseContribution  = (1.0 - specularContribution);

void main(void) {
    vec4 pos        = gl_ModelViewMatrix * gl_Vertex;
    Position        = vec3(gl_Vertex);
    vec3 tnorm      = normalize(gl_NormalMatrix * gl_Normal);
    vec3 lightVec   = normalize(LightPosition - vec3(pos));
    vec3 reflectVec = reflect(lightVec, tnorm);
    vec3 viewVec    = normalize(vec3(pos));
    float dotval    = abs(dot(lightVec, tnorm));

    float spec = pow(dot(reflectVec, viewVec), 16.0);

    lightIntensity = diffuseContribution * dotval +
                     specularContribution * spec;
    
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

}
