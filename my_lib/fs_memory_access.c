unsigned char	my_get_fs_byte(char *offset)
{
	unsigned char byte;
	__asm__("movb %%fs:%0,%%al\n\t" \
		"movb %%al,%1\n\t" \
		:: "m" (*(offset)), "m" (byte));
	return byte;
}

short		my_get_fs_long(char *offset)
{
	short word;
	__asm__("movw %%fs:%0,%%ax\n\t" \
		"movw %%ax,%1\n\t" \
		:: "m" (*(offset)), "m" (word));
	return word;
}

unsigned long	my_get_fs_dword(char *offset)
{
	unsigned long dword;
	__asm__("movl %%fs:%0,%%eax\n\t" \
		"movl %%eax,%1\n\t" \
	:: "m" (*(offset)), "m" (dword));
	return dword;
}

void	my_put_fs_byte(unsigned char byte, char *offset)
{
	__asm__("movb %0,%%al\n\t" \
		"movb %%al,%%fs:%1\n\t" \
		:: "m" (byte), "m" (*(offset)));
	return;
}

void	my_put_fs_word(short word, char *offset)
{
	__asm__("movw %0,%%ax\n\t" \
		"movw %%ax,%%fs:%1\n\t" \
		:: "m" (word), "m" (*(offset)));
	return;
}

void	my_put_fs_dword(unsigned long dword, char *offset)
{
	__asm__("movl %0,%%eax\n\t" \
		"movl %%eax,%%fs:%1\n\t" \
	:: "m" (dword), "m" (*(offset)));
	return;
}
