#ifndef CREATCACHE_H
#define CREATCACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cacheInfo_t{
	unsigned int lineSize;		/* block size		*/
	unsigned int associat;		/* cache assocativity	*/
	unsigned int dataSize;		/* total cache size	*/
	unsigned int replacePolicy;	/* replacement policy	*/
	unsigned int missPenalty;	/* miss penalty		*/
	unsigned int writeAlloc;	/* write allocate	*/
	unsigned int writeBack;		/* 1 = wirte back, 0 = write through	*/
}cacheInfo_t;

typedef struct cache_t{
	unsigned int valid;	/* valid bit	*/
	unsigned int dirty;	/* dirty bit	*/
	unsigned int tag;
}cache_t;

typedef struct {
	char accessType;		/* l = load, s = store			*/
	unsigned int address;		/* 32 bit address			*/
	unsigned int lastMEMAccess;	/* Instructions since last mem access	*/
}trace_t;


extern cacheInfo_t cacheInfo;
extern cache_t *cache;
extern unsigned int numOfBlock;


void initCache(char*);
void creatCache();

#endif
