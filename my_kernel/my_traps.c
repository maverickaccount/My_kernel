void	my_divide_error(void);
void	my_debug(void);
void	my_nmi(void);
void	my_int3(void)
void	my_overflow(void);
void	my_bounds(void);
void	my_invalid_op(void);
void	my_device_not_available(void);
void	my_double_fault(void);
void	my_coprocessor_segment_overrun(void);
void	my_invalid_TSS(void);
void	my_segment_not_present(void);
void	my_stack_segment(void);
void	my_general_protection(void);
void	my_page_fault(void);
void	my_reserved(void);
void	my_coprocessor_error(void);

void	my_trap_init(void)
{
	int i; //pour initialisé les instruction réservés par Intel

	my_set_trap_gate(0,&my_divide_error);
	my_set_trap_gate(1,&my_debug);
	my_set_trap_gate(2,&my_nmi);
	my_set_system_gate(3,&my_int3);
	my_set_system_gate(4,&my_overflow);
	my_set_system_gate(5,&my_bounds);
	my_set_trap_gate(6,&my_invalid_op);
	my_set_trap_gate(7,&my_device_not_available);
	my_set_trap_gate(8,&my_double_fault);
	my_set_trap_gate(9,&my_coprocessor_segment_overrun);
	my_set_trap_gate(10,&my_invalid_TSS);
	my_set_trap_gate(11,&my_segment_not_present);
	my_set_trap_gate(12,&my_stack_segment);
	my_set_trap_gate(13,&my_general_protection);
	my_set_trap_gate(14,&my_page_fault);
	my_set_trap_gate(15,&my_reserved);
	my_set_trap_gate(16,&my_coprocessor_error);

	for(i = 17; i < 32; i++)
		my_set_trap_gate(i,&reserved);
}
