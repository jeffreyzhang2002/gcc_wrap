# Example

This is an example of how to use the linker wrap command.

To compile use the following commands

```bash
gcc wrap.c main.c -o main -Wl,--wrap=malloc
./main
```

