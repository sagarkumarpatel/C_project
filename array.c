#include<stdio.h>
#include<stdlib.h>

void input(int ptr[],int size){
    printf("enter your array element: \n");
for(int i=0;i<size;i++){
    scanf("%d",&ptr[i]);
}
};

void display(int ptr[],int size){
    printf("your array is: ");
    for(int i=0;i<size;i++){
        printf("%d ",ptr[i]);
    }
};

int main(){
    int size;
    printf("enter the size: \n");
    scanf("%d",&size);
  int *ptr = NULL;
  ptr=(int *)malloc(size*sizeof(int));
  input(ptr,size);
  display(ptr,size);

return 0;
}