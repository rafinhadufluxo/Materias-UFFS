varying float LightIntensity;
varying vec2 MCposition;

void main()
{
	vec3 BrickColor = vec3 (1.0,0.3, 0.2);
	vec3 MortarColor = vec3 (0.85, 0.86, 0.84);
	vec2 BrickSize = vec2(0.3, 0.15);
	vec2 BrickPct = vec2(0.9, 0.85);

	vec3 color = vec3(1.0,1.0,1.0);
	vec2 position, useBrick;
	
	position = MCposition / BrickSize;
	
	if(fract(position.y * 0.5) > 0.5)
		position.x += 0.5;

	position = fract(position);

	useBrick = step(position, BrickPct);

	color = mix(MortarColor, BrickColor, useBrick.x * useBrick.y);
	color *= (0.1 + LightIntensity);

	gl_FragColor = vec4(MortarColor, 1.0);	
}