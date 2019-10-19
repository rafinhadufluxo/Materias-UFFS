varying vec3 N;
varying vec3 L;
varying vec3 v;
varying float pattern;   
const vec3 lightPos = vec3(0.0,15.0,0.0); // make this uniform
void main(void)
{
   v = vec3(gl_ModelViewMatrix * gl_Vertex);
   L = normalize(lightPos - v);
   N = normalize(gl_NormalMatrix * gl_Normal);  
   pattern=fract(4.0*(gl_Vertex.y+gl_Vertex.x+gl_Vertex.z));
   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
              

