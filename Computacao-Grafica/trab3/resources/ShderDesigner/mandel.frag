
//
// mandel.frag: Fragment shader for drawing the Mandelbrot set
//
// author: Dave Baldwin
//         based on a shader by Michael Rivero
//
// Copyright (c) 2002: 3Dlabs, Inc.
//

varying vec3 Position;
varying float lightIntensity;

uniform int   maxIterations;
uniform float zoom;
uniform float xCenter;
uniform float yCenter;
uniform vec3  ColorInterior;
uniform vec3  ColorExterior1;
uniform vec3  ColorExterior2;

void main (void)
{
    vec3    pos   = fract(Position);
    float   real  = ((pos.x - 0.5) * zoom) - xCenter;
    float   imag  = ((pos.y - 0.5) * zoom) - yCenter;
    float   Creal = real;
    float   Cimag = imag;

    float r2 = 0.0;
    int iter;

    for (iter = 0; iter < maxIterations && r2 < 4.0; ++iter) {
        float tempreal = real;

        real = (tempreal * tempreal) - (imag * imag) + Creal;
        imag = 2.0 * tempreal * imag + Cimag;
        r2   = (real * real) + (imag * imag);
    }

    // Base the color on the number of iterations
    vec3 color;

    if (r2 < 4.0) {
        color = ColorInterior;
    } else {
        color = mix(ColorExterior1, ColorExterior2, fract (float(iter) * 0.05));
    }

    color = clamp(color * lightIntensity, 0.0, 1.0);

    gl_FragColor = vec4(color, 1.0);
}
