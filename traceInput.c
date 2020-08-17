#include "traceInput.h"
#include "creatCache.h"

void traceInput(char *tracePath)
{
	FILE *tracefp;
	struct trace_t trace;
	char buf[16];
	int i;
	char addrBuf[9];

	tracefp = fopen(tracePath, "r");

	memset(buf, 0, sizeof(buf));

	while (fgets(buf, sizeof(buf), tracefp) != NULL){
		trace.accessType = buf[0];
		
		for (i = 4; i < 12; i++){
			addrBuf[i - 4] = buf[i];
		}
		addrBuf[9] = '\0';
		trace.address = _strHexToIntDec(addrBuf);
	}

	fclose(tracefp);
}

unsigned int _strHexToIntDec(unsigned char *hex)
{
	unsigned int total = 0;
	unsigned int dec;
	int i;
	int j = 7;	/* MSB to LSB weight	*/
	
	for (i = 0; i < 8; i++){
		dec = _hexToDec(hex[i]);
		dec = (dec << (j * 4));
		total += dec;
		j--;
	}

	return total;
}

unsigned int _hexToDec(unsigned char hex)
{
	switch (hex){
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'a':
			return 10;
		case 'b':
			return 11;
		case 'c':
			return 12;
		case 'd':
			return 13;
		case 'e':
			return 14;
		case 'f':
			return 15;
		default:
			printf("traceInput _hexToDec: hex error\n");
			exit(1);
	}
}
