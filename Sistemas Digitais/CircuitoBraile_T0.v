module alfabeto(
	input CLOCK_50,
	input [5:0] let,
	output [6:0] hexa);
	
	reg [6:0] h;
	assign hexa = (h);

	always @(posedge CLOCK_50) begin
		if (let == 6'b000001) begin
			h = 7'b1110111; //A
		end
		else if (let == 6'b000011) begin
			h = 7'b0011111; //B
		end
		else if (let == 6'b100001) begin
			h = 7'b1001110; //C
 		end
		else if (let == 6'b110001) begin
			h = 7'b0111101; //D
		end
		else if (let == 6'b010001) begin
			h = 7'b1001111; //E
		end
		else if (let == 6'b100011) begin
			h = 7'b1000111; //F
		end
		else if (let == 6'b110011) begin
			h = 7'b1111011; //G
		end
		else if (let == 6'b010011) begin
			h = 7'b0110111; //H
		end
		else if (let == 6'b100010) begin
			h = 7'b0000110; //I
		end
		else if (let == 6'b110010) begin
			h = 7'b0111100; //J
		end
		else if (let == 6'b000101) begin
			h = 7'b0101111; //K
		end
		else if (let == 6'b000111) begin
			h = 7'b0001110; //L
		end
		else if (let == 6'b100101) begin
			h = 7'b1110110; //M
		end
		else if (let == 6'b110101) begin
			h = 7'b0010101; //N
		end
		else if (let == 6'b010101) begin
			h = 7'b1111110; //O
		end
		else if (let == 6'b100111) begin
			h = 7'b1100111; //P
		end
		else if (let == 6'b110111) begin
			h = 7'b1110011; //Q
		end
		else if (let == 6'b010111) begin
			h = 7'b0000101; //R
		end
		else if (let == 6'b100110) begin
			h = 7'b1011011; //S
		end
		else if (let == 6'b110110) begin
			h = 7'b0001111; //T
		end
		else if (let == 6'b001101) begin
			h = 7'b0011100; //U
		end
		else if (let == 6'b001111) begin
			h = 7'b0111110; //V
		end
		else if (let == 'b111010) begin
			h = 7'b1011100; //W
		end
		else if (let == 'b101101) begin
			h = 7'b0000111; //X
		end
		else if (let == 6'b111101) begin
			h = 7'b0111011; //Y
		end
		else if (let == 6'b011101) begin
			h = 7'b1001001; //Z
		end
		else begin
			h = 7'b0000000; //0
		end
	end

endmodule

module braile(
	input CLOCK_50,
	input [10:4] SW,
	output [0:6] HEX0,
	output [0:6] HEX1,
	output [0:6] HEX2,
	output [0:6] HEX3);
		
	wire[6:0] bra;
	reg[6:0] offreg = 7'b0000000;
	wire[6:0] off;
	
	assign off = offreg;
	
	reg [5:0] letra = 6'b000000;
	assign HEX0 = ~bra;
	assign HEX1 = ~off;
	assign HEX2 = ~off;
	assign HEX3 = ~off;
	
	alfabeto B(CLOCK_50, SW, bra);

endmodule // braile
