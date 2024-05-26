#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INITIAL_SIZE 5

//creates a struct that represents a stack
//contains: an arraysize(int), a pointer to a stack array, and a top(int)
typedef struct arrayStack

{
        int arraySize;
        int* stackArray;
        int top;
} arrayStack_t;

//creates the stack
//holds a stack pointer as an argument that points to the parameters in the stack struct
void initStack(arrayStack_t* stack)
{
        stack->arraySize=INITIAL_SIZE;
        stack->stackArray=(int*)malloc(sizeof(int)*INITIAL_SIZE);
        stack->top=0;
}

//pushes a value onto the stack (input)
//side effects: allocates memory using malloc and frees it after copying contents of the old array
void push(arrayStack_t* stack, int value)
{
        if (stack->top >= stack->arraySize)
        {
                int* oldArray=stack->stackArray;
                stack->stackArray=(int*)malloc(sizeof(int)*stack->arraySize*2);
                for (int i=0;i<stack->arraySize;i++)
                {
                        stack->stackArray[i]=oldArray[i];
                }
        stack->arraySize=stack->arraySize * 2;
        free(oldArray);
        }
//once we get here, we know the stack is big enough.
stack->stackArray[stack->top++]=value;
}

//pop: remove an item from the stack
//Parameters: stack: a pointer to a stack structure
//result: a pointer to an integer to hold the value from the top of the stack.
//Returns: non-zero on success, 0 on failure
int pop(arrayStack_t* stack,int* result)
{
        if (stack->top==0) //stack is empty
        {
                return 0;
        }
        stack->top--; //decrement it first and now it points to the value we want
        *result=stack->stackArray[stack->top];
        return 1;
}

//checks whether or not a char pointer (string) is meant to be an integer
//returns one on true unless the integer happens to be zero
int isInteger(char* valString)
{
   if (!strcmp(valString,"0")) return 1;
   if (atoi(valString)==0) return 0;
   return 1;
}

