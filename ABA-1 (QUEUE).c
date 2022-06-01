#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};

struct node *front;
struct node *rear;

typedef struct node *NODE;

void main ()
{
    int choice;
    while(choice != 4)
    {
        printf("\n*************************Main Menu*****************************\n");
        printf("\n=================================================================\n");
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",& choice);
        switch(choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\nEnter valid choice: \n");
        }
    }
}

void insert()
{
    NODE ptr;
    int item;

    ptr = (NODE) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        printf("\nEnter value: \n");
        scanf("%d",&item);
        ptr -> info = item;
        if(front == NULL)
        {
            front = ptr;
            rear = ptr;
            front -> link = NULL;
            rear -> link = NULL;
        }
        else
        {
            rear -> link = ptr;
            rear = ptr;
            rear-> link = NULL;
        }
    }
}
void delete ()
{
   NODE ptr;
    if(front == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        ptr = front;
        front = front -> link;
        free(ptr);
    }
}
void display()
{
    NODE ptr;
    ptr = front;
    if(front == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {   printf("\nThe values of the queue are\n");
        while(ptr != NULL)
        {
            printf("\n%d\n",ptr -> info);
            ptr = ptr -> link;
        }
    }
}
