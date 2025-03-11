#include<stdio.h>

void inputA(int arr[],int usize){
    printf("enter your %d array elements: \n",usize);
    for(int i=0;i<usize;i++){
        scanf("%d",&arr[i]);
    }
}
void display(int arr[],int usize){
    printf("your array is: \n");
    for(int i=0;i<usize;i++){
        printf("%d ",arr[i]);
    }
}
// void DeleteE(int arr[],int usize,int index,int Tsize){          ////delete at specific position of an elements

//     if(index>=Tsize||usize>=Tsize){
//         printf("insertion is not possible");
//     }
//     for(int i=index;i<usize-1;i++){
//         arr[i]=arr[i+1];
//     }
// }
int DeleteE(int arr[],int usize,int index,int Tsize){              ////delete at last index

    if(index>=Tsize||usize>=Tsize){
        printf("insertion is not possible");
        return 0;
    }
 return 1;
}

// int main(){
// int arr[10];
// int Tsize=10,used_size=4,index=0;
// inputA(arr,used_size);
//  display(arr,used_size);
// if (DeleteE(arr,used_size,index,Tsize)){
// used_size--;
// }
// printf("\n");
// display(arr,used_size);
//     return 0;
// }

int main(){
int arr[10];
int Tsize=10,used_size=4,index=0;
inputA(arr,used_size);
 display(arr,used_size);
if (DeleteE(arr,used_size,index,Tsize)){       ////for deleting last index;
used_size--;
}
printf("\n");
display(arr,used_size);
    return 0;
}