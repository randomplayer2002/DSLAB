#include<stdio.h>
#include<stdlib.h>

struct node
{
   int info;
   struct node *link;
};
typedef struct node *NODE;

int search(int key, NODE first)
{
    NODE cur;
    if(first==NULL)
        return 0;

    cur=first;

    while(cur!=NULL)
    {
        if(key==cur->info)
            return 1;
        cur=cur->link;
    }
    return 0;
}

void display(NODE first)
{
    NODE cur;
    if(first==NULL)
   {
       printf("List is empty\n");
       return;
    }
   printf("The contents of singly linked list is\n");
   cur=first;
   while(cur!=NULL)
   {
     printf("%d\n",cur->info);
     cur=cur->link;
    }
  printf("\n");
}

NODE getnode()
{
       NODE x;
       x=(NODE) malloc(sizeof(struct node));
       if(x==NULL)
       {
         printf("Out of memory\n");
         exit(0);
        }
     return x;
}

NODE insert_rear(int item,NODE first)
{
   NODE temp;
   NODE cur;
   temp=getnode();
   temp->info=item;
   temp->link=NULL;

  if(first==NULL)
  return temp;

 cur=first;
 while(cur->link!=NULL)
{
   cur=cur->link;
  }
 cur->link=temp;
 return first;
}

 NODE remove_duplicate(NODE first)
{
    NODE a, b;
    int flag;
    if(first==NULL)
     return NULL;

    b=NULL;
    a=first;

    while(a!=NULL)
     {
         flag=search(a->info,b);
         if(flag==0)
            b=insert_rear(a->info,b);
         a=a->link;
     }
     return b;
}

NODE union_of_list(NODE first, NODE second)
{
    NODE a, third;
    int flag;
    a=first;
    third=NULL;
    while(a!=NULL)
    {
        third=insert_rear(a->info,third);
        a=a->link;
    }

    a=second;

    while(a!=NULL)
    {
        flag=search(a->info,third);
        if(flag==0)
            third=insert_rear(a->info,third);
        a=a->link;
    }
    return third;
}

NODE intersection_of_list(NODE first, NODE second)
{
     NODE a,b,third;
     int flag;
     a=first;
     b=second;
     third=NULL;

     while(a!=NULL)
     {
         flag=search(a->info,b);
         if(flag==1)
            third=insert_rear(a->info,third);
         a=a->link;
     }
     return third;
}

void main()
{
    NODE first,second,third;
    int choice,item,i,n;
    for(;;)
    {
        printf("1:Create first list\n");
        printf("2:Create second list\n");
        printf("3:Remove duplicates of list 1\n");
        printf("4:Remove duplicates of list 2\n");
        printf("5:Union of two lists\n");
        printf("6: Intersection of two lists\n");
        printf("7:Exit\n");

        printf("Enter the choice\n");
        scanf("%d",& choice);
        switch(choice)
        {
             case 1:
                      printf("enter the number of nodes in the LIST 1\n");
                      scanf("%d",&n);
                      first=NULL;
                      for(i=1;i<=n;i++)
                        {
                              printf("enter the item\n");
                              scanf("%d",&item);
                              first=insert_rear(item,first);
                        }
                            break;

            case 2:
                     printf("Enter the number of nodes in second list\n");
                     scanf("%d",&n);
                     second=NULL;
                    for(i=1;i<=n;i++)
                    {
                      printf("enter the item\n");
                      scanf("%d",&item);
                      second=insert_rear(item,second);
                    }
                        break;

            case 3:
                    printf("The first list before removing duplicate  is:\n");
                    display(first);
                    first=remove_duplicate(first);
                    printf("The first list after removing duplicates\n");
                    display(first);
                        break;

           case 4:
                   printf("The second list before removing duplicate  is:\n");
                   display(second);
                   second=remove_duplicate(second);
                   printf("The first list after removing duplicates\n");
                   display(second);
                        break;

           case 5:
                   printf("The first list is \n");
                   display(first);
                   printf("The second list is \n");
                   display(second);
                   third=union_of_list(first,second);
                   printf("The union of two lists\n");
                   display(third);
                        break;

           case 6:
                   printf("The first list \n");
                   display(first);
                   printf("The second list\n");
                   display(second);
                   third=intersection_of_list(first,second);
                   printf("The intersection of two lists \n");
                   display(third);
                        break;

           default:exit(0);

        }
    }
}

