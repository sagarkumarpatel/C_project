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
// int insertE(int arr[],int usize,int index,int Tsize,int element){            //insertion at specific position 

//     if(index>=Tsize){
//         printf("insertion is not possible");
//     }
//     for(int i=usize-1;i>=index;i--){
//         arr[i+1]=arr[i];
//     }
//     arr[index]=element;
//     return 1;
// }


// int insertE(int arr[],int usize,int index,int Tsize,int element){            //insertion at last position 

//     if(index>usize||usize>=Tsize||index<0){
//         printf("insertion is not possible");
//         return 0;
//     }
//    arr[usize]=element;
   
//     return 1;
// }

void updateA(int arr[],int index,int value){
    arr[index]=value;
}

int main(){
int arr[10];
int Tsize=10,used_size=4,index=1,element=7;
inputA(arr,used_size);
 display(arr,used_size);
// insertE(arr,used_size,index,Tsize,element);
// used_size++;
// printf("\n");
// display(arr,used_size);
updateA(arr,index,element);
display(arr,used_size);
    return 0;
}