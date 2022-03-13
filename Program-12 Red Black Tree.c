#include<stdio.h>
#include<stdlib.h>

struct rbtNode{
    int key;
    char color;
    struct rbtNode *left, *right,*parent;
};

struct rbtNode* root = NULL;

void leftRotate(struct rbtNode *x){
    struct rbtNode *y;
    y = x->right;
    x->right = y->left;
    
    if( y->left != NULL)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if( x->parent == NULL){
        root = y;
    }
    else if((x->parent->left!=NULL) && (x->key == x->parent->left->key))
    {
        x->parent->left = y;
    }
    else x->parent->right = y;
    y->left = x; x->parent = y; return;
}

void rightRotate(struct rbtNode *y){
    struct rbtNode *x;
    x = y->left;
    y->left = x->right;
    if ( x->right != NULL)
    {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if( y->parent == NULL)
    {
        root = x;
    }
    else if((y->parent->left!=NULL)&& (y->key == y->parent->left->key))
    {
        y->parent->left = x;
    }
    else
    y->parent->right = x;
    x->right = y; y->parent = x;
    return;
}

void colorinsert(struct rbtNode *z){
    struct rbtNode *y=NULL;
    while ((z->parent != NULL) && (z->parent->color == 'r'))
    {
        if ((z->parent->parent->left != NULL) && (z->parent->key == z->parent->parent->left->key))
        {
            if(z->parent->parent->right!=NULL)
                y = z->parent->parent->right;
            if ((y!=NULL) && (y->color == 'r'))
            {
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                if(z->parent->parent!=NULL)
                    z = z->parent->parent;
            }
            else
            {
                if ((z->parent->right != NULL) && (z->key == z->parent->right->key))
                {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                rightRotate(z->parent->parent);
            }
        }
        else
        {
            if(z->parent->parent->left!=NULL)
                y = z->parent->parent->left;
            if ((y!=NULL) && (y->color == 'r'))
            {
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                if(z->parent->parent!=NULL)
                    z = z->parent->parent;
            }
            else
            {
                if ((z->parent->left != NULL) && (z->key == z->parent->left->key))
                {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = 'b';
}

void inorderTree(struct rbtNode* root){
    struct rbtNode* temp = root;
    if (temp != NULL)
    {
        inorderTree(temp->left);
        printf(" %d-%c ",temp->key,temp->color);
        inorderTree(temp->right);
    }
    return;
}

void traversal(struct rbtNode* root){
    if (root != NULL)
    {
        printf("root is %d- %c",root->key,root->color);
        printf("\nInorder tree traversal\n");
        inorderTree(root);
    }
    return;
}

void insert(int val){
    struct rbtNode *x, *y;
    struct rbtNode *z = (struct rbtNode*)malloc(sizeof(struct rbtNode));
    z->key = val;
    z->left = NULL;
    z->right = NULL;
    z->color = 'r';
    x=root;
    if ( root == NULL )
    {
        root = z;
        root->color = 'b';
        return;
    }
    while ( x != NULL)
    {
        y = x;
        if ( z->key < x->key)
        {
            x = x->left;
        }
        else
            x = x->right;
    }
    z->parent = y;
    if ( y == NULL)
    {
        root = z;
    }
    else if( z->key < y->key )
    {
        y->left = z;
    }
    else{
        y->right = z;
    }

    colorinsert(z);
    return;
}

void printTree(struct rbtNode *root, int space)
{
    if (root == NULL)
    {
        return;
    }

    else
    {
        space += 8;
    printTree(root->right, space);
    printf("\n");
    for (int i = 8; i < space; i++)
        printf(" ");
    printf("%d(%c)", root->key,root->color);
    printTree(root->left, space);
    }
}

void print(struct rbtNode *root)
{
if(root==NULL)
{
    printf("No Data");
}
else
{
    printTree(root, 0);
}
}

int main(){
    int choice,val,data,var,fl=0;
    while(1)
    {
       // system("cls");
        print(root);
        printf("\nRed Black Tree Menu - \nEnter your choice :\n1:Insert\n 2:Traversal\n 3:Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the integer you want to add : ");
                scanf("%d",&val);
                insert(val);
            break;
             case 2:
                traversal(root);
                break;
            case 4:
                fl=1;
            break;
            default:
                printf("\nInvalid Choice\n");
        }
        if(fl==1){
            break;}
        }
    return 0;
}
