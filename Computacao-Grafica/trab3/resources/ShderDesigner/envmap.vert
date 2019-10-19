
//
// envmap.vert: Fragment shader for bump mapping into an environment map.
//
// author: John Kessenich
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying vec3 Normal;
varying vec3 EyeDir;

const vec3 LightPosition = vec3(0.0, 10.0, 4.0);
const float Scale = 1.0;
const float Time = 0.5;

const float InvRootThreeMinusOne = 1.3660254;

void main(void) 
{
    gl_TexCoord[0] = gl_MultiTexCoord0;
    Normal = normalize(gl_NormalMatrix * gl_Normal);
    EyeDir = vec3(gl_ModelViewMatrix * gl_Vertex);
    
    float periodicTime = 2.0 - 8.0 * pow(fract(0.15 * Time) - 0.5, 2.0);
    
    vec3 hashPosition = normalize(vec3(gl_Vertex - 0.001));
    float hash = (abs(hashPosition.x) + abs(hashPosition.y) + abs(hashPosition.z));
    
    // shortest sum of coords for a normal is 1.0
    // longest sum of coords for a normal is 3 * (1 / root 3), which is root 3
    // normalize hash WRT to this range.
    hash = (hash - 1.0) * InvRootThreeMinusOne;
    
    vec4 position = gl_ModelViewProjectionMatrix * gl_Vertex;
    float w = position.w;
    vec3 crumpled = vec3(position);
    if (hash < periodicTime)
        crumpled *= 1.0 - (periodicTime - hash);

        
    gl_Position = vec4(crumpled, w);
}
