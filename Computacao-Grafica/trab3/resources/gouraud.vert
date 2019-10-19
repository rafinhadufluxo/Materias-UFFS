void main()
{
	vec4 vert = gl_Vertex;
	float scale = 1.0;
	vert.x *= scale;
	vert.y *= scale;
	vert.z *= scale;
	
 	gl_Position = gl_ModelViewProjectionMatrix * vert;


	vec3 ePosition = vec3(gl_ModelViewMatrix * gl_Vertex);
	vec3 lPosition = vec3(gl_ModelViewMatrix * gl_LightSource[0].position);
	vec3 tnorm     = normalize(gl_NormalMatrix * gl_Normal);
	vec3 lightVec  = normalize(gl_LightSource[0].position.xyz - ePosition);
	//vec3 lightVec  = normalize(lPosition - ePosition);
	float diffuse  = dot(lightVec,tnorm);
	vec4 color =   gl_LightSource[0].diffuse * gl_Color * diffuse;
	gl_FrontColor = color;
	//gl_BackColor = color;
}
