#ifndef SET_FULL_DESC_H
#define SET_FULL_DESC_H

#define set_gba(gba,addr) \
__asm__("andb $0xf0, %%al\n\t" \
	"movb %2, %%bl\n\t" \
	"andb $0x0f, %%bl\n\t" \
	"orb %%al, %%bl\n\t" \
: "=b" (*(addr + 6)): "a" (gba), "m" (*(addr + 6)), "b" (0))

#define set_right(right,addr) \
__asm__("movb %%al, %1\n\t" \
:: "a" (right), "m" (*(addr + 5)))

void	set_full_desc(int address, int limit, char g, char b, char a2, char p, char dpl, char dpl2, char s, char e, char x, char rw, char a, char *desc);

#endif
