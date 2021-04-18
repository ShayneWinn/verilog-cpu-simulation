ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
endif

default:
	@echo "-- VERILATE & BUILD --------"
	$(VERILATOR) -cc --exe --build -j constant_register.v constant_register_test.cpp
	@echo "-- RUN ---------------------"
	obj_dir/Vconstant_register
	@echo "-- DONE --------------------"
