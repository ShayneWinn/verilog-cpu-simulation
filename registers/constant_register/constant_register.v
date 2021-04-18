module constant_register
    (
    input  [7:0] b_data,
    output [7:0] b_main,

    input i_load,
    input i_assert,

    output reg [7:0] data
    );

    assign b_main = i_assert ? data : 8'z;

    always @(negedge i_load) begin
        data <= b_data;
    end

endmodule
