#include "my_fs.h"
#include "my_const.h"

#define BUF_END 0xFFFFF
#define BUF_START 0xA0000

int NR_BUFFERS = 0; //nombre maximal de tampon en memoire vive en meme temps, cf my_buffer_init()

my_struct_buffer_head *start_buf = (my_struct_buffer_head *) BUF_START;
my_struct_buffer_head *free_list; //utilisé pour la liste des tampon libres
my_struct_buffer_head *hash_list[307]; //utilisé pour aller plus vite dans la liste chainé, maximum \
					307 pointeurs sur des buffer_head (tampon)

void	my_buffer_init(void)
{
	my_struct_buffer_head *current = start_buf;
	void *data = (void *) BUF_END;
	int i = 0;

	while(data > current)
	{
		current->dev = 0;
		current->blocknr = 0;
		current->uptodate = 0;
		current->dirt = 0;
		current->count = 0;
		current->lock = 0;
		current->wait = NULL;
		current->prev = NULL;
		current->data = data;
		current->next = NULL;
		if(i > 0)
		current->prev_free = current - sizeof(my_struct_buffer_head);
		else
		current->prev_free = NULL;

		if((data - BLOCK_SIZE) > (current + sizeof(my_struct_buffer_head)))
		current->next_free = current + sizeof(my_struct_buffer_head);
		else
		current->next_free = free_list;

		current += sizeof(my_struct_buffer_head);
		data -= BLOCK_SIZE;
		i++;
	}
	NR_BUFFERS = i - 1;
	current -= sizeof(my_struct_buffer_head);
	data += BLOCK_SIZE;

	printf("start_buf : 0x%x\n", &start_buf);
	printf("data : 0x%x\n", &data);
	printf("NR_BUFFERS : %d\n", NR_BUFFERS);
		for(i = 0; i < 307; i++)
			hash_list[i] = NULL;
}
