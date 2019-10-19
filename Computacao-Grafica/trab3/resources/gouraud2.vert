void PointLight(in int i, in vec3 eye, in vec3 ecPosition3, in vec3 normal,
					inout vec4 ambient, 
					inout vec4 diffuse, 
					inout vec4 specular)
{
	float nDotVP;       // normal . light direction
	float nDotHV;		// normal . light half vector
	float pf;			// power factor
	float attenuation;  // computed attenuation factor
	float d;			// distance from surface to light source
	vec3 VP;			// direction from surface to light position
	vec3 halfVector;   // direction of maximum highlights
	
	//Compute vector from surface to light position
	VP = vec3(gl_LightSource[i].position) - ecPosition3;
	
	//Compute distance between surface and light position
	d= length(VP);
	
	//Normalize the vector from surface to light position
	VP = normalize(VP);
	
	//Compute attenuation
	attenuation = 1.0 - gl_LightSource[i].constantAttenuation +
						gl_LightSource[i].linearAttenuation * d +
						gl_LightSource[i].quadraticAttenuation * d*d;
						
	halfVector = normalize(VP + eye);
	
	nDotVP = max(0.0, dot(normal, VP));
	nDotHV = max(0.0, dot(normal, halfVector));
	
	if(nDotVP == 0.0)
		pf = 0.0;
	else
		pf = pow(nDotHV, gl_FrontMaterial.shininess);
		
	ambient += gl_LightSource[i].ambient * attenuation;
	diffuse += gl_LightSource[i].diffuse * nDotVP * attenuation;
	specular += gl_LightSource[i].specular * pf * attenuation;
}

void SpotLight(in int i, in vec3 eye, in vec3 ecPosition3, in vec3 normal,
					inout vec4 ambient, 
					inout vec4 diffuse, 
					inout vec4 specular)
{
	float nDotVP;       	// normal . light direction
	float nDotHV;			// normal . light half vector
	float pf;				// power factor
	float spotDot;			// cosine of angle between spotlight
	float spotAttenuation;	// spotlight attenuation factor
	float attenuation;  	// computed attenuation factor
	float d;				// distance from surface to light source
	vec3 VP;				// direction from surface to light position
	vec3 halfVector;   	// direction of maximum highlights
	
	//Compute vector from surface to light position
	VP = vec3(gl_LightSource[i].position) - ecPosition3;
	
	//Compute distance between surface and light position
	d= length(VP);
	
	//Normalize the vector from surface to light position
	VP = normalize(VP);
	
	//Compute attenuation
	attenuation = 1.0 - gl_LightSource[i].constantAttenuation +
						gl_LightSource[i].linearAttenuation * d +
						gl_LightSource[i].quadraticAttenuation * d*d;
						
	// See if point on surface is inside cone of illumination
	spotDot = dot(-VP, normalize(gl_LightSource[i].spotDirection));
	
	if(spotDot < gl_LightSource[i].spotCosCutoff)
		spotAttenuation = 0.0;
	else
		spotAttenuation = pow(spotDot, gl_LightSource[i].spotExponent);
		
	// Combine the spotLight and distance attenuation
	attenuation *= spotAttenuation;
						
	halfVector = normalize(VP + eye);
	
	nDotVP = max(0.0, dot(normal, VP));
	nDotHV = max(0.0, dot(normal, halfVector));
	
	if(nDotVP == 0.0)
		pf = 0.0;
	else
		pf = pow(nDotHV, gl_FrontMaterial.shininess);
		
	ambient += gl_LightSource[i].ambient * attenuation;
	diffuse += gl_LightSource[i].diffuse * nDotVP * attenuation;
	specular += gl_LightSource[i].specular * pf * attenuation;
}

void DirectionalLight(in int i, in vec3 normal, 
						inout vec4 ambient,
						inout vec4 diffuse,
						inout vec4 specular)
{
	float nDotVP;       // normal . light direction
	float nDotHV;		// normal . light half vector
	float pf;			// power factor
	
	nDotVP = max(0.0, dot(normal, normalize(vec3(gl_LightSource[i].position))));
	nDotHV = max(0.0, dot(normal, vec3(gl_LightSource[i].halfVector)));
	
	if(nDotVP == 0.0)
		pf = 0.0;
	else
		pf = pow(nDotHV, gl_FrontMaterial.shininess);
	
	ambient  += gl_LightSource[i].ambient;
	diffuse  += gl_LightSource[i].diffuse * nDotVP;
	specular += gl_LightSource[i].specular * pf;
}

const int NumEnabledLights = 1;
const bool LocalViewer = false; 

vec4 computFrontColor()
{
	vec3 eye;
	vec4 color;
	vec4 ecPosition = gl_ModelViewMatrix * gl_Vertex;
	vec3 ecPosition3 = vec3(ecPosition) / ecPosition.w;
	vec3 normal      = normalize(gl_NormalMatrix * gl_Normal);
		
	if(LocalViewer)
		eye = -normalize(ecPosition3);
	else
		eye = vec3(0.0, 0.0, -1.0);
		
	// Clear the light intensity accumulators
	vec4 amb  = vec4(0.0);
	vec4 diff = vec4(0.0);
	vec4 spec = vec4(0.0);
	
	// Look through enabled lights, comput contribution from each
	for(int i = 0; i < NumEnabledLights; i++)
	{
		if(gl_LightSource[i].position.w == 0.0)
			DirectionalLight(i, normal, amb, diff, spec);
		else if(gl_LightSource[i].spotCutoff == 180.0)
			PointLight(i, eye, ecPosition3, normal, amb, diff, spec);
		else
			SpotLight(i, eye, ecPosition3, normal, amb, diff, spec);
	}
	
	// Surface color computation, omitting the specular contribuition
	color = gl_FrontLightModelProduct.sceneColor +
			amb  * gl_FrontMaterial.ambient +
			diff * gl_FrontMaterial.diffuse;
			
	// Final surface color computation
	//if(SeparateSpecular)
	//	gl_FrontSecundaryColor = vec4(spec * gl_FrontMaterial.specular, 1.0);
	//else
		color += spec * gl_FrontMaterial.specular;
		
	return color;
}

void main()
{
	gl_FrontColor = computFrontColor();

 	gl_Position = ftransform();
}
