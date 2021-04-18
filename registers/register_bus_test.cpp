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
}

int main(int argc, char** argv, char** env){
    Vregister_testbench* testBench = new Vregister_testbench();
    testBench->eval();

    print_status(testBench);
    printf("\n\n");

    // load A and B with 0
    printf("Initialize Values\n");
    testBench->i_bus_in = 0;
    testBench->i_8bit_load_word = 1;
    clock_tick(testBench);
    testBench->i_8bit_load_word = 2;
    clock_tick(testBench);
    print_status(testBench);
    printf("\n\n");

    // reset
    testBench->i_8bit_load_word = 0;

    // load A with 170
    printf("Load A with 0xaa (170)\n");
    testBench->i_8bit_assert_word = 0;
    testBench->i_8bit_load_word = 1;
    testBench->i_bus_in = 170;
    clock_tick(testBench);
    print_status(testBench);
    printf("\n\n");

    // transfer A to B
    printf("Transfer A->B\n");
    testBench->i_8bit_load_word = 2;
    testBench->i_8bit_assert_word = 1;
    clock_tick(testBench);
    print_status(testBench);
    printf("\n\n");

    // load B with 102
    printf("Load B with 0x66 (102)\n");
    testBench->i_8bit_assert_word = 0;
    testBench->i_8bit_load_word = 2;
    testBench->i_bus_in = 102;
    clock_tick(testBench);
    print_status(testBench);
    printf("\n\n");

    // transfer B to A
    printf("Transfer B->A\n");
    testBench->i_8bit_load_word = 1;
    testBench->i_8bit_assert_word = 2;
    clock_tick(testBench);
    print_status(testBench);
    printf("\n\n");
}
