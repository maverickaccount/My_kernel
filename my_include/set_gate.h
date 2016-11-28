#ifndef SET_GATE_H
#define SET_GATE_H

#define my_set_gate(gate_addr,info,addr) \
__asm__("rorl $16, %%eax\n\t" \
	"movw $0x0008, %%ax\n\t" \
	"rorl $16, %%eax\n\t" \
	"movl %%eax, %2\n\t" \
	"movl %%edx, %3\n\t" \
:: "d" (info), "a" (addr), "m" (*(gate_addr)), "m" (*(gate_addr + 4)));

void	my_set_gate_c(char *gate_addr, char type, char dpl, short addr);

#define my_set_intr_gate(n,addr) \
my_set_gate_c(idt[n],14,0,addr)

#define my_set_trap_gate(n,addr) \
my_set_gate_c(idt[n],15,0,addr)

#define my_set_system_gate(n,addr) \
my_set_gate_c(idt[n],15,3,addr)

#endif
