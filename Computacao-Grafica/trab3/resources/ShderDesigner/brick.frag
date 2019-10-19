
//
// brick.frag: Fragment shader for procedural bricks
//
// author: Dave Baldwin, Steve Koren, Randi Rost
//         originally based on a shader by Darwyn Peachey
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

uniform vec3  BrickColor, MortarColor;
uniform float ColumnWidth, RowHeight;
uniform float Bwf, Bhf;

varying vec2  MCposition;
varying float LightIntensity;

void main(void)
{
    vec3 color;
    float ss, tt, w, h;
    
    ss = MCposition.x / ColumnWidth;
    tt = MCposition.y / RowHeight;

    if (fract(tt * 0.5) > 0.5)
        ss += 0.5;

    ss = fract(ss);
    tt = fract(tt);

    w = step(ss, Bwf);
    h = step(tt, Bhf);

    color = mix(MortarColor, BrickColor, w * h) * LightIntensity;
    gl_FragColor = vec4 (color, 1.0);
}
