module hello
    (
    // inputs and registers
    input               i_clock,
    output reg [7:0]    count
    );

    // initialize count to 0
    initial begin
        count = 8'b00000000;
    end

    // when the clock's rising edge happens
    always @(negedge i_clock) begin
        count <= count + 1;
    end
endmodule
