varying vec3 vNormal;
varying vec3 vVertex;
uniform vec3 eyePos;
uniform vec3 lightPos;
#define shininess 20.0
void main (void)
{         

vec3 Normal = normalize(gl_NormalMatrix * vNormal);
vec3 EyeVert = normalize(eyePos - vVertex);
vec3 LightVert = normalize(lightPos - vVertex);
vec3 EyeLight = normalize(LightVert+EyeVert);
float sil = max(dot(Normal,EyeVert), 0.0);
if (sil < 0.3) gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
gl_FragColor = vec4(0.8, 0.0, 0.0, 1.0);
/*float spec = pow(max(dot(Normal,EyeLight),0.0), shininess);   
if (spec < 0.2) 
  gl_FragColor *= 0.8;
else 
  gl_FragColor = vec4(0.8, 0.0, 0.0, 1.0);
float diffuse = max(dot(Normal,LightVert),0.0);
if (diffuse < 0.5) 
  gl_FragColor *=0.8; */  
}
