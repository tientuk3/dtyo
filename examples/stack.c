#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Vars {
    char password[5]; // Reference password
    char input[5]; // User input password
    bool correct; // Flag to indicate correct password
    char overflow_padding[16]; // Some overflow area to not trigger the stack smashing warning
} Vars;


int main(int argc, char** argv) {

    if (argc != 2) {
        printf("USAGE: stack [password]\n");
        return -1;
    }

    // The variables are in a struct because otherwise I couldn't get GCC to spit out
    // the memory layout I wanted
    Vars variables = {
        .password = "1234",
        .correct = false
    };

    memset(variables.overflow_padding, 0xAA, 16); // for debugger

    // Copy password argument from command line. Possibly overflow to the "correct" flag
    strcpy(variables.input, argv[1]);
    if (0 == strcmp(variables.input, variables.password)) {
        variables.correct = true; // User has input the correct password
    }

    if (variables.correct) {
        // It is possible to get here with a wrong password that is too long
        printf("Right password!\n");
    } else {
        printf("Wrong password!\n");
    }

    return 0;
}