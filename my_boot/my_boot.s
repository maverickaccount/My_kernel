.text
.globl _my_boot

_my_boot:
init_pic:
	movb $0x11,%al #ICW1 : 00010001
	outb %al,$0x20
	.word 0x96ff,0x96ff #waiting
	outb %al,$0xa0
	.word 0x96ff,0x96ff
	movb $0x20,%al #ICW2 : 00100000
	outb %al,$0x21 #(indique que le nouveau vecteur de IRQ0 est 0x20)
	.word 0x96ff,0x96ff
	movb $0x28,%al #ICW2 du PIC esclave : 00101000
	outb %al,$0xa1 #(indique que le nouveau vecteur de IRQ8 est 0x28)
	.word 0x96ff,0x96ff
	movb $0x04,%al #ICW3 du PIC maitre : 00000100
	outb %al,$0x21 #(indique que le PIC est branché a IRQ2)
	.word 0x96ff,0x96ff
	movb $0x02,%al #ICW3 du PIC esclave : 00000010
	outb %al,$0xa1 #(indique que le PIC esclave est branché a IRQ2 du PIC maitre)
	.word 0x96ff,0x96ff
	movb $0x01,%al #ICW4 defini microprocesseur Intel : 00000001
	outb %al,$0x21
	.word 0x96ff,0x96ff
	outb %al,$0xa1
	.word 0x96ff,0x96ff
	movb $0xff,%al #OCW1 : 11111111 (on masque tout le bordel wallah)
	outb %al,$0x21
	.word 0x96ff,0x96ff
	outb %al,$0xa1
