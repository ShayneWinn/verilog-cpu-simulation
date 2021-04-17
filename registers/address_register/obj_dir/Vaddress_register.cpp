// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaddress_register.h for the primary calling header

#include "Vaddress_register.h"
#include "Vaddress_register__Syms.h"

//==========

VerilatedContext* Vaddress_register::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void Vaddress_register::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vaddress_register::eval\n"); );
    Vaddress_register__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vaddress_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("address_register.v", 10, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vaddress_register::_eval_initial_loop(Vaddress_register__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("address_register.v", 10, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vaddress_register::_sequent__TOP__1(Vaddress_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddress_register::_sequent__TOP__1\n"); );
    Vaddress_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*15:0*/ __Vdly__data;
    // Body
    __Vdly__data = vlTOPp->data;
    if (vlTOPp->i_load_transfer) {
        __Vdly__data = vlTOPp->transfer_bus;
    } else {
        if (vlTOPp->i_inc) {
            __Vdly__data = (0xffffU & ((IData)(1U) 
                                       + (IData)(vlTOPp->data)));
        } else {
            if (vlTOPp->i_dec) {
                __Vdly__data = (0xffffU & ((IData)(vlTOPp->data) 
                                           - (IData)(1U)));
            }
        }
    }
    vlTOPp->data = __Vdly__data;
}

VL_INLINE_OPT void Vaddress_register::_combo__TOP__3(Vaddress_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddress_register::_combo__TOP__3\n"); );
    Vaddress_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->address_bus = ((((IData)(vlTOPp->i_assert_address)
                              ? (IData)(vlTOPp->data)
                              : 0U) & ((IData)(vlTOPp->i_assert_address)
                                        ? 0xffffU : 0U)) 
                           & ((IData)(vlTOPp->i_assert_address)
                               ? 0xffffU : 0U));
    vlTOPp->transfer_bus = ((((IData)(vlTOPp->i_assert_transfer)
                               ? (IData)(vlTOPp->data)
                               : 0U) & ((IData)(vlTOPp->i_assert_transfer)
                                         ? 0xffffU : 0U)) 
                            & ((IData)(vlTOPp->i_assert_transfer)
                                ? 0xffffU : 0U));
}

void Vaddress_register::_eval(Vaddress_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddress_register::_eval\n"); );
    Vaddress_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((((IData)(vlTOPp->i_dec) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_dec))) 
          | ((IData)(vlTOPp->i_inc) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_inc)))) 
         | ((IData)(vlTOPp->i_load_transfer) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_load_transfer))))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__i_dec = vlTOPp->i_dec;
    vlTOPp->__Vclklast__TOP__i_inc = vlTOPp->i_inc;
    vlTOPp->__Vclklast__TOP__i_load_transfer = vlTOPp->i_load_transfer;
}

VL_INLINE_OPT QData Vaddress_register::_change_request(Vaddress_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddress_register::_change_request\n"); );
    Vaddress_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vaddress_register::_change_request_1(Vaddress_register__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddress_register::_change_request_1\n"); );
    Vaddress_register* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vaddress_register::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaddress_register::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_load_transfer & 0xfeU))) {
        Verilated::overWidthError("i_load_transfer");}
    if (VL_UNLIKELY((i_assert_transfer & 0xfeU))) {
        Verilated::overWidthError("i_assert_transfer");}
    if (VL_UNLIKELY((i_assert_address & 0xfeU))) {
        Verilated::overWidthError("i_assert_address");}
    if (VL_UNLIKELY((i_inc & 0xfeU))) {
        Verilated::overWidthError("i_inc");}
    if (VL_UNLIKELY((i_dec & 0xfeU))) {
        Verilated::overWidthError("i_dec");}
}
#endif  // VL_DEBUG
