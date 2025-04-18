.set MAGIC, 0x2badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
	.long MAGIC
	.long FLAGS
	.long CHECKSUM

.section .text
.extern kmain
.global loader

Loader:
	mov $kernel_stack,%rsp
	movl %ebx, %edi
	movl %eax, %esi
	call kmain

_stop:
	cli
	hlt
	jmp _stop

.section .bss
.space 2*1024*1024
kernel_stack:
