// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddress_register.h for the primary calling header

#include "Vaddress_register.h"
#include "Vaddress_register__Syms.h"

//==========

Vaddress_register::Vaddress_register(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vaddress_register__Syms* __restrict vlSymsp = __VlSymsp = new Vaddress_register__Syms(_vcontextp__, this, name());
    Vaddress_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vaddress_register::__Vconfigure(Vaddress_register__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vaddress_register::~Vaddress_register() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vaddress_register::_initial__TOP__2(Vaddress_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddress_register::_initial__TOP__2\n"); );
    Vaddress_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->data = 0U;
}

void Vaddress_register::_eval_initial(Vaddress_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddress_register::_eval_initial\n"); );
    Vaddress_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__i_dec = vlTOPp->i_dec;
    vlTOPp->__Vclklast__TOP__i_inc = vlTOPp->i_inc;
    vlTOPp->__Vclklast__TOP__i_load_transfer = vlTOPp->i_load_transfer;
    vlTOPp->_initial__TOP__2(vlSymsp);
}

void Vaddress_register::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddress_register::final\n"); );
    // Variables
    Vaddress_register__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vaddress_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vaddress_register::_eval_settle(Vaddress_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddress_register::_eval_settle\n"); );
    Vaddress_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__3(vlSymsp);
}

void Vaddress_register::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddress_register::_ctor_var_reset\n"); );
    // Body
    i_load_transfer = VL_RAND_RESET_I(1);
    i_assert_transfer = VL_RAND_RESET_I(1);
    i_assert_address = VL_RAND_RESET_I(1);
    i_inc = VL_RAND_RESET_I(1);
    i_dec = VL_RAND_RESET_I(1);
    transfer_bus = VL_RAND_RESET_I(16);
    address_bus = VL_RAND_RESET_I(16);
    data = VL_RAND_RESET_I(16);
}
