ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
endif

default:
	@echo "-- Verilator hello-world simple example"
	@echo "-- VERILATE & BUILD --------"
	$(VERILATOR) -cc --exe --build -j address_register.v address_register_test.cpp
	@echo "-- RUN ---------------------"
	obj_dir/Vaddress_register
	@echo "-- DONE --------------------"
