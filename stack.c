#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

struct stack* createStack(int size){
      struct stack* newStack=(struct stack*)malloc(sizeof(struct stack));
      if(newStack==NULL){
        printf("Failed to allocate memory for the stack\n");
        exit(1);
      }
      newStack->size=size;
      newStack->top=-1;
      newStack->arr=(int*)malloc(size*sizeof(int));
      if(newStack->arr==NULL){
        printf("Failed to allocate memory for the array\n");
        free(newStack);
        exit(1);
      }
      return newStack;
}
int isFull(struct stack* myStack){
  if(myStack->top==myStack->size-1){
    printf("Stack overFlow\n");
    return 1;
  }
  else{
    return 0;
  }
}
int isEmpty(struct stack* myStack){
  if(myStack->top==-1){
    printf("Stack is underFlow\n");
    return 1;
  }
  else{
    return 0;
  }
}

void push(struct stack* myStack, int value){
  if(isFull(myStack)){
    printf("Stack is overflow! %d cannot push: ",value);
  }
  else{
    myStack->top++;
    myStack->arr[myStack->top]=value;
    printf("%d pushed to the Stack: \n",value);
  }
}
int pop(struct stack* myStack){
  if(isEmpty(myStack)){
    printf("Stack is underFlow! cannot poped from the stack\n");
    return -1;
  }
  else{
    int value=myStack->arr[myStack->top];
    myStack->top--;
    return value;
  }
}
int peek(struct stack* myStack){
  if(isEmpty(myStack)){
    printf("My stack is empty\n");
    return -99999;
  }
  else{
    return myStack->arr[myStack->top];
  }
}
void displayStack(struct stack* myStack){
  if(isEmpty(myStack)){
    printf("Stack is empty! Nothing to Display\n");
  }
  else{
    for(int i=myStack->top;i>=0;i--){
      printf("%d ",myStack->arr[i]);
    }
  }
}

int main(){
  int size,value,choice;
  printf("Enter the size of the stack: ");
  scanf("%d",&size);
if(size<=0){
  printf("Invalid stack size. Size must be a positive integer.\n");
  return 1;
}
  struct stack* myStack=createStack(size);
do{
  printf("1)Display the elements of the Stack\n");
  printf("2)is Stack is Full\n");
  printf("3)is Stack is empty\n");
  printf("4)Push the element in the Stack\n");
  printf("5)Pop the element from the Stack\n");
  printf("6)peek\n");
  printf("7)Exit from the program\n");
  printf("Enter the choice: ");
  scanf("%d",&choice);
  switch(choice){
    case 1:
    displayStack(myStack);
    printf("=====================================================\n");
    break;
    case 2:
    if(isFull(myStack)){
      printf("Stack is Full!\n");
    }
    else{
      printf("Stack is not Full\n");
    }
    printf("=====================================================\n");
    break;
    case 3:
    if(isEmpty(myStack)){
      printf("Stack is Empty\n");
    }
    else{
      printf("Stack is not empty\n");
    }
    printf("=====================================================\n");
    break;
    case 4:
    printf("Enter the value for push: ");
    scanf("%d",&value);
    push(myStack,value);
    printf("\nYour Stack (Top to Bottom) after pushing the element: ");
    displayStack(myStack);
    printf("\n======================================================\n");
    break;
    case 5:
    // int popValue=pop(myStack);
    printf("You poped the value %d from the stack: ",pop(myStack));
    printf("\nAfter poping the value the Stack (Top to Bottom) is: ");
    displayStack(myStack);
    printf("\n======================================================\n");
    break;
    case 6:
    printf("You seek the top of the value is: %d ",peek(myStack));
    printf("\n======================================\n");
    break;
    case 7:
    printf("Exit------------------------------------------");
    break;
    default:
    printf("Invalid choice! please enter the valid choice\n");
  }
}while(choice!=7);

 return 0;
}