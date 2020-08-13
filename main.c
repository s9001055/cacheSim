#include "creatCache.h"

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
	
	FILE *TraceFp;
	char *confPath = argv[1];
	char *tracePath = argv[2];
	
	initCache(confPath);

	TraceFp = fopen(tracePath, "r");
	
	fclose(TraceFp);




	return 0;

}
