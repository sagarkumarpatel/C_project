#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int Total_size;
    int use_size;
    int *ptr;       //base index
};

void creatArray(struct myArray *mark, int size,int usize){
mark->Total_size=size;
mark->use_size=usize;
mark->ptr=(int*)malloc(size*sizeof(int));   //After the assignment, mark->ptr will point to the first element of the dynamically allocated array.

}

void setArray(struct myArray *mark){
    printf("enter the %d elements of an array\n",mark->use_size);
    for(int i=0;i<mark->use_size;i++){
        scanf("%d",&(mark->ptr[i]));
    }
}


void showArray(struct myArray *mark){
    printf("The elements of an array are: ");
    for(int i=0;i<mark->use_size;i++){
        printf("%d ",mark->ptr[i]);
    }
}

int main(){
   struct myArray marks;
      creatArray(&marks,10,4);
      setArray(&marks);
      showArray(&marks);

    return 0;
}