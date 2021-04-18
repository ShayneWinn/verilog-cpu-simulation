// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgeneral_register.h for the primary calling header

#include "Vgeneral_register.h"
#include "Vgeneral_register__Syms.h"

//==========

Vgeneral_register::Vgeneral_register(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vgeneral_register__Syms* __restrict vlSymsp = __VlSymsp = new Vgeneral_register__Syms(_vcontextp__, this, name());
    Vgeneral_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vgeneral_register::__Vconfigure(Vgeneral_register__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vgeneral_register::~Vgeneral_register() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vgeneral_register::_initial__TOP__1(Vgeneral_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgeneral_register::_initial__TOP__1\n"); );
    Vgeneral_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->general_register__DOT__unnamedblk1__DOT__temp 
        = VL_RANDOM_I(32);
    vlTOPp->data = (0xffU & vlTOPp->general_register__DOT__unnamedblk1__DOT__temp);
}

void Vgeneral_register::_eval_initial(Vgeneral_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgeneral_register::_eval_initial\n"); );
    Vgeneral_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__i_load_transfer = vlTOPp->i_load_transfer;
}

void Vgeneral_register::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgeneral_register::final\n"); );
    // Variables
    Vgeneral_register__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vgeneral_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vgeneral_register::_eval_settle(Vgeneral_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgeneral_register::_eval_settle\n"); );
    Vgeneral_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vgeneral_register::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgeneral_register::_ctor_var_reset\n"); );
    // Body
    i_load_transfer = VL_RAND_RESET_I(1);
    i_assert_transfer = VL_RAND_RESET_I(1);
    i_assert_left = VL_RAND_RESET_I(1);
    i_assert_right = VL_RAND_RESET_I(1);
    transfer_bus = VL_RAND_RESET_I(8);
    left_bus = VL_RAND_RESET_I(8);
    right_bus = VL_RAND_RESET_I(8);
    data = VL_RAND_RESET_I(8);
    general_register__DOT__unnamedblk1__DOT__temp = VL_RAND_RESET_I(32);
}
