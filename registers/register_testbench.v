`include "address_register/address_register.v"
`include "general_register/general_register.v"

// module used for register testing
// very similar to the eventual bus-control board
module register_testbench
    (
    input wire  clk,

    input reg [4:0] i_8bit_assert_word,     // can handle 15 devices and nothing
    input reg [4:0] i_8bit_load_word,       // can handle 15 devices and nothing
    input reg [3:0] i_16bit_assert_word,    // can handle 7 devices and nothing
    input reg [3:0] i_16bit_load_word,      // can handle 7 devices and nothing

    input reg [7:0] i_bus_in,

    output wire [7:0]  b_8bit_main,
    output wire [7:0]  b_8bit_left,
    output wire [7:0]  b_8bit_right,
    output wire [16:0] b_16bit_transfer,
    output wire [16:0] b_16bit_address,

    output reg [7:0] regA_data,
    output wire[7:0] regB_data,
    output wire[7:0] regC_data,
    output wire[7:0] regD_data
    );

    wire      ctl_regA_assert_main;
    wire      ctl_regA_assert_left;
    wire      ctl_regA_assert_right;
    wire      ctl_regA_load;

    wire      ctl_regB_assert_main;
    wire      ctl_regB_assert_left;
    wire      ctl_regB_assert_right;
    wire      ctl_regB_load;

    wire      ctl_regC_assert_main;
    wire      ctl_regC_assert_left;
    wire      ctl_regC_assert_right;
    wire      ctl_regC_load;

    wire      ctl_regD_assert_main;
    wire      ctl_regD_assert_left;
    wire      ctl_regD_assert_right;
    wire      ctl_regD_load;

    assign ctl_regA_assert_main = i_8bit_assert_word == 1;

    assign ctl_regA_load = (i_8bit_load_word == 1) & clk;
    assign ctl_regB_load = (i_8bit_load_word == 2) & clk;

    general_register regA
        (
        ctl_regA_load,
        ctl_regA_assert_main,
        ctl_regA_assert_left,
        ctl_regA_assert_right,

        b_8bit_main,
        b_8bit_left,
        b_8bit_right,
        regA_data
        );

    general_register regB
        (
        ctl_regB_load,
        ctl_regB_assert_main,
        ctl_regB_assert_left,
        ctl_regB_assert_right,

        b_8bit_main,
        b_8bit_left,
        b_8bit_right,
        regB_data
        );

    always @(i_8bit_assert_word) begin
        case (i_8bit_assert_word)
            1:;
            2:;
            default: begin
                b_8bit_main = i_bus_in;
            end 
        endcase
    end

endmodule