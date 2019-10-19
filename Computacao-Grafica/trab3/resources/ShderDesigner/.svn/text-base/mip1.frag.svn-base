varying float xpos;
varying float ypos;

uniform sampler2D t0;
uniform sampler2D t1;
uniform float TIME_FROM_INIT;

void main (void) {
  float t = TIME_FROM_INIT*0.001;
  vec4 cl = texture2D(t0, vec2 (gl_TexCoord[0])+vec2(t*0.03,-t*0.02))+texture2D(t1, vec2 (gl_TexCoord[0])+vec2(t*0.05,t*0.03));
  cl.r = sin(3.1416*(1-frac(cl.r+t+0.1)));
  cl.g = sin(3.1416*(1-frac(cl.g+t)));
  cl.b = sin(3.1416*(1-frac(cl.b+t+0.05+0.05*sin(t))));
  gl_FragColor =  cl;
}
