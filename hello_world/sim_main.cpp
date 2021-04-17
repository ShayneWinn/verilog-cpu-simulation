#include <verilated.h>
#include <stdio.h>

#include "Vtb.h" // generated from tb.v

int main(int argc, char** argv, char** env){
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vtb* testBench = new Vtb{contextp};

    int clockPulses = 0;

    while(!contextp->gotFinish()){
        printf("Clock = %u\n", clockPulses);

        // clock rising
        testBench->clk = 1;
        testBench->eval();
        printf("    Counter = %X\n", testBench->counter);

        // clock falling
        testBench->clk = 0;
        testBench->eval();
        printf("    Counter = %X \n\n", testBench->counter);

        clockPulses++;
    }
    delete testBench;
    delete contextp;
    return 0;
}