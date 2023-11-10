// Test module for lab 0
`timescale 1ns/1ns // set a realistic time scale for the simulation

module brainless_top();

wire [27:0] values;
reg [3:0]  inDataIn;
reg [3:0] inAddressBus;
reg inInvert;
reg inArith;
reg inPass;
reg inEnableAccumulator;
reg inAccumulatorToDataBus;
reg inReset;
reg inWrite;
reg inRead;

reg clk;

reg [3:0] exp_accum;
reg [3:0] exp_dataBus;
reg [3:0] exp_aluOut;

wire [3:0] accum;
wire [3:0] dataBus;
wire [3:0] aluOut;

reg [2:0] addr;
wire [3:0] num_tests;

integer index;

// Stimulus something
brainless_stim brainless_stim( .num_tests(num_tests), .values(values), .addr(addr));

// create a clock that has num_tests periods
initial begin
	clk <= 1'b0;
	for ( index = 0 ; index < num_tests ; index = index + 1 ) begin
		#5 clk <= 1'b1;
		#5 clk <= 1'b0;
	end
end

// Reset
initial begin
	addr <= 3'b0;
end

always @ ( negedge clk ) begin
	exp_accum <= values[27:24];
	exp_dataBus <= values[23:20];
	exp_aluOut <= values[19:16];

	 inDataIn <= values[15:12];
	inAddressBus <= values[11:8];
	inInvert <= values[7];
	inArith <= values[6];
	inPass <= values[5];
	inEnableAccumulator <= values[4];
	inAccumulatorToDataBus <= values[3];
	inReset <= values[2];
	inWrite <= values[1];
	inRead <= values[0];
end

always @ ( posedge clk ) begin
	addr <= addr + 3'b1;
end

always @ ( posedge clk ) begin
	#4; // wait for things to settle before checking...
	$display("dataIn: %b, addressBus: %b, invert: %b, arith: %b, pass: %b, enableAccumulator: %b, accumulatorToDataBus: %b, reset: %b, writeToRAM %b, readFromRAM: %b, accumulatorOut: %b, dataBus: %b, aluOut: %b",  inDataIn, inAddressBus, inInvert, inArith, inPass, inEnableAccumulator, inAccumulatorToDataBus, inReset, inWrite, inRead, accum, dataBus, aluOut);
	if ( accum != exp_accum )
		$display("Output mismatch for entry ",index," expected accum to be ",
	exp_accum," but got ", accum);
	if ( aluOut != exp_aluOut )
		$display("Output mismatch for entry ",index," expected aluOut to be ",
	exp_aluOut," but got ", aluOut);
	if ( dataBus != exp_dataBus )
		$display("Output mismatch for entry ",index," expected dataBus to be ",
	exp_dataBus," but got ", dataBus);
end

brainless brainless(.accumulatorOut(accum), .dataBus(dataBus), .aluOut(aluOut),
.dataIn( inDataIn), .addressBus(inAddressBus),
.invert(inInvert), .arith(inArith), .pass(inPass),
.enableAccumulator(load_acc), .accumulatorToDataBus(inAccumulatorToDataBus),
.writeToRAM(inWrite), .readFromRAM(inRead),
.clk(clk), .reset(inReset));

endmodule
