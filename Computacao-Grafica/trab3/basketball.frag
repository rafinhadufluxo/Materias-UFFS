uniform sampler2D sampler2d0, sampler2d1, sampler2d2;
varying float difusa;
varying float kespecular;

void main()
{
	//Adiciona as texturas
	vec4 textura = texture2D(sampler2d2, gl_TexCoord[0].st);
	
	if((textura.r < 0.30) && (textura.g < 0.30) && (textura.b < 0.30)) {
		textura = texture2D(sampler2d0, gl_TexCoord[0].st) * texture2D(sampler2d1, 3.0 * gl_TexCoord[0].st);
	}

	//Se for o friso preto tem especular
	if((textura.r < 0.15) && (textura.g < 0.18) && (textura.b < 0.18)) {
		gl_FragColor = gl_Color + kespecular;
	} else {
		gl_FragColor = textura;
	}

	gl_FragColor = gl_Color + (gl_FragColor * difusa);
	
}

