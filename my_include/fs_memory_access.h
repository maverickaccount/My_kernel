#ifndef FS_MEMORY_ACCESS_H
#define FS_MEMORY_ACCESS_H

unsigned char	my_get_fs_byte(char *offset);
short		my_get_fs_word(char *offset);
unsigned long	my_get_fs_dword(char *offset);

void		my_put_fs_byte(unsigned char byte, char *offset);
void		my_put_fs_word(short word, char *offset);
void		my_put_fs_dword(unsigned long dword, char *offset);

#endif
