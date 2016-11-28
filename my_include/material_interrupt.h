#infdef MATERIAL_INTERRUPT_H
#define MATERIAL_INTERRUPT_H

#define cli() \
__asm__("cli" \
::) //masque toute les interruptions materielles masquables

#define sti() \
__asm__("sti" \
::) //retabli les interruption materielles masquables

void    set_material_interruption(void);

#endif
