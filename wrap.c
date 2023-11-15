#include <stdio.h>
#include <stdlib.h>

extern void *__real_malloc(size_t size);

void *__wrap_malloc(size_t size) {
#ifdef __PAYLOAD__
    #define STR_EXPAND(tok) #tok
    #define STR(tok) STR_EXPAND(tok)
    printf("" STR(__PAYLOAD__) "\n");
#endif
    return __real_malloc(size);
}