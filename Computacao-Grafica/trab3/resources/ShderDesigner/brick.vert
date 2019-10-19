
//
// brick.vert: Vertex shader for procedural bricks
//
// author: Dave Baldwin, Steve Koren, Randi Rost
//         based on a shader by Darwyn Peachey
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

uniform vec3 LightPosition;

const float specularContribution = 0.3;
const float diffuseContribution  = (1.0 - specularContribution);

varying float LightIntensity;
varying vec2  MCposition;

void main(void)
{
    vec4 ecPosition = gl_ModelViewMatrix * gl_Vertex;
    vec3 tnorm      = normalize(gl_NormalMatrix * gl_Normal);
    vec3 lightVec   = normalize(LightPosition - vec3 (ecPosition));
    vec3 reflectVec = reflect(-lightVec, tnorm);
    vec3 viewVec    = normalize(vec3 (-ecPosition));
    float spec      = max(dot(reflectVec, viewVec), 0.0);
    spec            = pow(spec, 16.0);
    LightIntensity  = diffuseContribution * max(dot(lightVec, tnorm), 0.0) +
                      specularContribution * spec;
    MCposition      = vec2 (gl_Vertex);
    gl_Position     = gl_ModelViewProjectionMatrix * gl_Vertex;
}
