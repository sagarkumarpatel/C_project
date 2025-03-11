#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user
{
  int id;
  char name[50];
  char email[50];
  int Total_size;
  int uSized;
  int *ptr;
};

void create_A(struct user *p1, int tsize, int usize, int ID, char *Name, char *Email)
{
  p1->Total_size = tsize;
  p1->uSized = usize;
  p1->id = ID;
  p1->ptr = (int *)malloc(tsize * sizeof(int));
  if (p1->ptr == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  strcpy(p1->name, Name);
  strcpy(p1->email, Email);
  printf("Enter the %d element of an array \n", p1->uSized);
  for (int i = 0; i < usize; i++)
  {
    scanf("%d", &(p1->ptr[i]));
  }
}

void display(struct user *p1)
{
  printf("enter your Id: \n");
  scanf("%d", &p1->id);
  printf("enter your name: \n");
  scanf("%s", p1->name);
  printf("enter your email: \n");
  scanf("%s", p1->email);
  printf("The id of the user is: %d\n", p1->id);
  printf("The name of the user is: %s\n", p1->name);
  printf("The email of the user is: %s\n", p1->email);
  printf("The elements of the array are: ");
  for (int i = 0; i < p1->uSized; i++)
  {
    printf("%d ", p1->ptr[i]);
  }
}

void insertAtFirst(struct user *p1, int element)
{
  for (int i = p1->uSized - 1; i >= 0; i--)
  {
    p1->ptr[i + 1] = p1->ptr[i];
  }
  p1->ptr[0] = element;
  p1->uSized++;
}

void insertAtLast(struct user *p1, int element)
{
  if (p1->uSized >= p1->Total_size)
  {
    printf("Array is full,can't be inserted\n");
    return;
  }
  p1->ptr[p1->uSized] = element;
  p1->uSized++;
}

void insertAtSpecific(struct user *p1, int index, int element)
{
  if (index >= p1->Total_size)
  {
    printf("inserting is not posibal");
    return;
  }
  for (int i = p1->uSized - 1; i >= index; i--)
  {
    p1->ptr[i + 1] = p1->ptr[i];
  }
  p1->ptr[index] = element;
  p1->uSized++;
}

void deleteAtFirst(struct user *p1)
{
  for (int i = 0; i < p1->uSized - 1; i++)
  {
    p1->ptr[i] = p1->ptr[i + 1];
  }
  p1->uSized--;
  printf("First index deleted sucessfully.\n");
}

void deleteAtLast(struct user *p1)
{
  if (p1->uSized == 0)
  {
    printf("Array is empty");
  }
  p1->uSized--;
  printf("Last index deleted sucessfully.\n");
}

void deleteAtSpecific(struct user *p1, int index)
{
  for (int i = index; i < p1->uSized - 1; i++)
  {
    p1->ptr[i] = p1->ptr[i + 1];
  }
  p1->uSized--;
}

int main()
{
  struct user p1;
  int id;
  char name, email;
  int Total_size = 10;
  int uSized = 5;
  int index, element;
  int choice;
  create_A(&p1, Total_size, uSized, id, &name, &email);
  do
  {
    printf("\n1)Display user info: \n");
    printf("2) insertAtFirst\n");
    printf("3) insertAtLast\n");
    printf("4)insertAtSpecific\n");
    printf("5) deleteAtFirst\n");
    printf("6) deleteAtLast\n");
    printf("7)  deleteAtSpecific\n");
    printf("8)Exit program");
    printf("enter your choice: \n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      display(&p1);
      printf("\n--------------------------------------------");
      break;
    case 2:
      printf("Enter the element to insert at first: ");
      scanf("%d", &element);
      insertAtFirst(&p1, element);
      break;

    case 3:
      printf("Enter the element to insert at last: \n");
      scanf("%d", &element);
      insertAtLast(&p1, element);
      break;

    case 4:
      printf("Enter the index of inserting elements:\n");
      scanf("%d", &index);
      printf("Enter the inserting element :\n");
      scanf("%d", &element);
      insertAtSpecific(&p1, index, element);
      break;
    case 5:
      deleteAtFirst(&p1);
      break;
    case 6:
      deleteAtLast(&p1);
      break;
    case 7:
      printf("Enter your deleting index: \n");
      scanf("%d", &index);
      deleteAtSpecific(&p1, index);
      break;
    case 8:
      printf("Exiting....\n");
      break;
    default:
      printf("Invalid choice! please try again.\n");
    }
  } while (choice != 8);
  free(p1.ptr);

  return 0;
}