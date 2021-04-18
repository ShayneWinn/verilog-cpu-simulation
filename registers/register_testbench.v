`include "address_register/address_register.v"
`include "general_register/general_register.v"
`include "constant_register/constant_register.v"

// module used for register testing
// very similar to the eventual bus-control board
module register_testbench
    (
    // clock
    input wire  clk,

    // control words
    input reg [4:0] i_8bit_assert_word,     // can handle 15 devices and nothing
    input reg [4:0] i_8bit_load_word,       // can handle 15 devices and nothing
    input reg [3:0] i_16bit_assert_word,    // can handle 7 devices and nothing
    input reg [3:0] i_16bit_load_word,      // can handle 7 devices and nothing

    // used to assert to bus (control word 0)
    input reg [7:0] i_bus_in,

    // all busses
    output wire [7:0]  b_8bit_main,
    output wire [7:0]  b_8bit_left,
    output wire [7:0]  b_8bit_right,
    output wire [16:0] b_16bit_transfer,
    output wire [16:0] b_16bit_address,

    // data used to view registers
    output reg [7:0] regA_data,
    output wire[7:0] regB_data,
    output wire[7:0] regC_data,
    output wire[7:0] regD_data
    );

    // Control wires
        // General registers
        // A
        wire      ctl_regA_assert_main;
        wire      ctl_regA_assert_left;
        wire      ctl_regA_assert_right;
        wire      ctl_regA_load;
        // B
        wire      ctl_regB_assert_main;
        wire      ctl_regB_assert_left;
        wire      ctl_regB_assert_right;
        wire      ctl_regB_load;
        // C
        wire      ctl_regC_assert_main;
        wire      ctl_regC_assert_left;
        wire      ctl_regC_assert_right;
        wire      ctl_regC_load;
        // D
        wire      ctl_regD_assert_main;
        wire      ctl_regD_assert_left;
        wire      ctl_regD_assert_right;
        wire      ctl_regD_load;
        // Constant
        wire      ctl_const_assert;
        wire      ctl_const_load;

        // Assignments
        assign ctl_const_assert = i_8bit_assert_word == 1;
        assign ctl_regA_assert_main = i_8bit_assert_word == 2;
        assign ctl_regB_assert_main = i_8bit_assert_word == 3;
        assign ctl_regC_assert_main = i_8bit_assert_word == 4;
        assign ctl_regD_assert_main = i_8bit_assert_word == 5;

        assign ctl_const_load = (i_8bit_load_word == 1) & clk;
        assign ctl_regA_load = (i_8bit_load_word == 2) & clk;
        assign ctl_regB_load = (i_8bit_load_word == 3) & clk;
        assign ctl_regC_load = (i_8bit_load_word == 4) & clk;
        assign ctl_regD_load = (i_8bit_load_word == 5) & clk;

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

        general_register regC
        (
            ctl_regC_load,
            ctl_regC_assert_main,
            ctl_regC_assert_left,
            ctl_regC_assert_right,

            b_8bit_main,
            b_8bit_left,
            b_8bit_right,
            regC_data
        );

        general_register regD
        (
            ctl_regD_load,
            ctl_regD_assert_main,
            ctl_regD_assert_left,
            ctl_regD_assert_right,

            b_8bit_main,
            b_8bit_left,
            b_8bit_right,
            regD_data
        );

        constant_register constant
        (
            i_bus_in,
            b_8bit_main,
            ctl_const_load,
            ctl_const_assert,
            .data()
        );

endmodule