#ifndef _CODE16GCC_H_
#define _CODE16GCC_H_
__asm__(".code16gcc");
__asm__("jmpw $0x0000, $main");
#endif
