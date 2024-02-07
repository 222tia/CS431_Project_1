#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define FN_LENGTH 100
#define MAX_LENGTH 1000
#define STACK_LIMIT 10
#define SIZE 4  
int top = -1, stack[SIZE];  

void push(char x)  
{  
    if (top == SIZE - 1)  
    {  
        printf("\nOverflow");  
    }  
    else  
    {  
        top = top + 1;  
        stack[top] = x;  
    }  
}  
void pop()  
{  
    if (top == -1)  
    {  
        printf("\nUnderflow");  
    }  
    else  
    {   
        top = top - 1;  
    }  
}  

int main () {
    FILE *file;
    char filename[FN_LENGTH];
    char line[MAX_LENGTH]; 
    int stack[STACK_LIMIT];


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
                push(line[i]);
                printf("parenthesis added to stack\n");
            } else if (line[i] == ')') {
                pop();
                printf("parenthesis removedfrom stack\n");
            }

            if (line[i] == '{') {  
                push(line[i]);
                printf("curly brace added to stack\n");
            } else if (line[i] == '}') {
                pop();
                printf("curly brace removed from stack\n");
            }

            if (line[i] == '[') {  
                push(line[i]);
                printf("bracket added to stack\n");
            } else if (line[i] == ']') {
                pop();
                printf("bracket removed from stack\n");
            }
        }
    }

    /*
    TODO:
    1. make a function that returns true if the stack is empty and false if it's not by the end
    of iterating through the file
    2. if the function returns true, print an appropiate msg and if it returns false, then print
    the line where the mismatch occured
    3. figure out how to ignore (), [], and {} in comments
    */ 
    fclose(file);
}