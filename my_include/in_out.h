#ifndef IN_OUT_H
#define IN_OUT_H

#define my_outb(byte,port) \
__asm__("outb %%bl, %%ax\n\t" \
	:: "a" (port), "b" (byte))

#define my_inb(byte,port) \
__asm__("inb %%bx, %%al\n\t" \
	: "=a" (byte): "b" (port))

void	my_outb_pause(unsigned char byte, short port);
void	my_inb_pause(unsigned char byte, short port);

#endif
