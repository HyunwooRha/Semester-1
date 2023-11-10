// Test module for lab 0
`timescale 1ms/1ps // For realtime simulation

module four_bit_reg_top();

	reg [3:0] in_d;
	reg in_enable;
	reg in_reset;
	reg clk;
	wire [3:0] q;
	integer index;
	integer limit = 10;
	reg [5:0] data;

	// Drive clock
	initial begin
		clk = 1'b0;
		#10000
		for ( index = 0 ; index < 50 ; index = index + 1 ) begin
			#100000 clk = ~clk;
		end
	end
	
	// New data and display new data
	always @ ( negedge clk ) begin
		data = ($urandom%38);
		in_reset = data[5];
		in_enable = data[4];
		in_d = data[3:0];
		#1 $display("Next values | Reset: %d", in_reset, " | Enable: %d", in_enable, " | D: %d", in_d);
	end

	// Show data after clock pulse
	always @ ( posedge clk ) begin
		#1 $display("Clock pulse | Q: %d", q);
	end
	
	// The student's design
	four_bit_reg four_bit_reg(.q(q), .d(in_d), .enable(in_enable), .clk(clk), .reset(in_reset));

endmodule
