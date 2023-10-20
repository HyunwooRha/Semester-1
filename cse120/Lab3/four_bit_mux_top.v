// Student testbench module for four_bit_mux module
`timescale 1ns/1ns 

module four_bit_mux_top();

	reg [15:0] resp_data[0:7];  // Stimulus and response. This array is 8 rows and 16 columns
	reg [3:0] in_a;             // The a input to the circuit
	reg [3:0] in_b;             // The b input to the circuit
	reg in_s;                   // The s input to the circuit
	wire [3:0] out_y;           // the y output
	
	
	integer index;
	initial begin
		$readmemh("four_bit_mux_stim.txt",resp_data);  // Read inputs from stimulus file
	end
	
	initial begin
		// Test all stimulus
		for (index = 0; index < 8; index = index+1)	begin
			// Feed the modules the next input data
			{in_s,in_a,in_b} = resp_data[index][8:0];     // get the next inputs.
			
			// Wait for propogation
			#10;
			
			// Print out results
			$display("a: ", in_a, " | b: ", in_b, " | sel: ", in_s, " | y: ", out_y);
		end
	end

	// This instantiates your design
	four_bit_mux four_bit_mux(.a(in_a),.b(in_b),.sel(in_s), .y(out_y)); 

endmodule
