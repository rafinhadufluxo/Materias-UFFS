uniform sampler2D sampler2d0;
varying float difusa;
varying float kespecular;

void main()
{
	//Adiciona a textura
	vec4 textura = texture2D(sampler2d0, gl_TexCoord[0].st);	

	gl_FragColor = gl_Color + (gl_Color + textura) * difusa + kespecular;

}


