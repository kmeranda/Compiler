#include <stdio.h>
#include <stdlib.h>
#include "global.h"

typedef enum {
	rax,
	rbx,
	rcx,
	rdx,
	rsi,
	rdi,
	rbp,
	rsp,
	r8,
	r9,
	r10,
	r11,
	r12,
	r13,
	r14,
	r15
} reg_name;

//int reg[16] = {1,0,1,1,1,1,1,1,1,1,0,0,0,0,0};	// 0 = free, 1 = allocated

const char * register_name(int r);	// returns the name of the register
int register_alloc();			// finds a free register to allocate
void register_free(int r);		// frees a register
