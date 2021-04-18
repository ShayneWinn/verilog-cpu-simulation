// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vconstant_register.h for the primary calling header

#include "Vconstant_register.h"
#include "Vconstant_register__Syms.h"

//==========

VerilatedContext* Vconstant_register::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void Vconstant_register::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vconstant_register::eval\n"); );
    Vconstant_register__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vconstant_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("constant_register.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vconstant_register::_eval_initial_loop(Vconstant_register__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("constant_register.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vconstant_register::_sequent__TOP__1(Vconstant_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconstant_register::_sequent__TOP__1\n"); );
    Vconstant_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->data = vlTOPp->b_data;
}

VL_INLINE_OPT void Vconstant_register::_settle__TOP__2(Vconstant_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconstant_register::_settle__TOP__2\n"); );
    Vconstant_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->b_main = ((((IData)(vlTOPp->i_assert) ? (IData)(vlTOPp->data)
                         : 0U) & ((IData)(vlTOPp->i_assert)
                                   ? 0xffU : 0U)) & 
                      ((IData)(vlTOPp->i_assert) ? 0xffU
                        : 0U));
}

void Vconstant_register::_eval(Vconstant_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconstant_register::_eval\n"); );
    Vconstant_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((~ (IData)(vlTOPp->i_load)) & (IData)(vlTOPp->__Vclklast__TOP__i_load))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_settle__TOP__2(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__i_load = vlTOPp->i_load;
}

VL_INLINE_OPT QData Vconstant_register::_change_request(Vconstant_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconstant_register::_change_request\n"); );
    Vconstant_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vconstant_register::_change_request_1(Vconstant_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconstant_register::_change_request_1\n"); );
    Vconstant_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vconstant_register::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vconstant_register::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_load & 0xfeU))) {
        Verilated::overWidthError("i_load");}
    if (VL_UNLIKELY((i_assert & 0xfeU))) {
        Verilated::overWidthError("i_assert");}
}
#endif  // VL_DEBUG
