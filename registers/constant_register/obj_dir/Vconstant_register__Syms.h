// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCONSTANT_REGISTER__SYMS_H_
#define VERILATED_VCONSTANT_REGISTER__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vconstant_register.h"

// SYMS CLASS
class Vconstant_register__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vconstant_register*            TOPp;
    
    // CREATORS
    Vconstant_register__Syms(VerilatedContext* contextp, Vconstant_register* topp, const char* namep);
    ~Vconstant_register__Syms();
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
