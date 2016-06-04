/*--------------------------------------------------------------------------------*/
/* symtablehash.c                                                                 */
/* Author: @Alireza Arabi                                                         */
/* A generic Symbol Table ADT implementation via a resizing hash table            */
/*--------------------------------------------------------------------------------*/

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "symtable.h"

/* Constants for the expandable hash table                                        */
enum {ORIGINAL_BUCKET_COUNT = 509, MAX_BUCKET_COUNT = 65521};

/* Bucket sizes for expanding hash table                                          */
/* Selected for hash fn efficency (primes close to powers of two)                 */
static const int iBucketSizes[] = {ORIGINAL_BUCKET_COUNT, 1021, 2039, 4093, 8191, 16381, 32749, MAX_BUCKET_COUNT};

/* Each binding is stored in a SymTableNode, which are linked to form a list at   */
/* each hash bucket                                                               */
struct SymTableNode
{
  /* Key */
	const char *pcKey;

  /* Value */
	const void *pvValue;

  /* Address of next SymTableNode */
	struct SymTableNode *psNextNode;
};

/* A SymTable is an array of buckets that point to SymTableNodes                  */
struct SymTable
{
  /* Number of items in SymTable                                                  */
	int iLength;

  /* Current index into bucket sizes */
	int iBucketSizesIndex;

  /* Number of buckets in the table                                               */
	int iBucketCount;

  /* Address of the first bucket                                                  */
	struct SymTableNode **psBuckets;
};

/* Return a hash code for pcKey that is between 0 and iBucketCount-1, inclusive.  */
/* Adapted from the Princeton COS 217 lecture notes.                              */
static int SymTable_hash(const char *pcKey, int iBucketCount)
{
	enum {HASH_MULTIPLIER = 65599};
	int i;
	unsigned int uiHash = 0U;

	assert(pcKey != NULL);
	assert(iBucketCount != 0);

	for (i = 0; pcKey[i] != '\0'; i++)
		uiHash = uiHash * (unsigned int)HASH_MULTIPLIER + (unsigned int)pcKey[i];
	return (int)(uiHash % (unsigned int)iBucketCount);
}

/* Resizes the symbol table to iNewBucketSize and returns 1 (TRUE) if successful; */
/* If insufficient memory for the new table, return 0 (FALSE) without changing    */
/* the symbol table oSymTable                                                     */
static int SymTable_resize(SymTable_T oSymTable, int iNewBucketSize)
{
	struct SymTableNode **psNewBuckets;
	struct SymTableNode *psCurrentNode;
	struct SymTableNode *psTail;
	int i;
	int iNewHash;

	assert(oSymTable != NULL);
	psNewBuckets = (struct SymTableNode **)calloc(iNewBucketSize, sizeof(struct SymTableNode *));

	if (psNewBuckets == NULL)
		return 0;

	for (i = 0; i < oSymTable->iBucketCount; i++)
	{
		for (psCurrentNode = oSymTable->psBuckets[i]; psCurrentNode != NULL; psCurrentNode = psTail)
		{
			iNewHash = SymTable_hash(psCurrentNode->pcKey, iNewBucketSize);

			psTail = psCurrentNode->psNextNode;
			psCurrentNode->psNextNode = psNewBuckets[iNewHash];
			psNewBuckets[iNewHash] = psCurrentNode;
		}
	}
	free(oSymTable->psBuckets);
	oSymTable->psBuckets = psNewBuckets;
	oSymTable->iBucketCount = iNewBucketSize;
	return 1;
}

/* Expand the symbol table to the next larger bucket size.  If insufficient       */
/* memory, no change to the table is made                                         */
static void SymTable_expand(SymTable_T oSymTable)
{
	int iNewBucketSize;

	assert(oSymTable != NULL);

	iNewBucketSize = iBucketSizes[oSymTable->iBucketSizesIndex + 1];
	if (SymTable_resize(oSymTable, iNewBucketSize))
		oSymTable->iBucketSizesIndex++;
}

