// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vregister_testbench__Syms.h"


//======================

void Vregister_testbench::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vregister_testbench::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vregister_testbench__Syms* __restrict vlSymsp = static_cast<Vregister_testbench__Syms*>(userp);
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vregister_testbench::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vregister_testbench::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vregister_testbench__Syms* __restrict vlSymsp = static_cast<Vregister_testbench__Syms*>(userp);
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vregister_testbench::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vregister_testbench__Syms* __restrict vlSymsp = static_cast<Vregister_testbench__Syms*>(userp);
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBus(c+2,"i_8bit_assert_word", false,-1, 4,0);
        tracep->declBus(c+3,"i_8bit_load_word", false,-1, 4,0);
        tracep->declBus(c+4,"i_16bit_assert_word", false,-1, 3,0);
        tracep->declBus(c+5,"i_16bit_load_word", false,-1, 3,0);
        tracep->declBus(c+6,"b_8bit_main", false,-1, 7,0);
        tracep->declBus(c+7,"b_8bit_left", false,-1, 7,0);
        tracep->declBus(c+8,"b_8bit_right", false,-1, 7,0);
        tracep->declBus(c+9,"b_16bit_transfer", false,-1, 16,0);
        tracep->declBus(c+10,"b_16bit_address", false,-1, 16,0);
        tracep->declBus(c+11,"regA_data", false,-1, 7,0);
        tracep->declBus(c+12,"regB_data", false,-1, 7,0);
        tracep->declBus(c+13,"regC_data", false,-1, 7,0);
        tracep->declBus(c+14,"regD_data", false,-1, 7,0);
        tracep->declBit(c+1,"register_testbench clk", false,-1);
        tracep->declBus(c+2,"register_testbench i_8bit_assert_word", false,-1, 4,0);
        tracep->declBus(c+3,"register_testbench i_8bit_load_word", false,-1, 4,0);
        tracep->declBus(c+4,"register_testbench i_16bit_assert_word", false,-1, 3,0);
        tracep->declBus(c+5,"register_testbench i_16bit_load_word", false,-1, 3,0);
        tracep->declBus(c+6,"register_testbench b_8bit_main", false,-1, 7,0);
        tracep->declBus(c+7,"register_testbench b_8bit_left", false,-1, 7,0);
        tracep->declBus(c+8,"register_testbench b_8bit_right", false,-1, 7,0);
        tracep->declBus(c+9,"register_testbench b_16bit_transfer", false,-1, 16,0);
        tracep->declBus(c+10,"register_testbench b_16bit_address", false,-1, 16,0);
        tracep->declBus(c+11,"register_testbench regA_data", false,-1, 7,0);
        tracep->declBus(c+12,"register_testbench regB_data", false,-1, 7,0);
        tracep->declBus(c+13,"register_testbench regC_data", false,-1, 7,0);
        tracep->declBus(c+14,"register_testbench regD_data", false,-1, 7,0);
        tracep->declBit(c+15,"register_testbench ctl_regA_assert_main", false,-1);
        tracep->declBit(c+21,"register_testbench ctl_regA_assert_left", false,-1);
        tracep->declBit(c+22,"register_testbench ctl_regA_assert_right", false,-1);
        tracep->declBit(c+16,"register_testbench ctl_regA_load", false,-1);
        tracep->declBit(c+17,"register_testbench ctl_regB_assert_main", false,-1);
        tracep->declBit(c+23,"register_testbench ctl_regB_assert_left", false,-1);
        tracep->declBit(c+24,"register_testbench ctl_regB_assert_right", false,-1);
        tracep->declBit(c+18,"register_testbench ctl_regB_load", false,-1);
        tracep->declBit(c+25,"register_testbench ctl_regC_assert_main", false,-1);
        tracep->declBit(c+26,"register_testbench ctl_regC_assert_left", false,-1);
        tracep->declBit(c+27,"register_testbench ctl_regC_assert_right", false,-1);
        tracep->declBit(c+28,"register_testbench ctl_regC_load", false,-1);
        tracep->declBit(c+29,"register_testbench ctl_regD_assert_main", false,-1);
        tracep->declBit(c+30,"register_testbench ctl_regD_assert_left", false,-1);
        tracep->declBit(c+31,"register_testbench ctl_regD_assert_right", false,-1);
        tracep->declBit(c+32,"register_testbench ctl_regD_load", false,-1);
        tracep->declBit(c+16,"register_testbench regA i_load_transfer", false,-1);
        tracep->declBit(c+15,"register_testbench regA i_assert_transfer", false,-1);
        tracep->declBit(c+21,"register_testbench regA i_assert_left", false,-1);
        tracep->declBit(c+22,"register_testbench regA i_assert_right", false,-1);
        tracep->declBus(c+6,"register_testbench regA transfer_bus", false,-1, 7,0);
        tracep->declBus(c+7,"register_testbench regA left_bus", false,-1, 7,0);
        tracep->declBus(c+8,"register_testbench regA right_bus", false,-1, 7,0);
        tracep->declBus(c+19,"register_testbench regA data", false,-1, 7,0);
        tracep->declBit(c+18,"register_testbench regB i_load_transfer", false,-1);
        tracep->declBit(c+17,"register_testbench regB i_assert_transfer", false,-1);
        tracep->declBit(c+23,"register_testbench regB i_assert_left", false,-1);
        tracep->declBit(c+24,"register_testbench regB i_assert_right", false,-1);
        tracep->declBus(c+6,"register_testbench regB transfer_bus", false,-1, 7,0);
        tracep->declBus(c+7,"register_testbench regB left_bus", false,-1, 7,0);
        tracep->declBus(c+8,"register_testbench regB right_bus", false,-1, 7,0);
        tracep->declBus(c+20,"register_testbench regB data", false,-1, 7,0);
    }
}

