#define my_set_base(addr,base) \
__asm__("movw %%ax, %0\n\t" \
	"rorl $16, %%eax\n\t" \
	"movb %%al, %1\n\t" \
	"rorl $8, %%eax\n\t" \
	"movb %%al, %2" \
:: "m" (*(addr + 2)), "m" (*(addr + 4)), "m" (*(addr + 7)), "a" (base))

#define my_get_base(addr,base) \
__asm__("movw %1, %%ax\n\t" \
	"roll $8, %%eax\n\t" \
	"movb %3, %%al\n\t" \
	"roll $8, %%eax\n\t" \
	"movb %2, %%al\n\t" \
	"rorl $16, %%eax" \
: "=a" (base) : "m" (*(addr + 2)), "m" (*(addr + 4)), "m" (*(addr + 7)), "a" (0))

#define my_set_limit(addr,limit) \
__asm__("movw %%ax, %0\n\t" \
	"xorl %%ebx, %%ebx\n\t" \
	"movb %1, %%bl\n\t" \
	"andb $0xf0, %%bl\n\t" /* (met a zero les 4 derniers bits de bl) */ \
	"roll $16, %%eax\n\t" \
	"orb %%bl, %%al\n\t" /* (inscrit les 4 premiers bits de bl sur les 4 premiers bits de al) */ \
	"movb %%al, %1\n\t" \
:: "m" (*(addr)), "m" (*(addr + 6)), "a" (limit))

#define my_get_limit(addr,limit) \
__asm__("movb %2, %%al\n\t" \
	"andb $0x0f, %%al\n\t" \
	"rorl $16, %%eax\n\t" \
	"movw %1, %%ax\n\t" \
: "=a" (limit) : "m" (*(addr)), "m" (*(addr + 6)), "a" (0))
