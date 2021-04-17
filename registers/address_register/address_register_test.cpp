#include <verilated.h>
#include <stdio.h>

#include "Vaddress_register.h" // generated from tb.v

int main(int argc, char** argv, char** env){
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vaddress_register* CuTregister;

    //================================================================================

    // begin data latching test
    printf("TEST: Data Latching (0-65535): ");
    CuTregister = new Vaddress_register{contextp};
    CuTregister->eval();

    bool fail = false;
    for(int i = 0; i <= 65535; i++){
        CuTregister->transfer_bus = i;
        CuTregister->i_load_transfer = 1;
        CuTregister->eval();
        CuTregister->i_load_transfer = 0;
        CuTregister->eval();
        if(CuTregister->data != i){
            printf("FAIL; expected: %u actual: %d\n", i, CuTregister->data);
            fail = true;
            break;
        }
    }
    if(!fail){
        printf("PASS\n");
    }

    delete CuTregister;
    // end data latching test

    //================================================================================

    // begin bus assertion tests
    printf("TESTS: Bus Assertion (0-65535):\n");
        printf("\tTransfer Bus Assertions: ");
        CuTregister = new Vaddress_register;
        CuTregister->eval();
        fail = false;
        for(int i = 0; i <= 65535; i++){
            // load value
            CuTregister->transfer_bus = i;
            CuTregister->i_load_transfer = 1;
            CuTregister->eval();
            CuTregister->i_load_transfer = 0;
            CuTregister->eval();
            CuTregister->transfer_bus = 0;

            // assert to bus
            CuTregister->i_assert_transfer = 1;
            CuTregister->eval();
            if(CuTregister->transfer_bus != i){
                printf("FAIL; expected: %u actual: %d\n", i, CuTregister->transfer_bus);
                fail = true;
                break;
            }
        }
        if (!fail){
            printf("PASS\n");
        }
    delete CuTregister;

    printf("\tAddress Bus Assertions: ");
        CuTregister = new Vaddress_register;
        CuTregister->eval();
        fail = false;
        for(int i = 0; i <= 65535; i++){
            // load value
            CuTregister->transfer_bus = i;
            CuTregister->i_load_transfer = 1;
            CuTregister->eval();
            CuTregister->i_load_transfer = 0;
            CuTregister->eval();

            // assert to bus
            CuTregister->i_assert_address = 1;
            CuTregister->eval();
            if(CuTregister->address_bus != i){
                printf("FAIL; expected: %u actual: %d\n", i, CuTregister->address_bus);
                fail = true;
                break;
            }
        }
        if (!fail){
            printf("PASS\n");
        }
    delete CuTregister;
    // end bus assertion tests

    //================================================================================

    // begin increment and decrment tests
    printf("TESTS: Increment and Decrment\n");
    printf("\tTest: Regular increment: ");
    CuTregister = new Vaddress_register;
    CuTregister->eval();
        // load value
        CuTregister->transfer_bus = 64;
        CuTregister->i_load_transfer = 1;
        CuTregister->eval();
        CuTregister->i_load_transfer = 0;
        CuTregister->eval();

        // working
        CuTregister->i_inc = 1;
        CuTregister->eval();
        printf(CuTregister->data == 65 ? "PASS\n" : "FAIL; expected: %d actual: %d\n", 65, CuTregister->data);
    delete CuTregister;

    printf("\tTest: Wrapping increment: ");
    CuTregister = new Vaddress_register;
    CuTregister->eval();
        // load value
        CuTregister->transfer_bus = 65535;
        CuTregister->i_load_transfer = 1;
        CuTregister->eval();
        CuTregister->i_load_transfer = 0;
        CuTregister->eval();

        // working
        CuTregister->i_inc = 1;
        CuTregister->eval();
        printf(CuTregister->data == 0 ? "PASS\n" : "FAIL; expected: %d actual: %d\n", 0, CuTregister->data);
    delete CuTregister;

    printf("\tTest: Regular decrement: ");
    CuTregister = new Vaddress_register;
    CuTregister->eval();
        // load value
        CuTregister->transfer_bus = 64;
        CuTregister->i_load_transfer = 1;
        CuTregister->eval();
        CuTregister->i_load_transfer = 0;
        CuTregister->eval();

        // working
        CuTregister->i_dec = 1;
        CuTregister->eval();
        printf(CuTregister->data == 63 ? "PASS\n" : "FAIL; expected: %d actual: %d\n", 63, CuTregister->data);
    delete CuTregister;

    printf("\tTest: Wrapping decrement: ");
    CuTregister = new Vaddress_register;
    CuTregister->eval();
        // load value
        CuTregister->transfer_bus = 0;
        CuTregister->i_load_transfer = 1;
        CuTregister->eval();
        CuTregister->i_load_transfer = 0;
        CuTregister->eval();

        // working
        CuTregister->i_dec = 1;
        CuTregister->eval();
        printf(CuTregister->data == 65535 ? "PASS\n" : "FAIL; expected: %d actual: %d\n", 65535, CuTregister->data);
    delete CuTregister;
    // end increment and decrement tests

    //================================================================================

    delete contextp;
    return 0;
}