
//
// inferno.frag: Fragment shader for producing a fire effect
//
// author: Randi Rost
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying float lightIntensity; 
varying vec3 Position;

uniform vec3 Offset;
uniform vec3 FireColor1;
uniform vec3 FireColor2;
uniform vec3 Black;
uniform bool Teapot;
uniform float Extent;
uniform sampler3D sampler3d; // value of sampler3d = 6
void main (void)
{
    vec4 noisevec;
    vec3 color;
    float intensity;
    float alpha;

    noisevec = texture3D(sampler3d, Position);
    noisevec = texture3D(sampler3d, vec3 (Position.x+noisevec[1]+Offset.x,
				 Position.y-noisevec[3]+Offset.y,
				 Position.z+noisevec[1]+Offset.z));

    intensity = 0.75 * (noisevec[0] + noisevec[1] + noisevec[2] + noisevec[3]);

    intensity = 1.95 * abs(2.0 * intensity - 0.35);
    intensity = clamp(intensity, 0.0, 1.0);

    if (Teapot == false)
        alpha = fract((Position.y+Extent)*0.65);
    else
        alpha = fract((Position.z+Extent)*0.65);

    color = mix(FireColor1, FireColor2, intensity) * (1.0 - alpha) * 2.0;
    color = clamp(color, 0.0, 1.0);
    alpha = 1.0 - alpha  * intensity;
    alpha *= alpha;

    gl_FragColor = vec4(color, alpha);
    
}
