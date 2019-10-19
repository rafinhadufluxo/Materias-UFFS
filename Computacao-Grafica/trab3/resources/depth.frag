void main(void)
{
    vec3 color = mix(vec3(1.0,0.0,0.0), vec3(0.0,1.0,0.0), gl_FragCoord.z);
    gl_FragColor = vec4(color, 1.0);
}

