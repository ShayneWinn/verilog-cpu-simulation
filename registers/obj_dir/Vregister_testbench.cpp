// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister_testbench.h for the primary calling header

#include "Vregister_testbench.h"
#include "Vregister_testbench__Syms.h"

//==========

VerilatedContext* Vregister_testbench::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void Vregister_testbench::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vregister_testbench::eval\n"); );
    Vregister_testbench__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("register_testbench.v", 6, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vregister_testbench::_eval_initial_loop(Vregister_testbench__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("register_testbench.v", 6, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vregister_testbench::_combo__TOP__2(Vregister_testbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_testbench::_combo__TOP__2\n"); );
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U != (IData)(vlTOPp->i_8bit_assert_word))) {
        if ((2U != (IData)(vlTOPp->i_8bit_assert_word))) {
            vlTOPp->register_testbench__DOT__b_8bit_main__out__out10 
                = vlTOPp->i_bus_in;
        }
    }
    vlTOPp->register_testbench__DOT__ctl_regA_load 
        = ((1U == (IData)(vlTOPp->i_8bit_load_word)) 
           & (IData)(vlTOPp->clk));
    vlTOPp->register_testbench__DOT__ctl_regB_load 
        = ((2U == (IData)(vlTOPp->i_8bit_load_word)) 
           & (IData)(vlTOPp->clk));
}

VL_INLINE_OPT void Vregister_testbench::_sequent__TOP__4(Vregister_testbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_testbench::_sequent__TOP__4\n"); );
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->regA_data = vlTOPp->b_8bit_main;
}

VL_INLINE_OPT void Vregister_testbench::_sequent__TOP__5(Vregister_testbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_testbench::_sequent__TOP__5\n"); );
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->regB_data = vlTOPp->b_8bit_main;
}

VL_INLINE_OPT void Vregister_testbench::_multiclk__TOP__6(Vregister_testbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_testbench::_multiclk__TOP__6\n"); );
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->b_8bit_right = ((((((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_right)
                                 ? (IData)(vlTOPp->regA_data)
                                 : 0U) & ((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_right)
                                           ? 0xffU : 0U)) 
                              & ((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_right)
                                  ? 0xffU : 0U)) | 
                             ((((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_right)
                                 ? (IData)(vlTOPp->regB_data)
                                 : 0U) & ((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_right)
                                           ? 0xffU : 0U)) 
                              & ((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_right)
                                  ? 0xffU : 0U))) & 
                            (((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_right)
                               ? 0xffU : 0U) | ((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_right)
                                                 ? 0xffU
                                                 : 0U)));
    vlTOPp->b_8bit_left = ((((((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_left)
                                ? (IData)(vlTOPp->regA_data)
                                : 0U) & ((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_left)
                                          ? 0xffU : 0U)) 
                             & ((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_left)
                                 ? 0xffU : 0U)) | (
                                                   (((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_left)
                                                      ? (IData)(vlTOPp->regB_data)
                                                      : 0U) 
                                                    & ((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_left)
                                                        ? 0xffU
                                                        : 0U)) 
                                                   & ((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_left)
                                                       ? 0xffU
                                                       : 0U))) 
                           & (((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_left)
                                ? 0xffU : 0U) | ((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_left)
                                                  ? 0xffU
                                                  : 0U)));
}

VL_INLINE_OPT void Vregister_testbench::_combo__TOP__7(Vregister_testbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_testbench::_combo__TOP__7\n"); );
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->b_8bit_main = ((((((1U == (IData)(vlTOPp->i_8bit_assert_word))
                                ? (IData)(vlTOPp->regA_data)
                                : 0U) & ((1U == (IData)(vlTOPp->i_8bit_assert_word))
                                          ? 0xffU : 0U)) 
                             & ((1U == (IData)(vlTOPp->i_8bit_assert_word))
                                 ? 0xffU : 0U)) | (
                                                   (((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_main)
                                                      ? (IData)(vlTOPp->regB_data)
                                                      : 0U) 
                                                    & ((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_main)
                                                        ? 0xffU
                                                        : 0U)) 
                                                   & ((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_main)
                                                       ? 0xffU
                                                       : 0U))) 
                           | (IData)(vlTOPp->register_testbench__DOT__b_8bit_main__out__out10));
}

void Vregister_testbench::_eval(Vregister_testbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_testbench::_eval\n"); );
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if (((~ (IData)(vlTOPp->register_testbench__DOT__ctl_regA_load)) 
         & (IData)(vlTOPp->__Vclklast__TOP__register_testbench__DOT__ctl_regA_load))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->register_testbench__DOT__ctl_regB_load)) 
         & (IData)(vlTOPp->__Vclklast__TOP__register_testbench__DOT__ctl_regB_load))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if ((((~ (IData)(vlTOPp->register_testbench__DOT__ctl_regA_load)) 
          & (IData)(vlTOPp->__Vclklast__TOP__register_testbench__DOT__ctl_regA_load)) 
         | ((~ (IData)(vlTOPp->register_testbench__DOT__ctl_regB_load)) 
            & (IData)(vlTOPp->__Vclklast__TOP__register_testbench__DOT__ctl_regB_load)))) {
        vlTOPp->_multiclk__TOP__6(vlSymsp);
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__register_testbench__DOT__ctl_regA_load 
        = vlTOPp->register_testbench__DOT__ctl_regA_load;
    vlTOPp->__Vclklast__TOP__register_testbench__DOT__ctl_regB_load 
        = vlTOPp->register_testbench__DOT__ctl_regB_load;
}

VL_INLINE_OPT QData Vregister_testbench::_change_request(Vregister_testbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_testbench::_change_request\n"); );
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vregister_testbench::_change_request_1(Vregister_testbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_testbench::_change_request_1\n"); );
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vregister_testbench::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_testbench::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((i_8bit_assert_word & 0xe0U))) {
        Verilated::overWidthError("i_8bit_assert_word");}
    if (VL_UNLIKELY((i_8bit_load_word & 0xe0U))) {
        Verilated::overWidthError("i_8bit_load_word");}
    if (VL_UNLIKELY((i_16bit_assert_word & 0xf0U))) {
        Verilated::overWidthError("i_16bit_assert_word");}
    if (VL_UNLIKELY((i_16bit_load_word & 0xf0U))) {
        Verilated::overWidthError("i_16bit_load_word");}
}
#endif  // VL_DEBUG
