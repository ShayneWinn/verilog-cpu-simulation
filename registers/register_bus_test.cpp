#include <stdio.h>

#include "Vregister_testbench.h" // generated from tb.v

void clock_tick(Vregister_testbench* testBench){
    testBench->eval();
    testBench->clk = 1;
    testBench->eval();
    testBench->clk = 0;
    testBench->eval();
}

void print_status(Vregister_testbench* testBench){
    printf("RegisterA: %u\n", testBench->regA_data);
    printf("RegisterB: %u\n", testBench->regB_data);
    printf("RegisterC: %u\n", testBench->regC_data);
    printf("RegisterD: %u\n", testBench->regD_data);
}

int main(int argc, char** argv, char** env){
    printf("RUNNING TESTS...\n");
    //run_constant_register_tests();

    Vregister_testbench* testBench = new Vregister_testbench();
    testBench->eval();

    print_status(testBench);
    printf("\n\n");

    // load A and B with 0
    printf("Initialize Values\n");
    // laod const with 0
    testBench->i_bus_in = 0;
    testBench->i_8bit_load_word = 1;
    clock_tick(testBench);
    // transfer to all other registers
    testBench->i_8bit_assert_word = 1;
    testBench->i_8bit_load_word = 2;
    clock_tick(testBench);
    testBench->i_8bit_load_word = 3;
    clock_tick(testBench);
    testBench->i_8bit_load_word = 4;
    clock_tick(testBench);
    testBench->i_8bit_load_word = 5;
    clock_tick(testBench);
    print_status(testBench);
    printf("\n\n");

    // reset
    testBench->i_8bit_load_word = 0;
    testBench->i_8bit_assert_word = 0;

    // load A with 170
    printf("Load A with 0xaa (170)\n");
    // load const with 170
    testBench->i_8bit_load_word = 1;
    testBench->i_bus_in = 170;
    clock_tick(testBench);
    // transfer to A
    testBench->i_8bit_assert_word = 1;
    testBench->i_8bit_load_word = 2;
    clock_tick(testBench);
    print_status(testBench);
    printf("\n\n");

    // reset
    testBench->i_8bit_load_word = 0;
    testBench->i_8bit_assert_word = 0;

    // transfer A to B
    printf("Transfer A->B\n");
    testBench->i_8bit_load_word = 3;
    testBench->i_8bit_assert_word = 2;
    clock_tick(testBench);
    print_status(testBench);
    printf("\n\n");

    // reset
    testBench->i_8bit_load_word = 0;
    testBench->i_8bit_assert_word = 0;

    // load B with 102
    printf("Load B with 0x66 (102)\n");
    // load const with 102
    testBench->i_8bit_load_word = 1;
    testBench->i_bus_in = 102;
    clock_tick(testBench);
    // transfer to B
    testBench->i_8bit_assert_word = 1;
    testBench->i_8bit_load_word = 3;
    clock_tick(testBench);
    print_status(testBench);
    printf("\n\n");

    // reset
    testBench->i_8bit_load_word = 0;
    testBench->i_8bit_assert_word = 0;

    // transfer B to C
    printf("Transfer B->C\n");
    testBench->i_8bit_load_word = 4;
    testBench->i_8bit_assert_word = 3;
    clock_tick(testBench);
    print_status(testBench);
    printf("\n\n");

    // reset
    testBench->i_8bit_load_word = 0;
    testBench->i_8bit_assert_word = 0;

    // load C with 255
    printf("Load C with 0xff (102)\n");
    // load const with 255
    testBench->i_8bit_load_word = 1;
    testBench->i_bus_in = 255;
    clock_tick(testBench);
    // transfer to C
    testBench->i_8bit_assert_word = 1;
    testBench->i_8bit_load_word = 4;
    clock_tick(testBench);
    print_status(testBench);
    printf("\n\n");

    // reset
    testBench->i_8bit_load_word = 0;
    testBench->i_8bit_assert_word = 0;

    // transfer C to D
    printf("Transfer C->D\n");
    testBench->i_8bit_load_word = 5;
    testBench->i_8bit_assert_word = 4;
    clock_tick(testBench);
    print_status(testBench);
    printf("\n\n");
}
