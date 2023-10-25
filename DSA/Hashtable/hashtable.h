#ifndef _HASH_TABLE_
#define _HASH_TABLE_

#include <stdint.h>

#define MAX_KEYS ('Z'-'A'+1)

typedef struct _node
{
    char word[20];
    char meaning[200];
    struct _node *next;
}Node;

typedef struct _list
{
    Node *tail;
    Node *head;
    int count;
}List;
void InitHashTable();
void InsertData(const char *word, const char *meaning);
void PrintHashtable();
const char *SearchMeaning(const char *word);
#endif //_HASH_TABLE_
