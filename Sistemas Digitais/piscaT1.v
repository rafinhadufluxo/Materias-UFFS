module piscaled(
	input [0:0] KEY,
	input CLOCK_50,
	output reg [7:0] LEDG
);
always @(posedge CLOCK_50)begin

	if(KEY [0]==1)begin
		LEDG <= 8'hAA;
		
	end else begin 
		LEDG <= ~LEDG;
	end
	
end
	
	
endmodule
