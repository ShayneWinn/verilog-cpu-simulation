// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vconstant_register.h for the primary calling header

#include "Vconstant_register.h"
#include "Vconstant_register__Syms.h"

//==========

Vconstant_register::Vconstant_register(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vconstant_register__Syms* __restrict vlSymsp = __VlSymsp = new Vconstant_register__Syms(_vcontextp__, this, name());
    Vconstant_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vconstant_register::__Vconfigure(Vconstant_register__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vconstant_register::~Vconstant_register() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vconstant_register::_eval_initial(Vconstant_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconstant_register::_eval_initial\n"); );
    Vconstant_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__i_load = vlTOPp->i_load;
}

void Vconstant_register::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconstant_register::final\n"); );
    // Variables
    Vconstant_register__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vconstant_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vconstant_register::_eval_settle(Vconstant_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconstant_register::_eval_settle\n"); );
    Vconstant_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vconstant_register::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconstant_register::_ctor_var_reset\n"); );
    // Body
    b_data = VL_RAND_RESET_I(8);
    b_main = VL_RAND_RESET_I(8);
    i_load = VL_RAND_RESET_I(1);
    i_assert = VL_RAND_RESET_I(1);
    data = VL_RAND_RESET_I(8);
}
