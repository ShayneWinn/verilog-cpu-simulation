// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VADDRESS_REGISTER_H_
#define VERILATED_VADDRESS_REGISTER_H_  // guard

#include "verilated_heavy.h"

//==========

class Vaddress_register__Syms;

//----------

VL_MODULE(Vaddress_register) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(i_load_transfer,0,0);
    VL_IN8(i_inc,0,0);
    VL_IN8(i_dec,0,0);
    VL_IN8(i_assert_transfer,0,0);
    VL_IN8(i_assert_address,0,0);
    VL_INOUT16(transfer_bus,15,0);
    VL_OUT16(address_bus,15,0);
    VL_OUT16(data,15,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__i_dec;
    CData/*0:0*/ __Vclklast__TOP__i_inc;
    CData/*0:0*/ __Vclklast__TOP__i_load_transfer;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vaddress_register__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vaddress_register);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vaddress_register(VerilatedContext* contextp, const char* name = "TOP");
    Vaddress_register(const char* name = "TOP")
      : Vaddress_register(nullptr, name) {}
    /// Destroy the model; called (often implicitly) by application code
    ~Vaddress_register();
    
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
    static void _eval_initial_loop(Vaddress_register__Syms* __restrict vlSymsp);
    void __Vconfigure(Vaddress_register__Syms* symsp, bool first);
  private:
    static QData _change_request(Vaddress_register__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vaddress_register__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vaddress_register__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vaddress_register__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vaddress_register__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vaddress_register__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__2(Vaddress_register__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vaddress_register__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
