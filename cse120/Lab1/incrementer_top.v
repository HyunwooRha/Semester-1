// Test module for lab 0
`timescale 1ns/1ns          // set a realistic time scale for the simulation

module incrementer_top();

reg [3:0]in_a;              // the a input to the circuit
reg inc;                    // the inc input to the circuit
wire [3:0] sum;             // the y output
wire cry;                   // the cry output

integer index;              // index into the input/output arrays

initial    // all initial blocks run at start up...
begin
   inc = 1'b1;                                      // set the INC bit so it counts
   for ( index = 0 ; index < 16 ; index = index+1 ) // walk through the values
   begin
      in_a = index[3:0];            // the value to increment

      #10;                                // wait for propagation
      $display("a: ", in_a, " | inc: ", inc, " | sum: ", sum, " | cry: ", cry);
   end

   inc = 1'b0;     // make sure it doesn't count...
   for ( index = 0 ; index < 3 ; index = index+1 ) // walk through the values
   begin
      in_a = index[3:0];            // the value to increment

      #10;                                // wait for propagation
      $display("a: ", in_a, " | inc: ", inc, " | sum: ", sum, " | cry: ", cry);
   end

end

// this instantiates your design
incrementer incrementer(.a(in_a),.inc(inc),.y(sum),.cry(cry)); 

endmodule
