#ifndef INITCACHE_H
#define INITCACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cache_t{
	unsigned int lineSize;		/* block size		*/
	unsigned int associat;		/* cache assocativity	*/
	unsigned int dataSize;		/* data size		*/
	unsigned int replacePolicy;	/* replacement policy	*/
	unsigned int missPenalty;	/* miss penalty		*/
	unsigned int writeAlloc;	/* write allocate	*/
}cache_t;

typedef struct {
	char accessType;		/* l = load, s = store			*/
	unsigned int address;		/* 32 bit address			*/
	unsigned int lastMEMAccess;	/* Instructions since last mem access	*/
}trace_t;


extern cache_t cache;

void initCache(char*);

#endif
