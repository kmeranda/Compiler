#include "register.h"

const char * register_name(int r) {
	switch (r) {
		case rax:
			return "%rax";
			break;
		case rbx:
			return "%rbx";
			break;
		case rcx:
			return "%rcx";
			break;
		case rdx:
			return "%rdx";
			break;
		case rsi:
			return "%rsi";
			break;
		case rdi:
			return "%rdi";
			break;
		case rbp:
			return "%rbp";
			break;
		case rsp:
			return "%rsp";
			break;
		case r8:
			return "%r8";
			break;
		case r9:
			return "%r9";
			break;
		case r10:
			return "%r10";
			break;
		case r11:
			return "%r11";
			break;
		case r12:
			return "%r12";
			break;
		case r13:
			return "%r13";
			break;
		case r14:
			return "%r14";
			break;
		case r15:
			return "%r15";
			break;
	}
}

int register_alloc() {
	int i;
	for(i=0; i<16; i++) {
		if (reg[i]==0) {
			reg[i] = 1;
			return i;
		}
	}
	printf("out of registers.\n");
	exit(1);
}

void register_free(int r) {
	if (r>=0 && r<16) {
		reg[r] = 0;
	}
	else {
		printf("error: attempted to free invalid register number.\n");
		exit(1);
	}
}



