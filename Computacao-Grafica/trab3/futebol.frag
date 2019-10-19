uniform sampler2D sampler2d0;
varying float difusa;
varying float kespecular;

void main()
{
	//Adiciona a textura
	vec4 textura = texture2D(sampler2d0, gl_TexCoord[0].st);	

	if((textura.r < 0.9) && (textura.r > 0.1)) {
		textura.r = 0.95;
		textura.g = 0.95;
		textura.b = 0.95;
	}

	if(textura.r < 0.1 && textura.g < 0.1 && textura.b < 0.1){
		gl_FragColor = gl_Color + (gl_Color * difusa) + kespecular;
	}else{
		gl_FragColor = gl_Color + (gl_Color + textura) * difusa; 
	}
	

}

