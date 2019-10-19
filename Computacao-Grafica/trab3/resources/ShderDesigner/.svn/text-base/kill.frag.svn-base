
//
// kill.frag: Fragment shader for testing the "discard" command
//
// author: Randi Rost
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying vec3  Position;
varying float lightIntensity;

void main (void)
{
    vec3	ct;
    float	ss, tt;

    vec3 pos = Position;
    
    ss = pos.x * 7.1;
    tt = pos.z * 7.1;

    ss = fract (ss);
    tt = fract (tt);

    if ((ss > 0.13) && (tt > 0.13)) discard;

    ct = vec3 (0.9, 0.7, 0.25) * lightIntensity * 1.5;
    ct = clamp(ct, 0.0, 1.0);

    gl_FragColor = vec4 (ct, 1.0);
}
