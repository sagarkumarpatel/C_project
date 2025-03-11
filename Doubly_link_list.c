#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *creatNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("memory is not allocated: ");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("head is empty\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *insertAtFirst(struct node *head, int data)
{
    struct node *newNode = creatNode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}

struct node *insertAtLast(struct node *head, int data)
{
    struct node *newNode = creatNode(data);
    if (head == NULL)
    {
        return insertAtFirst(head, data);
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
struct node *insertAtIndex(struct node *head, int data, int index)
{
    struct node *newNode = creatNode(data);
    if (index < 0)
    {
        printf("Invalid index\n");
        return head;
    }
    if (index == 0)
    {
        return insertAtFirst(head, data); 
    }
    struct node *temp = head;
    int i = 0;
    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct node *DeleteAtFirst(struct node *head)
{
    if (head == NULL)
    {
        printf("List is already empty\n");
        return NULL;
    }
    struct node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}
struct node *DeleteAtLast(struct node *head)
{
    if (head == NULL)
    {
        printf("List is already empty\n");
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}

struct node* DeleteAtIndex(struct node *head,int index){
    if(head==NULL){
        printf("List is already empty\n");
        return NULL;
    }
    if(index<0){
        printf("Invalid index!\n");
        return head;
    }
    if(index==0){
        return DeleteAtFirst(head);
    }
    struct node* temp1=head;
    struct node* temp2=head;
    int i=0;
    while (i!=index)
    {
          temp2=temp1;
        temp1=temp1->next;
        i++;
    }
     temp2->next=temp1->next;
     temp1->next->prev=temp2;
    free(temp1);
    return head;
    
}

int main()
{
    struct node *head = NULL;
    int data, choice, index;
    do
    {
        printf("1)Display the node List\n");
        printf("2)Insert at First\n");
        printf("3)Insert at end\n");
        printf("4)Insert at index\n");
        printf("5)Delete at First\n");
        printf("6)Delete at Last\n");
        printf("7)Delete at index\n");
        printf("8)Exit from the programme\n");
        printf("enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Your List: \n");
            display(head);
            break;
        case 2:
            printf("enter your Data which you want to insert at first: \n");
            scanf("%d", &data);
            head = insertAtFirst(head, data);
            printf("your list After insertion at first\n");
            display(head);
            printf("-------------------------------------------------\n");
            break;
        case 3:
            printf("enter your Data which you want to insert at Last: \n");
            scanf("%d", &data);
            head = insertAtLast(head, data);
            printf("your list After insertion at Last\n");
            display(head);
            printf("-------------------------------------------------\n");
            break;
        case 4:
            printf("enter your Data which you want to insert at Last: \n");
            scanf("%d", &data);
            printf("enter your index to insert the data: \n");
            scanf("%d", &index);
            head = insertAtIndex(head, data, index);
            printf("your list After insertion at index\n");
            display(head);
            printf("-------------------------------------------------\n");
            break;
        case 5:
            head = DeleteAtFirst(head);
            printf("your list after first node deletion\n");
            display(head);
            break;

        case 6:
            head = DeleteAtLast(head);
            printf("your list after Last node deletion\n");
            display(head);
            break;
            case 7:
            printf("Enter your deleting index: \n");
            scanf("%d",&index);
            head=DeleteAtIndex(head,index);
            printf("your list after index node deletion\n");
            display(head);
            break;
            case 8:
            printf("----------------Exit-------------\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}