module tb
    (
    input wire clk,

    output wire [7:0] counter
    );

    hello       u0(clk, counter);

    initial begin
        $display("Begin");
    end

    always @* begin
        if(counter == 255) begin
            $finish;
        end
    end

endmodule
