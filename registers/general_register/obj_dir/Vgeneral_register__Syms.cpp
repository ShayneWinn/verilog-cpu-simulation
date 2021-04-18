// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vgeneral_register__Syms.h"
#include "Vgeneral_register.h"



// FUNCTIONS
Vgeneral_register__Syms::~Vgeneral_register__Syms()
{
}

Vgeneral_register__Syms::Vgeneral_register__Syms(VerilatedContext* contextp, Vgeneral_register* topp, const char* namep)
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
