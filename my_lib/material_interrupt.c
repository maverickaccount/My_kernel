#include "../my_inclue/material_interrupt.h"

void	my_timer_interrupt(void);
void	my_keyboard_interrupt(void);
void	my_rs1_interrupt(void);
void	my_rs2_interrupt(void);
void	my_hd_interrupt(void);

void	set_material_interruption(void)
{
	my_set_intr_gate(0x20,&my_timer_interrupt);
	my_set_trap_gate(0x21,&my_keyboard_interrupt);
	my_set_trap_gate(0x24,&my_rs1_interrupt);
	my_set_trap_gate(0x23,&my_rs2_interrupt);
	my_set_trap_gate(0x2e,&my_hd_interrupt);
}
