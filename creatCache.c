#include "creatCache.h"

struct cacheInfo_t cacheInfo;
struct cache_t *cacheD = NULL;
struct cache_t **cacheN = NULL;
unsigned int numOfBlock;
unsigned int blockOffset;

void initCache(char *configPath)
{
	FILE *configFp;
	int i = 0;
	unsigned int configVal[7];
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

	numOfBlock = cacheInfo.dataSize / cacheInfo.lineSize;
	blockOffset = _log2(numOfBlock);
	
	if (cacheInfo.associat < 2){
		cacheD = (cache_t*)malloc(sizeof(cache_t) * numOfBlock);
		memset(cacheD, 0, sizeof(cache_t) * numOfBlock);
	}else{
		cacheN = (cache_t**)malloc(sizeof(cache_t*) * numOfBlock);

		for (i = 0; i < numOfBlock; i++)
			cacheN[i] = (cache_t*)malloc(sizeof(cache_t) * cacheInfo.associat);

		memset(cacheN, 0, sizeof(cache_t) * cacheInfo.associat * numOfBlock);
	}

	fclose(configFp);
}

unsigned int _log2(unsigned int numBlock)
{
	unsigned int bit = 0;
	while ((numBlock >> 1) != 0){
		bit++;
	}

	return bit;
}

