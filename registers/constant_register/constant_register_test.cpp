#include <stdio.h>

#include "Vconstant_register.h"

void load_data(Vconstant_register* reg, uint8_t data){
    reg->i_load = 1;
    reg->eval();
    reg->i_load = 0;
    reg->b_data = data;
    reg->eval();
}

void run_load_tests(Vconstant_register* reg){
    printf("TEST: Load Tests (0-255): ");
    bool fail = false;
    for(int i = 0; i <= 255; i++){
        load_data(reg, i);
        if(reg->data != i){
            fail=true;
            printf("FAIL; expected %u actual %u\n", i, reg->data);
            break;
        }
    }
    if(!fail){
        printf("PASS\n");
    }
}

void run_assert_tests(Vconstant_register* reg){
    printf("TEST: Load Tests (0-255): ");
    bool fail = false;
    for(int i = 0; i <= 255; i++){
        reg->i_assert = 0;
        load_data(reg, i);
        reg->i_assert = 1;
        reg->eval();
        if(reg->b_main != i){
            fail=true;
            printf("FAIL; expected %u actual %u\n", i, reg->b_main);
            break;
        }
    }
    if(!fail){
        printf("PASS\n");
    }
}

int main(int argc, char** argv, char** env){
    Vconstant_register* CuT;
    CuT = new Vconstant_register;
    CuT->eval();
    run_load_tests(CuT);
    delete CuT;

    CuT = new Vconstant_register;
    CuT->eval();
    run_assert_tests(CuT);
    delete CuT;

}