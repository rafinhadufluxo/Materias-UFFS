varying float lightIntensity;
varying vec2 TexCoord;

void main()
{
	float cos_45 = sqrt(2.0)/2.0;
	float cos_45_2 = cos_45*cos_45;
	vec3 normal = gl_Normal;
	vec4 vert = gl_Vertex;
	
	if(vert.x > cos_45_2)
		vert.x = cos_45_2;
	else if(vert.x < -cos_45_2)
		vert.x = -cos_45_2;
	if(vert.y > cos_45_2)
		vert.y = cos_45_2;
	else if(vert.y < -cos_45_2)
		vert.y = -cos_45_2;
	if(vert.z > cos_45_2)
		vert.z = cos_45_2;
	else if(vert.z < -cos_45_2)
		vert.z = -cos_45_2;


	vec3 ePosition = vec3(gl_ModelViewMatrix * vert);
	vec3 lPosition = vec3(gl_ModelViewMatrix * gl_LightSource[0].position);
	vec3 tnorm     = normalize(gl_NormalMatrix * normal);
	vec3 lightVec  = normalize(gl_LightSource[0].position.xyz - ePosition);
	//vec3 lightVec  = normalize(lPosition - ePosition);
	float diffuse  = dot(lightVec,tnorm);
	vec4 color =   gl_LightSource[0].diffuse * gl_Color * diffuse;
	gl_FrontColor = color;
	gl_BackColor = color;

	TexCoord = gl_MultiTexCoord0.xy;
	
	lightIntensity = diffuse;
	gl_Position = gl_ModelViewProjectionMatrix * vert;
}
