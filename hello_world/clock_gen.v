module clock_gen
    (
    input       enable,
    output reg  clk
    );

    parameter FREQ = 1;     // in HZ
    parameter PHASE = 0;    // in degrees
    parameter DUTY = 50;    // in percentage

    real clk_pd     = 1.0 / (FREQ) * 1e9;   // convert to ns
    real clk_on     = DUTY/100.0 * clk_pd;
    real clk_off    = (100.0 - DUTY)/100.0 * clk_pd;
    real quarter    = clk_pd/4;
    real start_dly  = quarter * PHASE/90;

    reg  start_clk;

    always @(posedge enable or negedge enable) begin
        if (enable) begin
            #(start_dly) start_clk <= 1;
        end else begin
            #(start_dly) start_clk <= 0;
        end
    end 

    always @(posedge start_clk) begin
        if (start_clk) begin
            clk = 1;

            while (start_clk) begin
                #(clk_on)  clk = 0;
                #(clk_off) clk = 1;
            end

            clk = 0;
        end
    end

endmodule
