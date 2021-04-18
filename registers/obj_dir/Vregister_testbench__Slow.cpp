// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vregister_testbench.h for the primary calling header

#include "Vregister_testbench.h"
#include "Vregister_testbench__Syms.h"

//==========

Vregister_testbench::Vregister_testbench(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vregister_testbench__Syms* __restrict vlSymsp = __VlSymsp = new Vregister_testbench__Syms(_vcontextp__, this, name());
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vregister_testbench::__Vconfigure(Vregister_testbench__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vregister_testbench::~Vregister_testbench() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vregister_testbench::_initial__TOP__1(Vregister_testbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_testbench::_initial__TOP__1\n"); );
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->register_testbench__DOT__regA__DOT__unnamedblk1__DOT__temp 
        = VL_RANDOM_I(32);
    vlTOPp->regA_data = (0xffU & vlTOPp->register_testbench__DOT__regA__DOT__unnamedblk1__DOT__temp);
    vlTOPp->register_testbench__DOT__regB__DOT__unnamedblk1__DOT__temp 
        = VL_RANDOM_I(32);
    vlTOPp->regB_data = (0xffU & vlTOPp->register_testbench__DOT__regB__DOT__unnamedblk1__DOT__temp);
    vlTOPp->register_testbench__DOT__regC__DOT__unnamedblk1__DOT__temp 
        = VL_RANDOM_I(32);
    vlTOPp->regC_data = (0xffU & vlTOPp->register_testbench__DOT__regC__DOT__unnamedblk1__DOT__temp);
    vlTOPp->register_testbench__DOT__regD__DOT__unnamedblk1__DOT__temp 
        = VL_RANDOM_I(32);
    vlTOPp->regD_data = (0xffU & vlTOPp->register_testbench__DOT__regD__DOT__unnamedblk1__DOT__temp);
}

void Vregister_testbench::_settle__TOP__3(Vregister_testbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_testbench::_settle__TOP__3\n"); );
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->register_testbench__DOT__ctl_regA_load 
        = ((2U == (IData)(vlTOPp->i_8bit_load_word)) 
           & (IData)(vlTOPp->clk));
    vlTOPp->register_testbench__DOT__ctl_regB_load 
        = ((3U == (IData)(vlTOPp->i_8bit_load_word)) 
           & (IData)(vlTOPp->clk));
    vlTOPp->register_testbench__DOT__ctl_regC_load 
        = ((4U == (IData)(vlTOPp->i_8bit_load_word)) 
           & (IData)(vlTOPp->clk));
    vlTOPp->register_testbench__DOT__ctl_regD_load 
        = ((5U == (IData)(vlTOPp->i_8bit_load_word)) 
           & (IData)(vlTOPp->clk));
    vlTOPp->register_testbench__DOT__ctl_const_load 
        = ((1U == (IData)(vlTOPp->i_8bit_load_word)) 
           & (IData)(vlTOPp->clk));
    vlTOPp->b_8bit_right = ((((((((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_right)
                                   ? (IData)(vlTOPp->regA_data)
                                   : 0U) & ((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_right)
                                             ? 0xffU
                                             : 0U)) 
                                & ((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_right)
                                    ? 0xffU : 0U)) 
                               | ((((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_right)
                                     ? (IData)(vlTOPp->regB_data)
                                     : 0U) & ((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_right)
                                               ? 0xffU
                                               : 0U)) 
                                  & ((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_right)
                                      ? 0xffU : 0U))) 
                              | ((((IData)(vlTOPp->register_testbench__DOT__ctl_regC_assert_right)
                                    ? (IData)(vlTOPp->regC_data)
                                    : 0U) & ((IData)(vlTOPp->register_testbench__DOT__ctl_regC_assert_right)
                                              ? 0xffU
                                              : 0U)) 
                                 & ((IData)(vlTOPp->register_testbench__DOT__ctl_regC_assert_right)
                                     ? 0xffU : 0U))) 
                             | ((((IData)(vlTOPp->register_testbench__DOT__ctl_regD_assert_right)
                                   ? (IData)(vlTOPp->regD_data)
                                   : 0U) & ((IData)(vlTOPp->register_testbench__DOT__ctl_regD_assert_right)
                                             ? 0xffU
                                             : 0U)) 
                                & ((IData)(vlTOPp->register_testbench__DOT__ctl_regD_assert_right)
                                    ? 0xffU : 0U))) 
                            & (((((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_right)
                                   ? 0xffU : 0U) | 
                                 ((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_right)
                                   ? 0xffU : 0U)) | 
                                ((IData)(vlTOPp->register_testbench__DOT__ctl_regC_assert_right)
                                  ? 0xffU : 0U)) | 
                               ((IData)(vlTOPp->register_testbench__DOT__ctl_regD_assert_right)
                                 ? 0xffU : 0U)));
    vlTOPp->b_8bit_left = ((((((((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_left)
                                  ? (IData)(vlTOPp->regA_data)
                                  : 0U) & ((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_left)
                                            ? 0xffU
                                            : 0U)) 
                               & ((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_left)
                                   ? 0xffU : 0U)) | 
                              ((((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_left)
                                  ? (IData)(vlTOPp->regB_data)
                                  : 0U) & ((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_left)
                                            ? 0xffU
                                            : 0U)) 
                               & ((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_left)
                                   ? 0xffU : 0U))) 
                             | ((((IData)(vlTOPp->register_testbench__DOT__ctl_regC_assert_left)
                                   ? (IData)(vlTOPp->regC_data)
                                   : 0U) & ((IData)(vlTOPp->register_testbench__DOT__ctl_regC_assert_left)
                                             ? 0xffU
                                             : 0U)) 
                                & ((IData)(vlTOPp->register_testbench__DOT__ctl_regC_assert_left)
                                    ? 0xffU : 0U))) 
                            | ((((IData)(vlTOPp->register_testbench__DOT__ctl_regD_assert_left)
                                  ? (IData)(vlTOPp->regD_data)
                                  : 0U) & ((IData)(vlTOPp->register_testbench__DOT__ctl_regD_assert_left)
                                            ? 0xffU
                                            : 0U)) 
                               & ((IData)(vlTOPp->register_testbench__DOT__ctl_regD_assert_left)
                                   ? 0xffU : 0U))) 
                           & (((((IData)(vlTOPp->register_testbench__DOT__ctl_regA_assert_left)
                                  ? 0xffU : 0U) | ((IData)(vlTOPp->register_testbench__DOT__ctl_regB_assert_left)
                                                    ? 0xffU
                                                    : 0U)) 
                               | ((IData)(vlTOPp->register_testbench__DOT__ctl_regC_assert_left)
                                   ? 0xffU : 0U)) | 
                              ((IData)(vlTOPp->register_testbench__DOT__ctl_regD_assert_left)
                                ? 0xffU : 0U)));
    vlTOPp->b_8bit_main = (((((((((2U == (IData)(vlTOPp->i_8bit_assert_word))
                                   ? (IData)(vlTOPp->regA_data)
                                   : 0U) & ((2U == (IData)(vlTOPp->i_8bit_assert_word))
                                             ? 0xffU
                                             : 0U)) 
                                & ((2U == (IData)(vlTOPp->i_8bit_assert_word))
                                    ? 0xffU : 0U)) 
                               | ((((3U == (IData)(vlTOPp->i_8bit_assert_word))
                                     ? (IData)(vlTOPp->regB_data)
                                     : 0U) & ((3U == (IData)(vlTOPp->i_8bit_assert_word))
                                               ? 0xffU
                                               : 0U)) 
                                  & ((3U == (IData)(vlTOPp->i_8bit_assert_word))
                                      ? 0xffU : 0U))) 
                              | ((((4U == (IData)(vlTOPp->i_8bit_assert_word))
                                    ? (IData)(vlTOPp->regC_data)
                                    : 0U) & ((4U == (IData)(vlTOPp->i_8bit_assert_word))
                                              ? 0xffU
                                              : 0U)) 
                                 & ((4U == (IData)(vlTOPp->i_8bit_assert_word))
                                     ? 0xffU : 0U))) 
                             | ((((5U == (IData)(vlTOPp->i_8bit_assert_word))
                                   ? (IData)(vlTOPp->regD_data)
                                   : 0U) & ((5U == (IData)(vlTOPp->i_8bit_assert_word))
                                             ? 0xffU
                                             : 0U)) 
                                & ((5U == (IData)(vlTOPp->i_8bit_assert_word))
                                    ? 0xffU : 0U))) 
                            | ((((1U == (IData)(vlTOPp->i_8bit_assert_word))
                                  ? (IData)(vlTOPp->register_testbench__DOT__constant__DOT__data)
                                  : 0U) & ((1U == (IData)(vlTOPp->i_8bit_assert_word))
                                            ? 0xffU
                                            : 0U)) 
                               & ((1U == (IData)(vlTOPp->i_8bit_assert_word))
                                   ? 0xffU : 0U))) 
                           & ((((((2U == (IData)(vlTOPp->i_8bit_assert_word))
                                   ? 0xffU : 0U) | 
                                 ((3U == (IData)(vlTOPp->i_8bit_assert_word))
                                   ? 0xffU : 0U)) | 
                                ((4U == (IData)(vlTOPp->i_8bit_assert_word))
                                  ? 0xffU : 0U)) | 
                               ((5U == (IData)(vlTOPp->i_8bit_assert_word))
                                 ? 0xffU : 0U)) | (
                                                   (1U 
                                                    == (IData)(vlTOPp->i_8bit_assert_word))
                                                    ? 0xffU
                                                    : 0U)));
}

void Vregister_testbench::_eval_initial(Vregister_testbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_testbench::_eval_initial\n"); );
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__register_testbench__DOT__ctl_regA_load 
        = vlTOPp->register_testbench__DOT__ctl_regA_load;
    vlTOPp->__Vclklast__TOP__register_testbench__DOT__ctl_regB_load 
        = vlTOPp->register_testbench__DOT__ctl_regB_load;
    vlTOPp->__Vclklast__TOP__register_testbench__DOT__ctl_regC_load 
        = vlTOPp->register_testbench__DOT__ctl_regC_load;
    vlTOPp->__Vclklast__TOP__register_testbench__DOT__ctl_regD_load 
        = vlTOPp->register_testbench__DOT__ctl_regD_load;
    vlTOPp->__Vclklast__TOP__register_testbench__DOT__ctl_const_load 
        = vlTOPp->register_testbench__DOT__ctl_const_load;
}

void Vregister_testbench::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_testbench::final\n"); );
    // Variables
    Vregister_testbench__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vregister_testbench::_eval_settle(Vregister_testbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_testbench::_eval_settle\n"); );
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vregister_testbench::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vregister_testbench::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    i_8bit_assert_word = VL_RAND_RESET_I(5);
    i_8bit_load_word = VL_RAND_RESET_I(5);
    i_16bit_assert_word = VL_RAND_RESET_I(4);
    i_16bit_load_word = VL_RAND_RESET_I(4);
    i_bus_in = VL_RAND_RESET_I(8);
    b_8bit_main = VL_RAND_RESET_I(8);
    b_8bit_left = VL_RAND_RESET_I(8);
    b_8bit_right = VL_RAND_RESET_I(8);
    b_16bit_transfer = VL_RAND_RESET_I(17);
    b_16bit_address = VL_RAND_RESET_I(17);
    regA_data = VL_RAND_RESET_I(8);
    regB_data = VL_RAND_RESET_I(8);
    regC_data = VL_RAND_RESET_I(8);
    regD_data = VL_RAND_RESET_I(8);
    register_testbench__DOT__ctl_regA_assert_left = VL_RAND_RESET_I(1);
    register_testbench__DOT__ctl_regA_assert_right = VL_RAND_RESET_I(1);
    register_testbench__DOT__ctl_regA_load = VL_RAND_RESET_I(1);
    register_testbench__DOT__ctl_regB_assert_left = VL_RAND_RESET_I(1);
    register_testbench__DOT__ctl_regB_assert_right = VL_RAND_RESET_I(1);
    register_testbench__DOT__ctl_regB_load = VL_RAND_RESET_I(1);
    register_testbench__DOT__ctl_regC_assert_left = VL_RAND_RESET_I(1);
    register_testbench__DOT__ctl_regC_assert_right = VL_RAND_RESET_I(1);
    register_testbench__DOT__ctl_regC_load = VL_RAND_RESET_I(1);
    register_testbench__DOT__ctl_regD_assert_left = VL_RAND_RESET_I(1);
    register_testbench__DOT__ctl_regD_assert_right = VL_RAND_RESET_I(1);
    register_testbench__DOT__ctl_regD_load = VL_RAND_RESET_I(1);
    register_testbench__DOT__ctl_const_load = VL_RAND_RESET_I(1);
    register_testbench__DOT__regA__DOT__unnamedblk1__DOT__temp = VL_RAND_RESET_I(32);
    register_testbench__DOT__regB__DOT__unnamedblk1__DOT__temp = VL_RAND_RESET_I(32);
    register_testbench__DOT__regC__DOT__unnamedblk1__DOT__temp = VL_RAND_RESET_I(32);
    register_testbench__DOT__regD__DOT__unnamedblk1__DOT__temp = VL_RAND_RESET_I(32);
    register_testbench__DOT__constant__DOT__data = VL_RAND_RESET_I(8);
}
