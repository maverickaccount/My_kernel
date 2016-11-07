#ifndef TSS_LDT_MACROS_H
#define TSS_LDT_MACROS_H

#define FIRST_TSS_ENTRY 4
#define FIRST_LDT_ENTRY (FIRST_TSS_ENTRY + 1)
#define tss_index(n) ((((unsigned int) n) * 2) + FIRST_TSS_ENTRY)
#define ldt_index(n) ((((unsigned int) n) * 2) + FIRST_LDT_ENTRY)
#define _TSS(n) (((((unsigned int) n) * 2) + FIRST_TSS_ENTRY) * 8)
#define _LDT(n) (((((unsigned int) n) * 2) + FIRST_LDT_ENTRY) * 8)

#define my_set_tssldt_desc(num,address,type) \
__asm__("movw $0x68, %1\n\t" \
	"movl %0, %%eax\n\t" \
	"movw %%ax, %2\n\t" \
	"rorl $16, %%eax\n\t" \
	"movb %%al, %3\n\t" \
	"movb %7, %%bl\n\t" \
	"movb %%bl, %4\n\t" \
	"movb $0, %5\n\t" \
	"rorl $8, %%eax\n\t" \
	"movb %%al, %6\n\t" \
	:: "m" (address), "m" (*(num)), "m" (*(num + 2)), \
	"m" (*(num + 4)), "m" (*(num + 5)), "m" (*(num + 6)), \
	"m" (*(num + 7)), "m" (type))

#define my_set_tss_desc(n,addr) my_set_tssldt_desc(n,addr,"0x89")
#define my_set_ldt_desc(n,addr) my_set_tssldt_desc(n,addr,"0x82")

#define tr_init(n) \
__asm__("ltr %%ax" \
	:: "a" (_TSS(n)))

#define ldtr_init(n) \
__asm__("lldt %%ax" \
	:: "a" (_LDT(n)))

#define my_str(n) \
__asm__("movl $0x00, %%eax\n\t" \
	"str %%ax\n\t" \
	"subl $32, %%eax\n\t" \
	"rorl $3, %%eax\n\t" \
	"movw %%ax, %0\n\t" \
:: "m" (n))

#endif
