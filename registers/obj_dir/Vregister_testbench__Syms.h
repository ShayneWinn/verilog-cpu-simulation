// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VREGISTER_TESTBENCH__SYMS_H_
#define VERILATED_VREGISTER_TESTBENCH__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vregister_testbench.h"

// SYMS CLASS
class Vregister_testbench__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vregister_testbench*           TOPp;
    
    // CREATORS
    Vregister_testbench__Syms(VerilatedContext* contextp, Vregister_testbench* topp, const char* namep);
    ~Vregister_testbench__Syms();
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
