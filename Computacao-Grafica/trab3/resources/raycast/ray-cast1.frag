
varying vec3 vv;

const float r = 0.4;
const float shininess = 8.0;
const vec4 c1 = vec4(1.5,1.5,1.5,1.0);
const vec4 c2 = vec4(1.0,1.0,1.0,1.0);
const float specContrib = 0.25;
const float diffContrib = 0.45;
const float ambContrib = 0.3;

float distSphere(in vec3 center, in vec3 vv)
{
	float b = dot(vv, center);
	float c = dot(center, center) - r*r;

	float delta = b*b - c;

	return (b - sqrt(delta));
}

float intensity(in vec3 inter, in vec3 center, in vec3 vv)
{
	vec3 norm = normalize(inter - center);
	vec3 lv = normalize(gl_LightSource[0].position.xyz - inter);

	float diff = max(dot(norm, lv), 0.0);
	lv = normalize(reflect(lv, norm));
	float spec = pow(max(dot(vv,lv),0.0), shininess);

	return diff*diffContrib + spec*specContrib + ambContrib;
}

void main ()
{
	vec3 vv2 = normalize(vv);
	float t = -1.0;
	vec3 c;
	
	vec3 sphere1 = (gl_ModelViewMatrix * c1).xyz;
	vec3 sphere2 = (gl_ModelViewMatrix * c2).xyz;

	float t1 = distSphere(sphere1, vv2);
	if(t1 >= 0.0)
	{
		t = t1;
		c = sphere1;
	}
	float t2 = distSphere(sphere2, vv2);
	if(t2 >= 0.0)
	{
		t = t2;
		c = sphere2;
	}
	
	if(t < 0.0)
		discard;

	float inten = intensity(t*vv2,c, vv2);
	
	
	gl_FragColor = vec4(gl_Color.xyz * inten, 1.0);
}