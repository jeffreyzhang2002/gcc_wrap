# To set this up with the provided sh script run the following command

```bash
curl -s https://raw.githubusercontent.com/jeffreyzhang2002/gcc_wrap/master/setup.sh | bash
```

# Example

This is an example of how to use the linker wrap command.

To compile use the following commands

```bash
gcc wrap.c -Wl,--wrap=malloc -D __PAYLOAD__="YOUR TEXT HERE" main.c -o main
./main
```

To create an alias
```
alias gcc="gcc wrap.c -Wl,--wrap=malloc -D __PAYLOAD__=\"YOUR TEXT HERE\""
```

You can override your own function by changing the defintion inside wrap.c
```c
// Add any includes necessary here
#include <stdio.h>
#include <stdlib.h>

// Define the extern version of the real function
// Change function defintion to whatever you want but need to prefix with __real
// This is optional if you do not with to call the original function
extern void *__real_malloc(size_t size);

// This is the function that gets wrapped
void *__wrap_malloc(size_t size) {
#ifdef __PAYLOAD__
    #define STR_EXPAND(tok) #tok
    #define STR(tok) STR_EXPAND(tok)
    printf("" STR(__PAYLOAD__) "\n"); //This lines is injected before calling the real malloc
#endif
    return __real_malloc(size); //Calling the real malloc
}
```