/* Return a new SymTable object, or NULL if insufficient memory                   */
SymTable_T SymTable_new(void)
{
	SymTable_T oSymTable;
	struct SymTableNode **psBuckets;

	oSymTable = (SymTable_T)malloc(sizeof(struct SymTable));
	if (oSymTable == NULL)
		return NULL;

	psBuckets = (struct SymTableNode **)calloc(ORIGINAL_BUCKET_COUNT, sizeof(struct SymTableNode *));
	if (psBuckets == NULL)
	{
		free(oSymTable);
		return NULL;
	}

	oSymTable->iLength = 0;
	oSymTable->iBucketSizesIndex = 0;
	oSymTable->iBucketCount = iBucketSizes[oSymTable->iBucketSizesIndex];
	oSymTable->psBuckets = psBuckets;
	return oSymTable;
}

/* Free all memory occupied by oSymTable                                          */
void SymTable_free(SymTable_T oSymTable)
{
	struct SymTableNode *psCurrentNode;
	struct SymTableNode *psNextNode;
	int i;

	assert(oSymTable != NULL);

	for (i = 0; i < oSymTable->iBucketCount; i++)
		for (psCurrentNode = oSymTable->psBuckets[i]; psCurrentNode != NULL; psCurrentNode = psNextNode)
		{
			psNextNode = psCurrentNode->psNextNode;
			free(psCurrentNode->pcKey);
			free(psCurrentNode);
		}
	free(oSymTable->psBuckets);
	free(oSymTable);
}

/* Return the number of bindings in oSymTable                                     */
int SymTable_getLength(SymTable_T oSymTable)
{
	assert(oSymTable != NULL);
	return oSymTable->iLength;
}

\/* Return 1 (TRUE) if oSymTable contains a binding at pcKey; 0 (FALSE) otherwise  */
int SymTable_contains(SymTable_T oSymTable, const char *pcKey)
{
	struct SymTableNode *psCurrentNode;
	int iHash;

	assert(oSymTable != NULL);
	assert(pcKey != NULL);

	iHash = SymTable_hash(pcKey, oSymTable->iBucketCount);
	for (psCurrentNode = oSymTable->psBuckets[iHash]; psCurrentNode != NULL; psCurrentNode = psCurrentNode->psNextNode)
	{
		if (strcmp(pcKey, psCurrentNode->pcKey) == 0)
			return 1;
	}
	return 0;
}

/* Adds the new binding (pcKey, pvValue) to oSymTable and return 1 (TRUE)         */
/* if oSymTable does not contain a binding with pcKey; otherwise oSymTable is     */
/* unchanged and return 0 (FALSE).  If insufficient memory, oSymTable is          */
/* unchanged and return 0 (FALSE)                                                 */
int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue)
{
	struct SymTableNode *psNewNode;
	int iHash;

	assert(oSymTable != NULL);
	assert(pcKey != NULL);
	assert(pvValue != NULL);

	if (SymTable_contains(oSymTable, pcKey))
		return 0;

	psNewNode = (struct SymTableNode *)malloc(sizeof(struct SymTableNode));
	if (psNewNode == NULL)
		return 0;

	psNewNode->pcKey = (const char *)malloc(strlen(pcKey) + 1);
	if (psNewNode->pcKey == NULL)
	{
		free(psNewNode);
		return 0;
	}

	strcpy(psNewNode->pcKey, pcKey);
	psNewNode->pvValue = pvValue;

	if ((oSymTable->iBucketCount < oSymTable->iLength + 1) && oSymTable->iBucketCount < MAX_BUCKET_COUNT)
		SymTable_expand(oSymTable);

	iHash = SymTable_hash(pcKey, oSymTable->iBucketCount);
	psNewNode->psNextNode = oSymTable->psBuckets[iHash];
	oSymTable->psBuckets[iHash] = psNewNode;
	oSymTable->iLength++;
	return 1;
}

