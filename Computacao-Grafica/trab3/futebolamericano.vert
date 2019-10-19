varying float difusa;

void main() {
   vec4 v = gl_Vertex;
	vec3 normal = gl_Vertex.xyz;    
	vec3 luz = gl_LightSource[0].position.xyz;
	
	//ALTERA O FORMATO DA ESFERA PARA ELIPSOIDE
	v.x = v.x/2.0;
	v.y = v.y/2.0;
	normal = gl_NormalMatrix * normal;

	vec4 preto = vec4(0.0, 0.0, 0.0, 1.0);
	vec3 dir_luz = normalize(luz - v.xyz);

	//DIFUSA
	difusa = dot(normal, dir_luz);
	difusa = max(difusa, 0.0);

	//DIFUSA
	//vec3 cor_final = (difusa * preto.xyz);
	vec3 cor_final = preto.xyz;
	
	//APLICA A COR FINAL
	gl_FrontColor.xyz = cor_final;
	gl_FrontColor.w = 1.0;
	gl_Position = gl_ModelViewProjectionMatrix * v;

	//DEBUG
	//gl_FrontColor.xyz = v.xyz;
	//gl_FrontColor.xyz = vec3(kespecular);

	//FRAG
	gl_TexCoord[0] = gl_MultiTexCoord0;

}