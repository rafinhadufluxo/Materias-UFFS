#extension GL_EXT_geometry_shader4 : enable
 
void main()
{
	int a;
 	for(int i = 0; i < gl_VerticesIn; ++i)
 	{
		//gl_FrontColor = gl_FrontColorIn[i];

      if(i == 0) gl_FrontColor = vec4(1.0, 0.0, 0.0, 1.0);
      else if(i == 1)	gl_FrontColor = vec4(0.0, 1.0, 0.0, 1.0);
      else gl_FrontColor = vec4(0.0, 0.0, 1.0, 1.0);

      
      // copy position
      gl_Position = gl_PositionIn[i];
 
      // done with the vertex
      
     EmitVertex();
    
  }
}