/* Replace the existing value at pcKey with pvValue and return the old value if   */
/* oSymTable contains the binding; otherwise, leave oSymTable unchanged and       */
/* return NULL                                                                    */
void *SymTable_replace(SymTable_T oSymTable, const char *pcKey, const void *pvValue)
{
	struct SymTableNode *psCurrentNode;
	void *pvOldValue;
	int iHash;

	assert(oSymTable != NULL);
	assert(pcKey != NULL);
	assert(pvValue != NULL);

	iHash = SymTable_hash(pcKey, oSymTable->iBucketCount);
	for (psCurrentNode = oSymTable->psBuckets[iHash]; psCurrentNode != NULL; psCurrentNode = psCurrentNode->psNextNode)
	{
		if (strcmp(pcKey, psCurrentNode->pcKey) == 0)
		{
			pvOldValue = psCurrentNode->pvValue;
			psCurrentNode->pvValue = pvValue;
			return pvOldValue;
		}
	}
	return NULL;
}

/* Return the value of the binding at pcKey in oSymTable; NULL otherwise          */
void *SymTable_get(SymTable_T oSymTable, const char *pcKey)
{
	struct SymTableNode *psCurrentNode;
	int iHash;

	assert(oSymTable != NULL);
	assert(pcKey != NULL);

	iHash = SymTable_hash(pcKey, oSymTable->iBucketCount);
	for (psCurrentNode = oSymTable->psBuckets[iHash]; psCurrentNode != NULL; psCurrentNode = psCurrentNode->psNextNode)
	{
		if (strcmp(pcKey, psCurrentNode->pcKey) == 0)
			return psCurrentNode->pvValue;
	}
	return NULL;
}

/* Remove the binding at pcKey from oSymTable and return the binding's value if   */
/* it exists; otherwise, no change to oSymTable and return NULL                   */
void *SymTable_remove(SymTable_T oSymTable, const char *pcKey)
{
	struct SymTableNode *psPreviousNode;
	struct SymTableNode *psCurrentNode;
	void *pvValue;
	int iHash;

	assert(oSymTable != NULL);
	assert(pcKey != NULL);

	iHash = SymTable_hash(pcKey, oSymTable->iBucketCount);
	for (psCurrentNode = oSymTable->psBuckets[iHash], psPreviousNode = NULL; psCurrentNode != NULL; psPreviousNode = psCurrentNode, psCurrentNode = psCurrentNode->psNextNode)
	{
		if (strcmp(pcKey, psCurrentNode->pcKey) == 0)
		{
			pvValue = psCurrentNode->pvValue;

			if (psPreviousNode == NULL)
				oSymTable->psBuckets[iHash] = psCurrentNode->psNextNode;
			else
				psPreviousNode->psNextNode = psCurrentNode->psNextNode;

			free(psCurrentNode->pcKey);
			free(psCurrentNode);
			oSymTable->iLength--;
			return pvValue;
		}
	}
	return NULL;
}

/* Apply function pfApply to each binding in oSymTable, passing pvExtra as an     */
/* extra parameter                                                                */
void SymTable_map(SymTable_T oSymTable, void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra), const void *pvExtra)
{
	struct SymTableNode *psCurrentNode;
	int i;

	assert(oSymTable != NULL);
	assert(pfApply != NULL);
	assert(pvExtra != NULL);

	for (i = 0; i < oSymTable->iBucketCount; i++)
		for (psCurrentNode = oSymTable->psBuckets[i]; psCurrentNode != NULL; psCurrentNode = psCurrentNode->psNextNode)
			(*pfApply)(psCurrentNode->pcKey, psCurrentNode->pvValue, pvExtra);
}

/* Free memory occupied by last scope                                          */
void SymTable_free_last_scope(SymTable_T oSymTable)
{
	struct SymTableNode *psCurrentNode;
	struct SymTableNode *psNextNode;
	int i = oSymTable->iLength;

	assert(oSymTable != NULL);

	for (psCurrentNode = oSymTable->psBuckets[i]; psCurrentNode != NULL; psCurrentNode = psNextNode)
	{
		psNextNode = psCurrentNode->psNextNode;
		free(psCurrentNode->pcKey);
		free(psCurrentNode);
	}
	free(oSymTable->psBuckets[i]);
}