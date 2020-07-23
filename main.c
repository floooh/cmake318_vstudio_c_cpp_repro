#include <stdio.h>

int main() {
    #if defined(__cplusplus)
        printf("!!!BUG!!! main.c is compiled as C++!\n");
        return 10;
    #else
        printf("OK: main.c is compiled as C.\n");
        return 0;
    #endif
}