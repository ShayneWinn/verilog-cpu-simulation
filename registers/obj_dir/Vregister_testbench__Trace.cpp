// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vregister_testbench__Syms.h"


void Vregister_testbench::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vregister_testbench__Syms* __restrict vlSymsp = static_cast<Vregister_testbench__Syms*>(userp);
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vregister_testbench::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vregister_testbench__Syms* __restrict vlSymsp = static_cast<Vregister_testbench__Syms*>(userp);
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clk));
        tracep->chgCData(oldp+1,(vlTOPp->i_8bit_assert_word),5);
        tracep->chgCData(oldp+2,(vlTOPp->i_8bit_load_word),5);
        tracep->chgCData(oldp+3,(vlTOPp->i_16bit_assert_word),4);
        tracep->chgCData(oldp+4,(vlTOPp->i_16bit_load_word),4);
        tracep->chgCData(oldp+5,(vlTOPp->b_8bit_main),8);
        tracep->chgCData(oldp+6,(vlTOPp->b_8bit_left),8);
        tracep->chgCData(oldp+7,(vlTOPp->b_8bit_right),8);
        tracep->chgIData(oldp+8,(vlTOPp->b_16bit_transfer),17);
        tracep->chgIData(oldp+9,(vlTOPp->b_16bit_address),17);
        tracep->chgCData(oldp+10,(vlTOPp->regA_data),8);
        tracep->chgCData(oldp+11,(vlTOPp->regB_data),8);
        tracep->chgCData(oldp+12,(vlTOPp->regC_data),8);
        tracep->chgCData(oldp+13,(vlTOPp->regD_data),8);
        tracep->chgBit(oldp+14,((1U == (IData)(vlTOPp->i_8bit_assert_word))));
        tracep->chgBit(oldp+15,(vlTOPp->register_testbench__DOT__ctl_regA_load));
        tracep->chgBit(oldp+16,((2U == (IData)(vlTOPp->i_8bit_assert_word))));
        tracep->chgBit(oldp+17,(vlTOPp->register_testbench__DOT__ctl_regB_load));
        tracep->chgCData(oldp+18,(vlTOPp->register_testbench__DOT__regA__DOT__data),8);
        tracep->chgCData(oldp+19,(vlTOPp->register_testbench__DOT__regB__DOT__data),8);
    }
}

void Vregister_testbench::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vregister_testbench__Syms* __restrict vlSymsp = static_cast<Vregister_testbench__Syms*>(userp);
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
