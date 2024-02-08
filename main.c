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

    printf("\nThis program will read a file and check for balanced (), {}, and [].\nEnter the name of the file you want to check: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL ) {
        printf("Could not open file: %s", filename);
    }

    while (fgets(line, sizeof(line), file) != NULL) { 
        for (size_t i = 0; i < strlen(line); i++) { 
            /* 
            lines 55 and 56 just iterate through the file. i don't really fully know what they
            do... if i'm being honest i looked this up :D, but he showed it a different way in class
            i think, so it can definitely be changed. 
            */

            if (line[i] == '(' || line[i] == '{' || line[i] == '[') {  
                push(line[i]); // if it finds an open bracket it adds the char to the stack
            } else if (line[i] == ')' || line[i] == '}' || line[i] == ']') {
                if (top == -1) { // so if the stack is still empty and it found a closing bracket, then that's a problem
                    printf("\nSyntax error: No opening bracket at line %i.\n", line[i]); 
                    /*
                    using line[i] is wrong :( it's showing the place in the characters where the error is, but using i also 
                    doesn't work. not sure what to use to get the correct line number????*/
                } else if (!isPair(stack[top], line[i])){ //checks to see if it matches the last char that got added to the stack
                    printf("\nSyntax error: No closing bracket at line %i.\n", line[i]);
                    pop(); // remove char from the stack since it's already been checked
                } else {
                    pop(); // still remove the char from the stack since the right closing bracket was found
                }
            }

        }
    }

    if (top == -1) { // stack is empty if it's -1 and if the stack is empty then all of the brackets had a match
        printf("\nAll (), {}, and [] are balanced.\n");
    }

    fclose(file);

}
