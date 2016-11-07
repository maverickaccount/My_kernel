#include <stdio.h>
#include <stdlib.h>
#include "./my_include/base_limit.h"
#include "./my_lib/set_full_desc.h"

void	set_full_desc(int address, int limit, char g, \
	char b, char a2, char p, char dpl, char dpl2, char s, char e, char x, \
	char rw, char a, char *desc)
{
	unsigned char right;
	unsigned char gba;

	right = (p << 7) + (dpl << 6) + (dpl2 << 5) + (s << 4) + \
	(e << 3) + (x << 2) + (rw << 1) + a;

	gba = (g << 3) + (b << 2) + a2;
	gba = gba << 4;

	set_right(right,desc);
	set_gba(gba,desc);
	my_set_base(desc,address);
	my_set_limit(desc,limit);
}
