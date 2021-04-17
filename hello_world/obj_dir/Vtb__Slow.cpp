// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb.h"
#include "Vtb__Syms.h"

//==========

Vtb::Vtb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vtb__Syms* __restrict vlSymsp = __VlSymsp = new Vtb__Syms(_vcontextp__, this, name());
    Vtb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtb::__Vconfigure(Vtb__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vtb::~Vtb() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vtb::_initial__TOP__1(Vtb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb::_initial__TOP__1\n"); );
    Vtb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_WRITEF("Begin\n");
    vlTOPp->counter = 0U;
}

void Vtb::_settle__TOP__3(Vtb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb::_settle__TOP__3\n"); );
    Vtb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (VL_UNLIKELY((0xffU == (IData)(vlTOPp->counter)))) {
        VL_FINISH_MT("tb.v", 16, "");
    }
}

void Vtb::_eval_initial(Vtb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb::_eval_initial\n"); );
    Vtb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtb::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb::final\n"); );
    // Variables
    Vtb__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtb::_eval_settle(Vtb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb::_eval_settle\n"); );
    Vtb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vtb::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    counter = VL_RAND_RESET_I(8);
}
