#include <stdio.h>
#include <stdlib.h>


struct node
{
int info;
struct node *link;
};
struct node *head;
typedef struct node *NODE;

void main ()
{
    int choice=0;
    printf("\n*********Stack operations using linked list*********\n");
    printf("\n----------------------------------------------\n");
    while(choice != 4)
    {
        printf("\n\nChose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.display\n4.Exit");
        printf("\n Enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("Exiting....");
                break;
            }
            default:
            {
                printf("Please Enter valid choice ");
            }
    }
}
}
void push ()
{
    int info;
    NODE ptr;
    ptr = (NODE)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("not able to push the element");
    }
    else
    {
        printf("Enter the value");
        scanf("%d",&info);
        if(head==NULL)
        {
            ptr->info = info;
            ptr -> link = NULL;
            head=ptr;
        }
        else
        {
            ptr->info = info;
            ptr->link = head;
            head=ptr;

        }
        printf("Item pushed");

    }
}

void pop()
{
    int item;
    NODE ptr;
    if (head == NULL)
    {
        printf("Underflow");
    }
    else
    {
        item = head->info;
        ptr = head;
        head = head->link;
        free(ptr);
        printf("Item popped");

    }
}
void display()
{
    int i;
    NODE ptr;
    ptr=head;
    if(ptr == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Printing Stack elements \n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->info);
            ptr = ptr->link;
        }
    }
}
