#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
        arrayStack_t stack;
        initStack(&stack); //USE THE STACK
        char input[100]; //Array of char that holds substantial user input
        int answer;
        int result; //variables that hold the answers/inputs of values once pushed/popped off the stacl
        int result1;

        while (1) // While loop continuosly repeats until user quits
        {
                printf("Enter a command: An integer, operator, or q\n"); 
                scanf("%s",input); // User input

                if(strcmp(input, "q") == 0 || strcmp(input, "quit") == 0)
                {
                        return 0; // Quit
                }
                else if(isInteger(input) != 0)
                {
                        push(&stack, atoi(input)); //If the string (char*) is an integer, the value is pushed onto the stack
                }
                else if(strcmp(input, "+") == 0 || strcmp(input, "-") == 0 || strcmp(input, "*") == 0 || strcmp(input, "/") == 0) // checks every operand
                {
                        if(stack.top == 0 || stack.top == 1)
                        {
                                printf("You tried to pop the stack twice when there isn't enough elements to pop! Error!\n");
                        }
                        else
                        {
                                pop(&stack, &result); // pops inputs off the stack and computes an answer once popped based on operand
                                pop(&stack, &result1);
                                if(strcmp(input, "+") == 0)
                                {
                                        answer = result1 + result;
                                }
                                else if((strcmp(input, "-")) == 0)
                                {
                                        answer = result1 - result;
                                }
                                else if((strcmp(input, "*")) == 0)
                                {
                                        answer = result1 * result;
                                }
                                else
                                {
                                        answer = result1 / result;
                                }
                                printf("%d\n", answer); // displays answer and pushes onto stack
                                push(&stack, answer);
                        }
                }
                else
                {
                        printf("Not a valid input! Error!\n"); // Only valid commands are quit, operators, or an integer
                }
        }
        free(stack.stackArray); //need to clean up our last malloc.
}
