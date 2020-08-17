#include "creatCache.h"
#include "traceInput.h"


int main(int argc, char **argv)
{
	if (argc != 3){
		printf("Please input 2 arguments\n");
		printf("========================\n");
		printf(" First : Config file    \n");
		printf(" Second: Trace file     \n");
		printf("========================\n");
		return 0;
	}
	
	char *confPath = argv[1];
	char *tracePath = argv[2];
	
	initCache(confPath);

	traceInput(tracePath);



	return 0;

}
