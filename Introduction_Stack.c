// Important note:-  This separation allows for dynamic sizing of the array and better memory management.
/* Why Not Allocate Everything Inside the Stack Structure?
You might wonder why we don't just allocate everything inside the stack structure. The reason is flexibility:

The size of the array (arr) is determined at runtime (e.g., s->size = 8).

The stack structure itself has a fixed size, but the array can have a variable size.

By allocating the array separately, we can dynamically adjust its size (e.g., resize the stack if needed). */

#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;     //a pointer to an integer array, which will hold the actual stack elements  OR   // Pointer to the array that holds the stack elements
};


int main(){
 struct stack *s=(struct stack*)malloc(sizeof(struct stack));  // Blueprint: You draw a plan for a house (define the stack structure).
 /*Build the House: You construct the house based on the plan (malloc for the structure).
 Furnish the House: You add furniture and utilities to the house (initialize size, top, and arr).
 Address of the House: You write down the address of the house (s is the pointer to the structure).*/

 s->size=8;
 /*The array (arr) is like a container that can hold up to 5 elements.

The stack is the way we use the container to add and remove elements in a specific order (LIFO).

The size of the stack is limited by the size of the array.
*/

 s->top=-1;
 s->arr=(int*)malloc(s->size * sizeof(int));  //After the second allocation, the arr pointer inside the stack structure is updated to point to the newly allocated array. So now:

 //The stack structure (s) contains a pointer (arr) that points to the external memory block (the array).

    return 0;
}


/*Introduction of stack 
1. What is a Stack?
A stack is a data structure that follows the Last-In-First-Out (LIFO) principle.

Think of it like a stack of plates: the last plate you add is the first one you remove.

2. Structure Definition
The stack structure is a blueprint for the stack:

int size: Maximum number of elements the stack can hold.

int top: Index of the top element in the stack (starts at -1 for an empty stack).

int *arr: Pointer to an array that stores the stack elements.

3. Memory Allocation
First Allocation: malloc(sizeof(struct stack)) allocates memory for the stack structure (the blueprint).

Second Allocation: malloc(size * sizeof(int)) allocates memory for the array (arr) that holds the stack elements.

4. Why Two Allocations?
The stack structure and the array are separate:

The structure holds metadata (size, top, and a pointer to the array).

The array holds the actual stack elements.

5. Size of the Stack
When we say the size of the stack is 5, it means:

The array (arr) can hold up to 5 elements.

The stack can grow and shrink within this limit.

6. Operations
Push: Add an element to the top of the stack.

Pop: Remove the top element from the stack.

isEmpty: Check if the stack is empty.

isFull: Check if the stack is full.

7. Key Points
Only one stack is created.

The array (arr) is the physical storage for the stack.

The stack is the logical way of using the array to follow LIFO.

Example in One Line
We create one stack with a size of 5 (array can hold 5 elements), and perform push/pop operations on it.*/


/*When to Use return 1 vs. return 0:
Use return 0 when the program completes successfully.

Use return 1 (or any non-zero value) when the program encounters an error and needs to exit early.*/