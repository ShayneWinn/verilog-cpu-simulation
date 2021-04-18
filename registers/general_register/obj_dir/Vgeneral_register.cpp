// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgeneral_register.h for the primary calling header

#include "Vgeneral_register.h"
#include "Vgeneral_register__Syms.h"

//==========

VerilatedContext* Vgeneral_register::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void Vgeneral_register::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vgeneral_register::eval\n"); );
    Vgeneral_register__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vgeneral_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("general_register.v", 7, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vgeneral_register::_eval_initial_loop(Vgeneral_register__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("general_register.v", 7, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vgeneral_register::_sequent__TOP__2(Vgeneral_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgeneral_register::_sequent__TOP__2\n"); );
    Vgeneral_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->data = vlTOPp->transfer_bus;
}

VL_INLINE_OPT void Vgeneral_register::_settle__TOP__3(Vgeneral_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgeneral_register::_settle__TOP__3\n"); );
    Vgeneral_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->right_bus = ((((IData)(vlTOPp->i_assert_right)
                            ? (IData)(vlTOPp->data)
                            : 0U) & ((IData)(vlTOPp->i_assert_right)
                                      ? 0xffU : 0U)) 
                         & ((IData)(vlTOPp->i_assert_right)
                             ? 0xffU : 0U));
    vlTOPp->left_bus = ((((IData)(vlTOPp->i_assert_left)
                           ? (IData)(vlTOPp->data) : 0U) 
                         & ((IData)(vlTOPp->i_assert_left)
                             ? 0xffU : 0U)) & ((IData)(vlTOPp->i_assert_left)
                                                ? 0xffU
                                                : 0U));
    vlTOPp->transfer_bus = ((((IData)(vlTOPp->i_assert_transfer)
                               ? (IData)(vlTOPp->data)
                               : 0U) & ((IData)(vlTOPp->i_assert_transfer)
                                         ? 0xffU : 0U)) 
                            & ((IData)(vlTOPp->i_assert_transfer)
                                ? 0xffU : 0U));
}

void Vgeneral_register::_eval(Vgeneral_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgeneral_register::_eval\n"); );
    Vgeneral_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->i_load_transfer) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_load_transfer)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    vlTOPp->_settle__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__i_load_transfer = vlTOPp->i_load_transfer;
}

VL_INLINE_OPT QData Vgeneral_register::_change_request(Vgeneral_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgeneral_register::_change_request\n"); );
    Vgeneral_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vgeneral_register::_change_request_1(Vgeneral_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgeneral_register::_change_request_1\n"); );
    Vgeneral_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vgeneral_register::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgeneral_register::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_load_transfer & 0xfeU))) {
        Verilated::overWidthError("i_load_transfer");}
    if (VL_UNLIKELY((i_assert_transfer & 0xfeU))) {
        Verilated::overWidthError("i_assert_transfer");}
    if (VL_UNLIKELY((i_assert_left & 0xfeU))) {
        Verilated::overWidthError("i_assert_left");}
    if (VL_UNLIKELY((i_assert_right & 0xfeU))) {
        Verilated::overWidthError("i_assert_right");}
}
#endif  // VL_DEBUG
