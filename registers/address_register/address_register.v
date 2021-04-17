// address register with twp busses:
//      transfer bus: can read and write fromthis bus, used to transfer values between devices
//      address bus: output only connects directly to RAM/ROM
//
//      i_load_transfer: rising edge tells register to latch what's on the transfer bus
//      i_assert_transfer: asyncrynous signal telling register to assert to transfer bus
//      i_assert_address: asyncrynous signal telling register to assert to address bus
//      i_inc: rising edge tells register to increment value
//      i_dec: rising edge tells register to decrement value
module address_register
    (
    input   i_load_transfer,
    input   i_assert_transfer,
    input   i_assert_address,

    input   i_inc,
    input   i_dec,

    inout wire [15:0] transfer_bus,
    output wire [15:0] address_bus,

    output reg [15:0] data
    );

    initial begin
        data = 16'b0000000000000000;
    end

    assign  transfer_bus = i_assert_transfer ? data : 16'bzzzzzzzzzzzzzzzz;
    assign  address_bus = i_assert_address? data : 16'bzzzzzzzzzzzzzzzz;

    always @(posedge i_load_transfer or posedge i_inc or posedge i_dec) begin
        if(i_load_transfer) begin
            data <= transfer_bus;
        end
        else if (i_inc) begin
            data <= data + 1;
        end
        else if (i_dec) begin
            data <= data - 1;
        end
    end
    
endmodule
