ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
endif

default:
	@echo "-- VERILATE & BUILD --------"
	$(VERILATOR) -cc --exe --build -j general_register.v general_register_test.cpp
	@echo "-- RUN ---------------------"
	obj_dir/Vgeneral_register
	@echo "-- DONE --------------------"
