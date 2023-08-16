#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdint.h>
#include "retcode.h"

typedef struct _array{
    int32_t *array_ptr;
    int16_t current_size;
    int16_t total_size;
}Array;

Array *InitialiseArray(int16_t size);
RetCode InsertData(Array *array , int32_t data);
RetCode DisplayArray(Array *ar);
#endif /* _ARRAY_H_ */ 