.globl _my_idt, _my_gdt, _my_pg_dir

_my_gdt: .quad 0x0000000000000000
	 .quad 0x00c09a00000007ff
	 .quad 0x00c09200000007ff
	 .quad 0x0000000000000000
	 .fill 512,8,0
