#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *ptr;
};

int main(){
struct node *head;
head=(struct node*)malloc(sizeof(struct node));
head->data=32;
head->ptr=NULL;

struct node *first;
first=(struct node*)malloc(sizeof(struct node));
first->data=33;
first->ptr=NULL;
head->ptr=first;

struct node *second;
second=(struct node*) malloc(sizeof(struct node));
second->data=34;
second->ptr=NULL;
first->ptr=second;

struct node *ptr2=NULL;
ptr2=head;
int count =0;
printf("The data of each node are: ");
while(ptr2!=NULL){
    count++;
   printf("%d ",ptr2->data);
   ptr2=ptr2->ptr;
}
printf("\nThe number of the node count is: %d",count);
free(head);
free(first);
free(second);
    return 0;
}