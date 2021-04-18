// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VCONSTANT_REGISTER_H_
#define VERILATED_VCONSTANT_REGISTER_H_  // guard

#include "verilated_heavy.h"

//==========

class Vconstant_register__Syms;

//----------

VL_MODULE(Vconstant_register) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(i_load,0,0);
    VL_IN8(b_data,7,0);
    VL_OUT8(b_main,7,0);
    VL_IN8(i_assert,0,0);
    VL_OUT8(data,7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__i_load;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vconstant_register__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vconstant_register);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vconstant_register(VerilatedContext* contextp, const char* name = "TOP");
    Vconstant_register(const char* name = "TOP")
      : Vconstant_register(nullptr, name) {}
    /// Destroy the model; called (often implicitly) by application code
    ~Vconstant_register();
    
    // API METHODS
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp();
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
    static void _eval_initial_loop(Vconstant_register__Syms* __restrict vlSymsp);
    void __Vconfigure(Vconstant_register__Syms* symsp, bool first);
  private:
    static QData _change_request(Vconstant_register__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vconstant_register__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vconstant_register__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vconstant_register__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vconstant_register__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vconstant_register__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vconstant_register__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
