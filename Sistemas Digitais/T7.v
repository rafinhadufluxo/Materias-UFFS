module calc(
    input [10:0] p1x,
    input [10:0] p1y,
    input [10:0] p2x,
    input [10:0] p2y,
    input [10:0] p3x,
    input [10:0] p3y,
    output result
);

//result = (((p1.x - p3.x)*(p2.y - p3.y)) - ((p2.x - p3.x)*(p1.y - p3.y)));

wire signed [11:0] s1;
wire signed [11:0] s2;
wire signed [11:0] s3;
wire signed [11:0] s4;
wire signed [23:0] m1;
wire signed [23:0] m2;

assign s1 = p1x - p3x;
assign s2 = p2y - p3y;
assign s3 = p2x - p3x;
assign s4 = p1y - p3y;
assign m1 = s1 * s2;
assign m2 = s3 * s4;
assign result = m1 > m2;

endmodule

module videoMemoy(
	input wr,
	input [10:0] pos_x,
	input [10:0] pos_y,
	input [3:0] Red_in,
	input [3:0] Green_in,
	input [3:0] Blue_in,
	output [3:0] Red_out,
	output [3:0] Green_out,
	output [3:0] Blue_out
	);

	reg [11:0] mem [640:1][480:1];
	//307200 registradores de 12 bits ordenados em 640 linhas e 480 colunas.

	always @(posedge wr) begin
		if (wr == 1) begin
			mem[pos_x][pos_y][3:0] <= Red_in;
			mem[pos_x][pos_y][7:4] <= Green_in;
			mem[pos_x][pos_y][11:8] <= Blue_in;
		end
	end

	assign Red_out = mem[pos_x][pos_y][3:0];
	assign Green_out = mem[pos_x][pos_y][7:4];
	assign Blue_out = mem[pos_x][pos_y][11:8];

endmodule

module teste1;

reg clk = 0;
reg fim = 0;
reg wr;
reg [4:0] state = 0;
reg [10:0] pos_x;
reg [10:0] pos_y;
reg [4:0] triangulo;

reg [10:0] p1x;
reg [10:0] p1y;
reg [10:0] p2x;
reg [10:0] p2y;
reg [10:0] p3x;
reg [10:0] p3y;
reg [10:0] Px;
reg [10:0] Py;


reg [3:0] Red_in;
reg [3:0] Green_in;
reg [3:0] Blue_in;

wire [3:0] Red_out;
wire [3:0] Green_out;
wire [3:0] Blue_out;

wire t1, s1, s2, s3;

videoMemoy M(wr, pos_x, pos_y, Red_in, Green_in, Blue_in, Red_out, Green_out, Blue_out);

calc S1(p1x, p1y, p2x, p2y, p3x, p3y, t1);
calc S2(p1x, p1y, p2x, p2y, Px, Py, s1);
calc S3(p2x, p2y, p3x, p3y, Px, Py, s2);
calc S4(p3x, p3y, p1x, p1y, Px, Py, s3);

always #1 clk = ~clk;
always @(posedge clk) begin
	case(state)
	0: begin
		wr <= 0;
		pos_x <= 0;
		pos_y <= 0;
		triangulo <= 0;
		state <= 1;
	end
	1: begin
		p1x <= {$random} %639;
		p2x <= {$random} %639;
		p3x <= {$random} %639;
		p1y <= {$random} %479;
		p2y <= {$random} %479;
		p3y <= {$random} %479;

		Px <= 0;
		Py <= 0;
		triangulo <= triangulo + 1;
		state <= 2;
	end
	2: begin
		if (triangulo == 5) state <= 11;
		else begin
			if(Px < 640) begin
				Px <= Px + 1;
				state <= 3;
			end
			else state <= 6;
		end
	end
	3: begin
		if(Py < 480) begin
			Py <= Py + 1;
			state <= 4;
		end
		else begin
			Py <= 0;
			state <= 2;
		end
	end
	4: begin
		pos_x <= Px;
		pos_y <= Py;
		if (((t1 == s1) && (s1 == s2) && (s2 == s3))) begin
			case(triangulo)
			1: begin
				Red_in <= 4'b1111;
				Green_in <= 4'b0000;
				Blue_in <= 4'b0000;
			end
			2: begin
				Red_in <= 4'b0000;
				Green_in <= 4'b1111;
				Blue_in <= 4'b0000;
			end
			3: begin
				Red_in <= 4'b0000;
				Green_in <= 4'b0000;
				Blue_in <= 4'b1111;
			end
			4: begin
				Red_in <= 4'b1111;
				Green_in <= 4'b1111;
				Blue_in <= 4'b1111;
			end
			endcase
		end
		else begin
			Red_in <= 4'b0000;
			Green_in <= 4'b0000;
			Blue_in <= 4'b0000;
		end
		wr <= 1;
		state <= 5;
	end
	5: begin
		wr <= 0;
		state <= 3;
	end
	6: begin
		Px <= 0;
		Py <= 0;
		state <= 7;
	end
	7: begin
		if(Px < 640) begin
			Px <= Px + 1;
			state <= 8;
		end
		else state <= 1;
	end
	8: begin
		if(Py < 480) begin
			Py <= Py + 1;
			state <= 9;
		end
		else begin
			Py <= 0;
			state <= 7;
		end
	end
	9: begin
		pos_x <= Px;
		pos_y <= Py;
		state <= 10;
	end
	10: begin
		$display("\nTriangulo%d Mem[%d][%d] = R%d G%d B%d\n", triangulo, pos_x, pos_y, Red_out, Green_out, Blue_out);
		state <= 8;
	end
	11: $finish;
	endcase
end


endmodule

