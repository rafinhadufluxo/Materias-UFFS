void main() {
    vec4 v = gl_Vertex;
    v.x *= 1.0;
	 gl_FrontColor = vec4(1.0, 0.0, 0.0, 1.0);
    gl_Position = gl_ModelViewProjectionMatrix * v;
}