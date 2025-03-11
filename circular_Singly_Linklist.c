#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void display(struct node *tail)
{
    if (tail == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else
    {
        struct node *temp = tail->next; // Starting from the first node, tail->next means head
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
    }
}

struct node *insertAtFirst(struct node *tail, int data)
{
    struct node *newNode = createNode(data);
    if (tail == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    return tail;
}
struct node *InsertAtLast(struct node *tail, int data)
{
    struct node *newNode = createNode(data);
    if (tail == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}
struct node *InsertAtindex(struct node *tail, int data, int index)
{
    struct node *newNode = createNode(data);
    if (index < 0)
    {
        printf("Invalid! Index\n");
        return tail;
    }
    if (index == 0)
    {
        return insertAtFirst(tail, data);
    }
    if (tail == NULL)
    {
        printf("List is empty. Inserting at index 0.\n");
        return insertAtFirst(tail, data);
    }
    struct node *temp = tail->next; // tail->next means head node
    int i = 0;
    while (i != index - 1)
    {
        temp = temp->next;
        i++;
        if (temp == tail->next)
        {
            printf("Index is out of bound!, inserting at the end\n");
            return InsertAtLast(tail, data);
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    if (tail == temp)
    {
        tail = newNode;
    }
    return tail;
}

int main()
{
    struct node *tail = NULL;
    int data, choice, index;
    do
    {
        printf("1) Display the data of List\n");
        printf("2) InsertAtFirst \n");
        printf("3) InserAtLast\n");
        printf("4) InsertAtIndex\n");
        printf("5) Exiting from the program\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(tail);
            break;
        case 2:
            printf("Enter your data for inserting at first: \n");
            scanf("%d", &data);
            printf("your data after inserting at first: ");
            tail = insertAtFirst(tail, data);
            display(tail);
            printf("\n-----------------------------------------------\n");
            break;
        case 3:
            printf("enter your data for inserting at Last: \n");
            scanf("%d", &data);
            tail = InsertAtLast(tail, data);
            printf("Your data after inserting at Last: ");
            display(tail);
            printf("\n-----------------------------------------------\n");
            break;
        case 4:
            printf("enter your data for inserting at index: \n");
            scanf("%d", &data);
            printf("enter your index for inserting: \n");
            scanf("%d", &index);
            tail = InsertAtindex(tail, data, index);
            printf("Your data after inserting at index: ");
            display(tail);
            printf("\n-----------------------------------------------\n");
            break;
        case 5:
            printf("Exited from the program\n");
            break;
        default:
            printf("Invalid! Choice\n");
        }
    } while (choice != 5);

    return 0;
}