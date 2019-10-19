varying vec3 tnorm;
varying vec3 lightVec;
varying vec4 cor;

void main()
{
	float diffuse  = dot(lightVec,tnorm);
	gl_FragColor = gl_LightSource[0].diffuse * cor * diffuse;
}