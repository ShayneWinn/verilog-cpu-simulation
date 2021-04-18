#include <verilated.h>
#include <stdio.h>

#include "Vgeneral_register.h" // generated from tb.v

int main(int argc, char** argv, char** env){
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vgeneral_register* CuTregister;

    // begin data latching test
    printf("\nTEST: Data Latching (0-255): ");
    CuTregister = new Vgeneral_register{contextp};

    bool fail = false;
    for(int i = 0; i <= 255; i++){
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
    // begin bus assertion tests
    printf("\nTESTS: Bus Assertion (0-255):\n");
    printf("\tTransfer Bus Assertions: ");
    CuTregister = new Vgeneral_register;
    fail = false;
    for(int i = 0; i <= 255; i++){
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

    printf("\tLeft Bus Assertions: ");
    CuTregister = new Vgeneral_register;
    fail = false;
    for(int i = 0; i <= 255; i++){
        // load value
        CuTregister->transfer_bus = i;
        CuTregister->i_load_transfer = 1;
        CuTregister->eval();
        CuTregister->i_load_transfer = 0;
        CuTregister->eval();

        // assert to bus
        CuTregister->i_assert_left = 1;
        CuTregister->eval();
        if(CuTregister->left_bus != i){
            printf("FAIL; expected: %u actual: %d\n", i, CuTregister->left_bus);
            fail = true;
            break;
        }
    }
    if (!fail){
        printf("PASS\n");
    }
    delete CuTregister;

    printf("\tRight Bus Assertions: ");
    CuTregister = new Vgeneral_register;
    fail = false;
    for(int i = 0; i <= 255; i++){
        // load value
        CuTregister->transfer_bus = i;
        CuTregister->i_load_transfer = 1;
        CuTregister->eval();
        CuTregister->i_load_transfer = 0;
        CuTregister->eval();

        // assert to bus
        CuTregister->i_assert_right = 1;
        CuTregister->eval();
        if(CuTregister->right_bus != i){
            printf("FAIL; expected: %u actual: %d\n", i, CuTregister->right_bus);
            fail = true;
            break;
        }
    }
    if (!fail){
        printf("PASS\n");
    }
    delete CuTregister;
    // end bus assertion tests

    delete contextp;
    return 0;
}