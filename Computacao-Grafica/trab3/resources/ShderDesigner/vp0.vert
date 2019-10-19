varying vec3 N;
varying vec3 v;
varying vec3 L;
varying float pattern;
const vec3 lightPos = vec3(0.0,5.0,5.0);

void main()
{
  v = (gl_ModelViewMatrix * gl_Vertex).xyz;
  L = normalize(lightPos - v);
  N = normalize(gl_NormalMatrix * gl_Normal);
  pattern = fract(4.0*(gl_Vertex.x+gl_Vertex.y+gl_Vertex.z));
  gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
