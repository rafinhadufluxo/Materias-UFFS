//
// Fragment shader for antialiased procedural bricks
//
// Authors: Dave Baldwin, Randi Rost
//          based on a shader by Darwyn Peachey
//
// Copyright (c) 2002-2004 3Dlabs Inc. Ltd. 
//
// See 3Dlabs-License.txt for license information
//

const vec3  BrickColor = vec3(1.0, 0.3, 0.2);
const vec3  MortarColor = vec3(0.85, 0.86, 0.84);
const vec2  BrickSize = vec2(0.3, 0.15);
const vec2  BrickPct = vec2(0.9, 0.85);
const vec2  MortarPct = vec2(0.1, 0.15);

varying vec2  MCposition;
varying float LightIntensity;

#define Integral(x, p, notp) ((floor(x)*(p)) + max(fract(x)-(notp), 0.0))

void main(void)
{
    vec2 position, fw, useBrick;
    vec3 color;
 
    // Determine position within the brick pattern
    position = MCposition / BrickSize;

    // Adjust every other row by an offset of half a brick
    if (fract(position.y * 0.5) > 0.5)
        position.x += 0.5;

    // Calculate filter size
    //fw = fwidth(position); //fwidth not implemented on WildcatVP
    fw = (abs(dFdx(MCposition)) + abs(dFdy(MCposition))) / BrickSize;
 
    // Perform filtering by integrating the 2D pulse made by the
    // brick pattern over the filter width and height
    useBrick = (Integral(position + fw, BrickPct, MortarPct) - 
                Integral(position, BrickPct, MortarPct)) / fw;

    // Determine final color
    color  = mix(MortarColor, BrickColor, useBrick.x * useBrick.y);
    color *= LightIntensity;
    
    gl_FragColor = vec4 (color, 1.0);
}
