// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VADDRESS_REGISTER__SYMS_H_
#define VERILATED_VADDRESS_REGISTER__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vaddress_register.h"

// SYMS CLASS
class Vaddress_register__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vaddress_register*             TOPp;
    
    // CREATORS
    Vaddress_register__Syms(VerilatedContext* contextp, Vaddress_register* topp, const char* namep);
    ~Vaddress_register__Syms();
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
