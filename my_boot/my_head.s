.text
.globl _my_idt, _my_gdt, _my_pg_dir

_my_pg_dir:
my_startup32:

my_setup_idt:
	lea my_ignore_int,%ebx
	movl $0x00080000,%eax
	movw %bx,%ax
	movw 0x8E00,%bx # 1 00 0 1110 00000000 (present,dpl,type)
	lea _my_idt,%edi
	movl $256,%ecx
my_rp_sidt:
	movl %eax,(%edi)
	movl %ebx,4(%edi)
	dec %ecx
	addl $8,%edi
	cmp $0,%ecx
	jne my_rp_sidt
	lidt my_idt_desc
	ret

my_ignore_int:
	movb $33,0xb8000+160 #afficher ! ligne 1 colonne 0
	movb $2,0xb8000+161 #indique la couleur verte
	iret

my_idt_desc:
	.word 512 * 8 - 1 #last idt byte
	.long _my_idt

my_gdt_desc:
	.word 512 * 8 - 1 #last gdt byte
	.long _my_gdt

_my_idt : .fill 512,8,0

_my_gdt: .quad 0x0000000000000000
	 .quad 0x00c09a00000007ff
	 .quad 0x00c09200000007ff
	 .quad 0x0000000000000000
	 .fill 512,8,0
