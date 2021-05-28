module sinal(
    input [11:0] p1X,
    input [11:0] p1Y,
    input [11:0] p2X,
    input [11:0] p2Y,
    input [11:0] pToX,
    input [11:0] pToY,
    
    output s
);

    wire signed [11:0] sub1;
    wire signed [11:0] sub2;
    wire signed [11:0] sub3;
    wire signed [11:0] sub4;
    wire signed [22:0] sub5;

    wire signed [22:0] mul1;
    wire signed [22:0] mul2;

    assign sub1 = pToX - p2X;
    assign sub2 = p1Y - p2Y;
    assign sub3 = p1X - p2X;
    assign sub4 = pToY - p2Y;
    assign mul1 = sub1 * sub2;
    assign mul2 = sub3 * sub4;
    assign sub5 = mul1 - mul2;

    assign s = (sub5 >= 0) ? 1 : 0;
endmodule


module testeTri(
    input [11:0] p1X,
    input [11:0] p1Y,

    input [11:0] p2X,
    input [11:0] p2Y,

    input [11:0] p3X,
    input [11:0] p3Y,

    input [11:0] pTX,
    input [11:0] pTY,
    output in
    );

    wire sl1;
    wire sl2;
    wire sl3;
    assign in = (sl1 == 1 && sl2 == 1 && sl3 == 1) ? 1 : 0;

    sinal S1(p1X, p1Y, p2X, p2Y, pToX, pToY, sl1);
    sinal S2(p2X, p2Y, p3X, p3Y, pToX, pToY, sl2);
    sinal S3(p3X, p3Y, p1X, p1Y, pToX, pToY, sl3);

endmodule

module teste;
    reg [11:0] p1X;
    reg [11:0] p1Y;
    reg [11:0] p2X;
    reg [11:0] p2Y;
    reg [11:0] p3X;
    reg [11:0] p3Y;
    reg [11:0] pToX;
    reg [11:0] pToY;

    wire In;

