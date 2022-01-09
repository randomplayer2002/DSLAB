#include <stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node * NODE;

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

NODE insert_left(int item,NODE head)
{
    NODE temp,prev,cur;
    if(head->rlink==head)
    {
        printf("list empty");
        return head;

    }
    cur=head->rlink;
    while(cur!=head)
    {
       if(item==cur->info)
            break;
       cur=cur->rlink;
    }
    if(cur==head)
    {
        printf("key not found");
        return head;
    }
    prev=cur->llink;
    printf("enter item\n");
    scanf("%d",&item);
    temp=getnode();
    temp->info=item;
    prev->rlink=temp;
    temp->llink=prev;
    cur->llink=temp;
    temp->rlink=cur;
    return head;
}

NODE insert_front(int item,NODE head)
{
    NODE temp,cur;
    temp=getnode();
    temp->info=item;
    cur=head->rlink;
    head->rlink=temp;
    temp->llink=head;
    temp->rlink=cur;
    cur->llink=temp;
    return head;
}

NODE del_info(int item,NODE head)
{
    NODE prev,cur,next;
    if(head->rlink==head)
    {
        printf("list is empty");
        return head;
    }
    cur=head->rlink;
    while(cur!=head)
    {
        if(item==cur->info)
        break;
        cur=cur->llink;
    }
    if(cur==head)
    {
        printf("item not found\n");
        return head;
    }
    prev=cur->llink;
    next=cur->rlink;
    prev->rlink=next;
    next->llink=prev;
    free(cur);
    return head;
}

void display(NODE head)
{
    NODE temp;
    if(head->rlink==head)
    {
        printf("List is empty");
        return;
    }
    printf("contents of list\n ");
    temp=head->rlink;
    while(temp!=head)
    {
        printf("%d\n",temp->info);
        temp=temp->rlink;
    }
}

void main()
{
    NODE head;
    int ch,key,item;
    head=getnode();
    head->rlink=head;
    head->llink=head;

    for(;;)
    {
        printf("1:insert_front\n 2.display\n 3.insert_left\n 4.del_info\n 5.exit\n");
        printf("enter choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("enter item\n");
                    scanf("%d",&item);
                    insert_front(item,head);
                    break;

            case 2: display(head);
                    break;

            case 3: printf("enter key\n");
                    scanf("%d",&key);
                    head=insert_left(key,head);
                    break;

            case 4: printf("enter item\n");
                    scanf("%d",&item);
                    head=del_info(item,head);
                    break;

            default: exit(0);

        }
    }
}

