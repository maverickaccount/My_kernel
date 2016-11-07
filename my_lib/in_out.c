#include "../my_include/in_out.h"

void	my_outb_pause(unsigned char byte, short port)
{
	my_outb(byte,port);
	int fake_test;
	fake_test = 55300;
	if(fake_test)
	fake_test = 0;
}

void	my_inb_pause(unsigned char byte, short port)
{
	my_inb(byte,port);
	int fake_test;
	fake_test = 55300;
	if(fake_test)
	fake_test = 0;
}
