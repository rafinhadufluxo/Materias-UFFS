module somador(input clock,
	input [43:0] E1,
	input [43:0] E2,
	output[43:0] S0);
	
	reg [43:0] saida = 0;
	reg [43:0] aux = 0;
 	assign S0 = saida;
	always @(posedge clock) begin
		aux <= E1 + E2;
		saida = aux + saida; 
	end
endmodule

module teste;
	reg clock;
	reg[43:0] E1, E2;
	wire[43:0] S0;
	always #3 clock = ~clock;
	somador B(clock, E1, E2, S0);
	initial begin
		$dumpvars();
		#0 clock <= 0;
		E1 <= 2;
		E2 <= 2;
		//4
		#6
		E1 <= 4;
		E2 <= 4;
		//12
		#6
		E1 <= 5;
		E2 <= 5;
		//22
		#6
		E1 <= 3;
		E2 <= 3;
		//28
		#12	
		$finish;
	end
endmodule
