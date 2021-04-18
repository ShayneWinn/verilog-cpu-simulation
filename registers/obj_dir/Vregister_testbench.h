// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VREGISTER_TESTBENCH_H_
#define VERILATED_VREGISTER_TESTBENCH_H_  // guard

#include "verilated_heavy.h"

//==========

class Vregister_testbench__Syms;

//----------

VL_MODULE(Vregister_testbench) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(i_8bit_assert_word,4,0);
    VL_IN8(i_8bit_load_word,4,0);
    VL_IN8(i_16bit_assert_word,3,0);
    VL_IN8(i_16bit_load_word,3,0);
    VL_IN8(i_bus_in,7,0);
    VL_OUT8(b_8bit_main,7,0);
    VL_OUT8(b_8bit_left,7,0);
    VL_OUT8(b_8bit_right,7,0);
    VL_OUT8(regA_data,7,0);
    VL_OUT8(regB_data,7,0);
    VL_OUT8(regC_data,7,0);
    VL_OUT8(regD_data,7,0);
    VL_OUT(b_16bit_transfer,16,0);
    VL_OUT(b_16bit_address,16,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ register_testbench__DOT__ctl_regA_load;
    CData/*0:0*/ register_testbench__DOT__ctl_regB_load;
    CData/*0:0*/ register_testbench__DOT__ctl_regC_load;
    CData/*0:0*/ register_testbench__DOT__ctl_regD_load;
    CData/*0:0*/ register_testbench__DOT__ctl_const_load;
    CData/*0:0*/ register_testbench__DOT__ctl_regA_assert_left;
    CData/*0:0*/ register_testbench__DOT__ctl_regA_assert_right;
    CData/*0:0*/ register_testbench__DOT__ctl_regB_assert_left;
    CData/*0:0*/ register_testbench__DOT__ctl_regB_assert_right;
    CData/*0:0*/ register_testbench__DOT__ctl_regC_assert_left;
    CData/*0:0*/ register_testbench__DOT__ctl_regC_assert_right;
    CData/*0:0*/ register_testbench__DOT__ctl_regD_assert_left;
    CData/*0:0*/ register_testbench__DOT__ctl_regD_assert_right;
    CData/*7:0*/ register_testbench__DOT__constant__DOT__data;
    IData/*31:0*/ register_testbench__DOT__regA__DOT__unnamedblk1__DOT__temp;
    IData/*31:0*/ register_testbench__DOT__regB__DOT__unnamedblk1__DOT__temp;
    IData/*31:0*/ register_testbench__DOT__regC__DOT__unnamedblk1__DOT__temp;
    IData/*31:0*/ register_testbench__DOT__regD__DOT__unnamedblk1__DOT__temp;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__register_testbench__DOT__ctl_regA_load;
    CData/*0:0*/ __Vclklast__TOP__register_testbench__DOT__ctl_regB_load;
    CData/*0:0*/ __Vclklast__TOP__register_testbench__DOT__ctl_regC_load;
    CData/*0:0*/ __Vclklast__TOP__register_testbench__DOT__ctl_regD_load;
    CData/*0:0*/ __Vclklast__TOP__register_testbench__DOT__ctl_const_load;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vregister_testbench__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vregister_testbench);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vregister_testbench(VerilatedContext* contextp, const char* name = "TOP");
    Vregister_testbench(const char* name = "TOP")
      : Vregister_testbench(nullptr, name) {}
    /// Destroy the model; called (often implicitly) by application code
    ~Vregister_testbench();
    
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
    static void _eval_initial_loop(Vregister_testbench__Syms* __restrict vlSymsp);
    void __Vconfigure(Vregister_testbench__Syms* symsp, bool first);
  private:
    static QData _change_request(Vregister_testbench__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vregister_testbench__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__10(Vregister_testbench__Syms* __restrict vlSymsp);
    static void _combo__TOP__2(Vregister_testbench__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vregister_testbench__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vregister_testbench__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vregister_testbench__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vregister_testbench__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__9(Vregister_testbench__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vregister_testbench__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vregister_testbench__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vregister_testbench__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vregister_testbench__Syms* __restrict vlSymsp);
    static void _sequent__TOP__8(Vregister_testbench__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vregister_testbench__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
