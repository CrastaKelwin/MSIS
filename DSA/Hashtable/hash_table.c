#include "hashtable.h"
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static List hash_table[MAX_KEYS] = {};

static int HashKey(const char *word)
{
    return (tolower(word[0]) - 'a');
}

static Node *GetNewNode(const char *word, const char *meaning)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node)
    {
        strcpy(new_node->word, word);
        strcpy(new_node->meaning, meaning);
        new_node->next = NULL;
    }
    return new_node;
}

void InsertData(const char *word, const char *meaning)
{
    Node *new_node = GetNewNode(word, meaning);
    int hash_key = HashKey(word);
    if (hash_key >= 0 && hash_key < MAX_KEYS)
    {
        printf("word %s, key, %d\n", word, hash_key);
        if (hash_table[hash_key].tail != NULL)
        {
            hash_table[hash_key].tail->next = new_node;
            hash_table[hash_key].tail = new_node;
        }
        else
        {
            hash_table[hash_key].tail = hash_table[hash_key].head = new_node;
        }
        hash_table[hash_key].count++;
        printf("%s added Ok\n", word);
    }
    else
    {
        printf("Error Adding %s\n", word);
        free(new_node);
    }
}

void PrintHashtable()
{
    for (int i = 0; i < MAX_KEYS; i++)
    {
        printf("chain of key %c %d count %d\n", (char)i, i, hash_table[i].count);
        Node *n = hash_table[i].head;
        while (n != NULL)
        {
            printf("word %s, meaning %s\n", n->word, n->meaning);
            n = n->next;
        }
        printf("\n");
    }
}

void InitHashTable()
{
    memset(hash_table, 0, sizeof(hash_table));
}

const char *SearchMeaning(const char *word)
{
    int hash_key = HashKey(word);
    if (hash_key >= 0 && hash_key < MAX_KEYS)
    {
        Node *n = hash_table[hash_key].head;
        while (n != NULL)
        {
            if (strcmp(word, n->word) == 0)
            {
                return n->meaning;
            }
            n = n->next;
        }
        printf("\n");
    }
    return NULL;
}