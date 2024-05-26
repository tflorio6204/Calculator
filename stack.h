#ifndef _STACK_H_
#define _STACK_H

typedef struct arrayStack //creates a struct that holds arguments that make up a stack
{
        int arraySize;
        int* stackArray;
        int top;
} arrayStack_t;

void initStack(arrayStack_t*stack); //function declaration that creates stack

void push(arrayStack_t* stack, int value); //function declaration that pushes an integer (input) onto the stack

int pop(arrayStack_t* stack,int* result);

int isInteger(char* valString); // function declaration checks whether a string (char*) contains an integer or not

#endif
