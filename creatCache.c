#include "creatCache.h"

struct cacheInfo_t cacheInfo;
struct cache_t *cache = NULL;
unsigned int numOfBlock;

void initCache(char *configPath)
{
	FILE *configFp;
	int i = 0;
	unsigned int configVal[7];
	char currChar;
	char buf[8];

	configFp = fopen(configPath, "r");

	memset(buf, 0, sizeof(buf));
	while (fgets(buf, sizeof(buf), configFp) != NULL){		
		configVal[i] = atoi(buf);
		memset(buf, 0, sizeof(buf));
		i++;
	}

	cacheInfo.lineSize = configVal[0];
	cacheInfo.associat = configVal[1];
	cacheInfo.dataSize = configVal[2];
	cacheInfo.replacePolicy = configVal[3];
	cacheInfo.missPenalty = configVal[4];
	cacheInfo.writeAlloc = configVal[5];
	cacheInfo.writeBack = configVal[6];
	
	fclose(configFp);
}

void creatCache()
{
	numOfBlock = cacheInfo.dataSize / cacheInfo.lineSize;

	cache = (cache_t*)malloc(sizeof(cache_t) * numOfBlock);
}

