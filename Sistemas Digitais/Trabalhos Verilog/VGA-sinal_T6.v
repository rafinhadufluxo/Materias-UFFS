module vga (
  	input CLOCK_50,
  	output [3:0] VGA_R,
  	output [3:0] VGA_G,
	output [3:0] VGA_B,
 	output VGA_HS,
	output VGA_VS);

reg [10:0] cx = 0;
reg [9:0]  cy = 0;

assign VGA_R = v ? 4'hf : 4'b0;
assign VGA_G = v ? 4'hf : 4'b0;
assign VGA_B = v ? 4'hf : 4'b0;

wire v = (cx >= 285) & (cx < 1555) & (cy >= 35) & (cy < 515);

assign VGA_HS = cx >= 190;
assign VGA_VS = cy >= 2;

always @(posedge CLOCK_50) begin
	if (cx == 1585) 
    begin
        if (cy == 525) begin
			cy <= 0;
        end
		else 
			cy <= cy + 1;
		cx <= 0;
	end
    else 
    begin
        // cy <= cy;
		cx <= cx + 1;
    end
end


endmodul
