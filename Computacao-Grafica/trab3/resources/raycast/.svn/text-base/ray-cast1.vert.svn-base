varying vec3 vv;

const float scale = 5.0;

void main ()
{
	vec4 vert = gl_Vertex * vec4(vec3(scale),1.0);
	vv = vec3(gl_ModelViewMatrix * vert);
	gl_FrontColor = gl_Color;
	gl_Position = gl_ModelViewProjectionMatrix * vert;
}