#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node Transversing(struct node *head){
  struct node *ptr2=head;
  printf("The data of each node are: ");
  while(ptr2!=NULL){
    printf("%d ",ptr2->data);
    ptr2=ptr2->next;
  }
  printf("\n------------------------------------------------------");
}

struct node* insertionAtFirst(struct node *head,int data){
     struct node *newNode;
     newNode=(struct node*)malloc(sizeof(struct node));
     newNode->data=data;
    newNode->next=head;
    return newNode;
     
}

int main(){

struct node *head;
head=(struct  node*)malloc(sizeof(struct node));
head->data=32;
head->next=NULL;

struct node *first;
first=(struct node*)malloc(sizeof(struct node));
first->data=34;
first->next=NULL;
head->next=first;

struct node *second;
second=(struct node*)malloc(sizeof(struct node));
second->data=39;
second->next=NULL;
 first->next=second;


struct node *third;
third=(struct node*)malloc(sizeof(struct node));
third->data=46;
 third->next=NULL;
second->next=third;
printf("The Data of the node before insertion \n");
Transversing(head);

int data=50;
head=insertionAtFirst(head,data);
printf("\nThe Data of the node after insertion \n");
Transversing(head);


    return 0;
}