// earth.vert

varying float Diffuse;
varying vec3  Specular;
varying vec2  TexCoord;

const vec4 LightPosition = vec4(0.0, 10.0, 4.0, 1.0);

void main(void)
{
    vec4 ecPosition = gl_ModelViewMatrix * gl_Vertex;
    vec3 tnorm      = normalize(gl_NormalMatrix * gl_Normal);
    //vec3 lightVec   = normalize(LightPosition - vec3 (ecPosition));
    vec3 lightVec   = normalize((gl_ModelViewMatrix*LightPosition).xyz - vec3 (ecPosition));
    vec3 reflectVec = reflect(-lightVec, tnorm);
    vec3 viewVec    = normalize(vec3 (-ecPosition));

    float spec      = clamp(dot(reflectVec, viewVec), 0.0, 1.0);
    spec            = pow(spec, 8.0);
    Specular        = vec3 (spec) * vec3 (1.0, 0.941, 0.898) * 0.3;

    Diffuse         = dot(lightVec, tnorm);

    TexCoord        = vec2 (gl_MultiTexCoord0);
    gl_Position     = gl_ModelViewProjectionMatrix * gl_Vertex;
}
