#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>  

#define FN_LENGTH 100
#define MAX_LENGTH 1000
#define STACK_LIMIT 10

int main () {
    FILE *file;
    char filename[FN_LENGTH];
    char line[MAX_LENGTH]; 
    int stack[STACK_LIMIT];
    initialize(&stack); 

// it doesn't like using initialize or pop or push idk why figure this out later


    printf("This filereader will read a file and check for balanced parentheses.\n");
    printf("Enter the name of the file you want to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL ) {
        printf("Could not open file: %s", filename);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        for (size_t i = 0; i < strlen(line); i++) { 
            if (line[i] == '(') {  
                push(&stack, '('); // add to the stack
            } else if (line[i] == ')') {
                pop(&stack) == -1;
            } else {
                printf("parentheses unbalanced");
                break;
            }
            // check for closing parentheses and then remove the element from the stack 
            // if no closing parentheses is found, then break the loop and print out error
        }
    }

    fclose(file);
}