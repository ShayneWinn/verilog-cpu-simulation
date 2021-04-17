// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vaddress_register__Syms.h"
#include "Vaddress_register.h"



// FUNCTIONS
Vaddress_register__Syms::~Vaddress_register__Syms()
{
}

Vaddress_register__Syms::Vaddress_register__Syms(VerilatedContext* contextp, Vaddress_register* topp, const char* namep)
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
