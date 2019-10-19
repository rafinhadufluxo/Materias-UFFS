
//
// dimple.frag: Fragment shader for bump mapping dimples (bumps)
//
// author: John Kessenich
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying vec3 LightDir;
varying vec3 EyeDir;
varying vec3 Normal;

const vec3 color = vec3(0.7, 0.6, 0.18);

const float Density = 16.0;
const float Size = 0.15;
const float SpecularFactor = 0.5;

void main (void)
{
    vec3 litColor;

    vec2 c = Density * vec2(gl_TexCoord[0]);
    vec2 p = fract(c) - vec2(0.5);
  
/* for elongated
    vec2 grid = floor(c + 0.5);    
    if (abs(fract(grid.x / 2.0) - fract(grid.y / 2.0)) < 0.1) {
        // parities match, transpose coords
        float t = grid.x;
        grid.x = grid.y;
        grid.y = t;
        t = p.x;
        p.x = p.y;
        p.y = t;
    }
*/

    float d;
/* for elongated
    d = p.x * p.x;
    if (p.y > 0.2) {
        p.y -= 0.2;
        d = p.x * p.x + p.y * p.y;
    } else if (p.y < -0.2) {
        p.y += 0.2;
        d = p.x * p.x + p.y * p.y;
    }
*/

    d = p.x * p.x + p.y * p.y;
    if (d >= Size)
        p = vec2(0.0);

    vec3 normDelta = vec3(-p.x, -p.y, 1.0);
      
    litColor = color * max(0.0, dot(normDelta, LightDir));
      
    float t = 2.0 * dot(LightDir, normDelta);
    vec3 reflectDir = t * normDelta;
    reflectDir = LightDir - reflectDir;
    
//    vec3 reflectDir = LightDir - 2.0 * dot(LightDir, normDelta) * normDelta;
    
    float spec = max(dot(EyeDir, reflectDir), 0.0);
    spec = spec * spec;
    spec = spec * spec;
    spec *= SpecularFactor;

    litColor = min(litColor + spec, vec3(1.0));

    gl_FragColor = vec4(litColor, 1.0);
}
