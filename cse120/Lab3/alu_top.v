// Student testbench module for four_bit_mux module
`timescale 1ns/1ns 

module four_bit_mux_top();

	reg [11:0] resp_data[0:5];  // Stimulus and response. This array is 5 rows and 12 columns
	reg [3:0] in_a;             // The a input to the circuit
	reg [3:0] in_b;             // The b input to the circuit
	reg in_invert;              // The s input to the circuit
	reg in_arith;               // The s input to the circuit
	reg in_cin;                 // The s input to the circuit
	reg in_pass;                // The s input to the circuit
	wire [3:0] out_y;           // the y output
	wire out_cout;        // the cout output
	wire out_overfl;      // the overfl output
	
	
	integer index;
	initial begin
		$readmemh("alu_stim.txt",resp_data);  // Read inputs from stimulus file
	end
	
	initial begin
		// Test all stimulus
		for (index = 0; index < 5; index = index+1)	begin
			// Feed the modules the next input data
			{in_invert,in_arith,in_cin,in_pass,in_a,in_b} = resp_data[index][11:0];     // get the next inputs.
			
			// Wait for propogation
			#10;
			
			// Print out results
			$display("a: %d", $signed(in_a), " | b: %d", $signed(in_b), " | invert: %d", in_invert, " | arith: %d", in_arith, " | cin: %d", in_cin, " | pass: %d", in_pass, " | y: %d", $signed(out_y), " | cout: %d", out_cout, " | overfl: %d", out_overfl);
		end
	end

	// This instantiates your design
	alu alu(.a(in_a), .b(in_b), .invert(in_invert), .arith(in_arith), .cin(in_cin), .pass(in_pass), .y(out_y), .cout(out_cout), .overfl(out_overfl)); 

endmodule
