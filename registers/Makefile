ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
endif

default:
	@echo "-- Verilator hello-world simple example"
	@echo "-- VERILATE & BUILD --------"
	$(VERILATOR) -cc --exe --build -j --top-module register_testbench register_testbench.v register_bus_test.cpp
	@echo "-- RUN ---------------------"
	obj_dir/Vregister_testbench
	@echo "-- DONE --------------------"
