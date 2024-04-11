#include <stdio.h>
#include <stdlib.h>
#include "minilisp.h"

#define INPUT_BUF_SIZE 1024

int main(int argc, char **argv) {
    // Input string
    char input_buf[INPUT_BUF_SIZE] = {0};
    if (!fread(input_buf, 1, sizeof(input_buf), stdin))
        return 0;
    input_buf[INPUT_BUF_SIZE - 1] = '\0';
    char *str = input_buf;

    // The main loop
    for (;;) {
        if (!*str)
            return 0;
        char *output = exec_lisp(&str);
        if (!output)
            return 0;
        printf("%s\n", output);
        free(output);
    }
}
