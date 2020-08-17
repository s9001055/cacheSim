#ifndef TRACEINPUT_H
#define TRACEINPUT_H

typedef struct trace_t{
	char accessType;		/* l = load, s = store			*/
	unsigned int address;		/* 32 bit address			*/
}trace_t;

void traceInput(char*);
unsigned int _strHexToIntDec(unsigned char*);
unsigned int _hexToDec(unsigned char);

#endif
