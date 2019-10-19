
//
// glass.frag: Fragment shader for doing a glass-like effect
//
// author: John Kessenich
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying vec3 LightDir;
varying vec3 EyeDir;
varying vec3 Normal;

const vec4 GlassColor = vec4(0.5, 0.5, 0.6, 0.15);
const vec4 SpecularColor1 = vec4(0.1, 0.08, 0.05, 1.0);
const vec4 SpecularColor2 = vec4(0.1, 0.1, 0.05, 1.0);
const float SpecularFactor1 = 2.0;
const float SpecularFactor2 = 2.0;

void main (void)
{
    vec4 color;

    vec3 reflectDir = -reflect(LightDir, Normal);
    
    //
    // Uncomment this line for a cool solid look.
    // Comment it out for light shining off of flat glass.
    //
   // reflectDir = -reflectDir;
    
    float spec = max(dot(EyeDir, reflectDir), 0.0);

    //
    // Compute two rings of specular effect.
    //
    spec = spec * spec;

    //
    // Basic glass color + first specular effect
    //
    color = GlassColor + SpecularFactor1 * spec * SpecularColor1;

    //
    // Second specular effect
    //
    spec = pow(spec, 8.0) * SpecularFactor2;
    color += spec * SpecularColor2;
    
    gl_FragColor = min(color, vec4(1.0));
}
