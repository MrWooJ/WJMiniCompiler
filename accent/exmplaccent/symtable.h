/*--------------------------------------------------------------------------------*/
/* symtable.h                                                                     */
/* Author: @Alireza Arabi                                                         */
/* A generic Symbol Table ADT interface                                           */
/*--------------------------------------------------------------------------------*/

#ifndef SYMTABLE
#define SYMTABLE

/* A SymTable_T object is an unordered collection of key-value bindings.          */
typedef struct SymTable *SymTable_T;

/* Return a new SymTable object, or NULL if insufficient memory                   */
SymTable_T SymTable_new(void);

/* Free all memory occupied by oSymTable                                          */
void SymTable_free(SymTable_T oSymTable);

/* Return the number of bindings in oSymTable                                     */
int SymTable_getLength(SymTable_T oSymTable);

/* Adds the new binding (pcKey, pvValue) to oSymTable and return 1 (TRUE)         */
/* if oSymTable does not contain a binding with pcKey; otherwise oSymTable is     */
/* unchanged and return 0 (FALSE).  If insufficient memory, oSymTable is          */
/* unchanged and return 0 (FALSE)                                                 */
int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue);

/* Replace the existing value at pcKey with pvValue and return the old value if   */
/* oSymTable contains the binding; otherwise, leave oSymTable unchanged and       */
/* return NULL                                                                    */
void *SymTable_replace(SymTable_T oSymTable, const char *pcKey, const void *pvValue);

/* Return 1 (TRUE) if oSymTable contains a binding at pcKey; 0 (FALSE) otherwise  */
int SymTable_contains(SymTable_T oSymTable, const char *pcKey);

/* Return the value of the binding at pcKey in oSymTable; NULL otherwise          */
void *SymTable_get(SymTable_T oSymTable, const char *pcKey);

/* Remove the binding at pcKey from oSymTable and return the binding's value if   */
/* it exists; otherwise, no change to oSymTable and return NULL                   */
void *SymTable_remove(SymTable_T oSymTable, const char *pcKey);

/* Apply function pfApply to each binding in oSymTable, passing pvExtra as an     */
/* extra parameter                                                                */
void SymTable_map(SymTable_T oSymTable, void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra), const void *pvExtra);

#endif