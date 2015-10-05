#include "cpu/exec/template-start.h"

#define instr jmp

static void do_execute() {
	int res = op_src->val;
	res = res << (32 - (DATA_BYTE << 3)) >> (32 - (DATA_BYTE << 3)); 
	cpu.eip = cpu.eip + res;
#if DATA_BYTE == 2
	cpu.eip = cpu.eip & 0xffff;
#endif
	print_asm_template1();
}

make_instr_helper(i)
make_instr_helper(rm)
#include "cpu/exec/template-end.h"


