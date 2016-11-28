#include "../my_include/my_sched.h"

void	my_system_call(void);

void	my_sched_init(void)
{
	my_set_system_gate(0x80,&my_system_call);
}