void Vregister_testbench::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vregister_testbench::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vregister_testbench__Syms* __restrict vlSymsp = static_cast<Vregister_testbench__Syms*>(userp);
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vregister_testbench::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vregister_testbench__Syms* __restrict vlSymsp = static_cast<Vregister_testbench__Syms*>(userp);
    Vregister_testbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk));
        tracep->fullCData(oldp+2,(vlTOPp->i_8bit_assert_word),5);
        tracep->fullCData(oldp+3,(vlTOPp->i_8bit_load_word),5);
        tracep->fullCData(oldp+4,(vlTOPp->i_16bit_assert_word),4);
        tracep->fullCData(oldp+5,(vlTOPp->i_16bit_load_word),4);
        tracep->fullCData(oldp+6,(vlTOPp->b_8bit_main),8);
        tracep->fullCData(oldp+7,(vlTOPp->b_8bit_left),8);
        tracep->fullCData(oldp+8,(vlTOPp->b_8bit_right),8);
        tracep->fullIData(oldp+9,(vlTOPp->b_16bit_transfer),17);
        tracep->fullIData(oldp+10,(vlTOPp->b_16bit_address),17);
        tracep->fullCData(oldp+11,(vlTOPp->regA_data),8);
        tracep->fullCData(oldp+12,(vlTOPp->regB_data),8);
        tracep->fullCData(oldp+13,(vlTOPp->regC_data),8);
        tracep->fullCData(oldp+14,(vlTOPp->regD_data),8);
        tracep->fullBit(oldp+15,((1U == (IData)(vlTOPp->i_8bit_assert_word))));
        tracep->fullBit(oldp+16,(vlTOPp->register_testbench__DOT__ctl_regA_load));
        tracep->fullBit(oldp+17,((2U == (IData)(vlTOPp->i_8bit_assert_word))));
        tracep->fullBit(oldp+18,(vlTOPp->register_testbench__DOT__ctl_regB_load));
        tracep->fullCData(oldp+19,(vlTOPp->register_testbench__DOT__regA__DOT__data),8);
        tracep->fullCData(oldp+20,(vlTOPp->register_testbench__DOT__regB__DOT__data),8);
        tracep->fullBit(oldp+21,(vlTOPp->register_testbench__DOT__ctl_regA_assert_left));
        tracep->fullBit(oldp+22,(vlTOPp->register_testbench__DOT__ctl_regA_assert_right));
        tracep->fullBit(oldp+23,(vlTOPp->register_testbench__DOT__ctl_regB_assert_left));
        tracep->fullBit(oldp+24,(vlTOPp->register_testbench__DOT__ctl_regB_assert_right));
        tracep->fullBit(oldp+25,(vlTOPp->register_testbench__DOT__ctl_regC_assert_main));
        tracep->fullBit(oldp+26,(vlTOPp->register_testbench__DOT__ctl_regC_assert_left));
        tracep->fullBit(oldp+27,(vlTOPp->register_testbench__DOT__ctl_regC_assert_right));
        tracep->fullBit(oldp+28,(vlTOPp->register_testbench__DOT__ctl_regC_load));
        tracep->fullBit(oldp+29,(vlTOPp->register_testbench__DOT__ctl_regD_assert_main));
        tracep->fullBit(oldp+30,(vlTOPp->register_testbench__DOT__ctl_regD_assert_left));
        tracep->fullBit(oldp+31,(vlTOPp->register_testbench__DOT__ctl_regD_assert_right));
        tracep->fullBit(oldp+32,(vlTOPp->register_testbench__DOT__ctl_regD_load));
    }
}
