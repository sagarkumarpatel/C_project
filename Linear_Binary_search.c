#include<stdio.h>

// void LinearSearch(int arr[],int size,int element){         ////code for linear search
//     int found=0;
// for(int i=0;i<size;i++){
//     if(arr[i]==element){
//         printf("Element found at index: %d\n",i);
//         found=1;
//     }
// }
// if(found==0){
//     printf("Not found");
// }
// }

void BinarySearch(int arr[],int size,int element){             //code for binary search
    int found=0;
 int low=0;
 int high=size-1;
 int mid;
 while(low<=high){
 mid=(low+high)/2;
 if(arr[mid]==element){
    printf("The index of the element is: %d\n",mid);
    found=1;
    break;
 }
 else if(arr[mid]<element){
    low=mid+1;
 }
 else{
    high=mid-1;
 }
 }
 if(found==0){
    printf("Element not found");
 }
}

int main(){
  int arr[]={1,2,3,4,5,6,7,9,10};
  int size=sizeof(arr)/sizeof(int);
  int element=5;
//   LinearSearch(arr,size,element);
  BinarySearch(arr,size,element);


    return 0;
}