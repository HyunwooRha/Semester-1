/*
 * Generated by Digital. Don't modify this file!
 * Any changes will be lost if this file is regenerated.
 */

module half_adder (
  input a,
  input b,
  output sum,
  output cry
);
  assign sum = (a ^ b);
  assign cry = (a & b);
endmodule

module incrementer (
  input [3:0] a,
  input inc,
  output [3:0] y,
  output cry
);
  wire s0;
  wire s1;
  wire s2;
  wire s3;
  wire s4;
  wire s5;
  wire s6;
  wire s7;
  wire s8;
  wire s9;
  wire s10;
  assign s0 = a[3];
  assign s3 = a[2];
  assign s4 = a[1];
  assign s5 = a[0];
  half_adder half_adder_i0 (
    .a( s5 ),
    .b( inc ),
    .sum( s10 ),
    .cry( s8 )
  );
  half_adder half_adder_i1 (
    .a( s4 ),
    .b( s8 ),
    .sum( s9 ),
    .cry( s6 )
  );
  half_adder half_adder_i2 (
    .a( s3 ),
    .b( s6 ),
    .sum( s7 ),
    .cry( s1 )
  );
  half_adder half_adder_i3 (
    .a( s0 ),
    .b( s1 ),
    .sum( s2 ),
    .cry( cry )
  );
  assign y[3] = s2;
  assign y[2] = s7;
  assign y[1] = s9;
  assign y[0] = s10;
endmodule