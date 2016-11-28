#include "../my_include/set_gate.h"

void	my_set_gate_c(char *gate_addr, char type, char dpl, short addr)
{
	short info = 0x8000 + (dpl << 13) + (type << 8);

	my_set_gate(gate_addr,info,addr);
	return;
}
