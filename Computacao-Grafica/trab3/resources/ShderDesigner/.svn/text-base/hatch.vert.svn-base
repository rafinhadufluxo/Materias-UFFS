uniform vec3  LightPosition;
uniform int TIME_FROM_INIT;

varying vec3  opos;
varying float v;
varying float lightIntensity;
 
void main(void)
{
    float Time	    = float(TIME_FROM_INIT) /500.0;
    opos            = (vec3(gl_Vertex) + vec3(0.0, 0.0, Time)) * 0.2;
 
    vec3 pos        = vec3(gl_ModelViewMatrix * gl_Vertex);
    vec3 tnorm      = normalize(gl_NormalMatrix * gl_Normal);
    vec3 lightVec   = normalize(LightPosition - pos);

    lightIntensity = max(dot(lightVec, tnorm), 0.0);

    v = gl_MultiTexCoord0.s;  // try .s for vertical stripes

    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}
