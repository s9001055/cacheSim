#include "initCache.h"

struct cache_t cache;

void initCache(char *configPath)
{
	FILE *configFp;
	int i = 0;
	unsigned int configVal[6];
	char currChar;
	char buf[8];

	configFp = fopen(configPath, "r");

	memset(buf, 0, sizeof(buf));
	while (fgets(buf, sizeof(buf), configFp) != NULL){		
		configVal[i] = atoi(buf);
		memset(buf, 0, sizeof(buf));
		i++;
	}

	cache.lineSize = configVal[0];
	cache.associat = configVal[1];
	cache.dataSize = configVal[2];
	cache.replacePolicy = configVal[3];
	cache.missPenalty = configVal[4];
	cache.writeAlloc = configVal[5];
	
	fclose(configFp);
}
