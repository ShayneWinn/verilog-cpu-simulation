// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vregister_testbench__Syms.h"
#include "Vregister_testbench.h"



// FUNCTIONS
Vregister_testbench__Syms::~Vregister_testbench__Syms()
{
}

Vregister_testbench__Syms::Vregister_testbench__Syms(VerilatedContext* contextp, Vregister_testbench* topp, const char* namep)
    // Setup locals
    : VerilatedSyms{contextp}
    , __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
}
