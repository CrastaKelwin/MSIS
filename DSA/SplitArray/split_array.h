#ifndef _SPLIT_ARRAY_H_
#define _SPLIT_ARRAY_H_

#include "array.h"

#define MAX_SPLIT_SIZE 20

typedef struct _split_array{
    Array **array_ptr;
    int16_t total_size;
}SplitArray;

SplitArray *SplitArrayTo_N_Parts(Array *array, int16_t no_of_splits);

#endif /* _SPLIT_ARRAY_H_ */ 