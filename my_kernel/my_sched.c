#include "../my_include/my_sched.h"

void	my_system_call(void);

static my_task_union my_init_task = {MY_INIT_TASK,};
my_task_struct *task_struct_table[NR_TASKS] = {&my_init_task,};
my_task_struct *current = &my_init_task;

void	my_sched_init(void)
{
	my_set_system_gate(0x80,&my_system_call);
}
