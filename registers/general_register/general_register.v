// general register with three busses:
//      transfer bus: can read and write fromthis bus, used to transfer values between devices
//      left bus: write only and heads directly to the ALU
//      right bus: write only and heads directly to the ALU
//
//      i_load_transfer: rising edge tells register to latch what's on the transfer bus
module general_register
    (
    input   i_load_transfer,
    input   i_assert_transfer,
    input   i_assert_left,
    input   i_assert_right,

    inout wire [7:0] transfer_bus,
    output wire [7:0] left_bus,
    output wire [7:0] right_bus,

    output reg [7:0] data
    );

    initial begin
        data = 8'b00000000;
    end

    assign  transfer_bus = i_assert_transfer ? data : 8'bzzzzzzzz;
    assign  left_bus = i_assert_left ? data : 8'bzzzzzzzz;
    assign  right_bus = i_assert_right ? data : 8'bzzzzzzzz;

    always @(posedge i_load_transfer) begin
        data <= transfer_bus;
    end
    
endmodule
