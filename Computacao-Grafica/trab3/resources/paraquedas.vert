void main()
{
	vec4 vert = gl_Vertex;
	vec3 norm = gl_Normal;

if(gl_Vertex.z < 0)
{
	vert = vec4(0,0,-1,1);
	norm = vec3(0,0,-1);
}
 	gl_Position = gl_ModelViewProjectionMatrix * vert;

	vec3 ePosition = vec3(gl_ModelViewMatrix * vert);
	vec3 lPosition = vec3(gl_ModelViewMatrix * gl_LightSource[0].position);
	vec3 tnorm     = normalize(gl_NormalMatrix * norm);
	vec3 lightVec  = normalize(gl_LightSource[0].position.xyz - ePosition);
	//vec3 lightVec  = normalize(lPosition - ePosition);
	float diffuse  = dot(lightVec,tnorm);
	vec4 color =   gl_LightSource[0].diffuse * gl_Color * diffuse;
	gl_FrontColor = color;
	gl_BackColor = color;
}
