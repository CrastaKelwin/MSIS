#ifndef _RETCODE_H_
#define _RETCODE_H_

typedef enum _retcode_t{
    kRetCodeOk = 0,
    kRetCodeBadParam,
    kRetCodeError,
    kRetCodeFound,
    kRetCodeNotFound
} RetCode;

#endif //_RETCODE_H_