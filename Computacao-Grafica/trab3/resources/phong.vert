varying vec3 tnorm;
varying vec3 lightVec;
varying vec4 cor;

uniform vec3 lpos;

void main()
{
	vec3 ePosition = vec3(gl_ModelViewMatrix * gl_Vertex);
	vec3 lPosition = vec3(gl_ModelViewMatrix * gl_LightSource[0].position);
	tnorm          = normalize(gl_NormalMatrix * gl_Normal);
	lightVec       = normalize(gl_LightSource[0].position.xyz - ePosition);
	lightVec       = normalize(lPosition - ePosition);
	
	gl_FrontColor = gl_Color;
	cor = gl_Color;

	vec4 vert = gl_Vertex;
	float scale = 1.0;
	vert.x *= scale;
	vert.y *= scale;
	vert.z *= scale;
	//play here
 	gl_Position = gl_ModelViewProjectionMatrix * vert;

}
