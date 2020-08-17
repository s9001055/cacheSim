#ifndef CREATCACHE_H
#define CREATCACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define byteOffset 2

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
	unsigned int lruBit;
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
extern cache_t *cacheD;
extern cache_t **cacheN;
extern unsigned int numOfBlock;
extern unsigned int blockOffset;
extern unsigned int addressTag;

void initCache(char*);
unsigned int _log2(unsigned int);

#endif
