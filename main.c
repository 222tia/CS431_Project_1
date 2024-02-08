#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define FN_LENGTH 100
#define MAX_LENGTH 1000
#define SIZE 4  

int top = -1, stack[SIZE]; 
char filename[FN_LENGTH];
char line[MAX_LENGTH]; 
FILE *file;

void push(char item) {  
    if (top == SIZE - 1)  {  
        printf("\nOverflow");  
    }  
    else {  
        top = top + 1;  
        stack[top] = item;  
    }  
}  

char pop() {  
    if (top == -1) {  
        printf("\nUnderflow");  
    }  
    else {  
        top = top - 1;
    }  
} 

int isPair(char a, char b) {
    if (a == '(' && b == ')') {
        return 1;
    } else if (a == '{' && b == '}') {
        return 1;
    } else if (a == '[' && b == ']') {
        return 1;
    } else {
        return 0;
    }
}

int main () {

    printf("\nThis program will read a file and check for balanced parentheses.\nEnter the name of the file you want to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL ) {
        printf("Could not open file: %s", filename);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        for (size_t i = 0; i < strlen(line); i++) { 

            if (line[i] == '(' || line[i] == '{' || line[i] == '[') {  
                push(line[i]); 
            } else if (line[i] == ')' || line[i] == '}' || line[i] == ']') {
                if (top == -1) { 
                    printf("\nSyntax errpr: No opening bracket at line x\n");
                } else if (!isPair(stack[top], line[i])){
                    printf("\nSyntax error: No closing bracket at line x\n");
                    pop();
                } else {
                    pop();
                }
            }
        }
    }

    if (top == -1) {
        printf("\nAll (), {}, and [] are balanced.\n");
    }

    fclose(file);

}
