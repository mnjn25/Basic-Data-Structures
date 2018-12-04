#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int info;
    struct node *link;
}node;
node *root = NULL;
node* createnode(int data){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->info=data;
    temp->link=NULL;
    return temp;
}

void print(){
    node *temp;
    temp=root;
    while(temp!=NULL){
        printf("%d ",temp->info);
        temp=temp->link;
    }
    printf("\n");
}

void begin(int data){
    node *temp;
    if(root==NULL){
            root=createnode(data);
     }
    else{
        temp=createnode(data);
        temp->link=root;
        root=temp;
    }
}

void middle(int data,int pos){
    int i;
    if(root==NULL){
        root=createnode(data);
    }
    else{
        node *temp;
        temp = createnode(data);
        node *temp1;
        temp1=root;
        for(i=1;i<=pos-1;i++){
            temp1=temp1->link;
        }
        temp->link=temp1->link;
        temp1->link=temp;
    }
}

void last(int data){
    if(root==NULL){
                root=(node*)malloc(sizeof(node));
                root->info=data;
                root->link=NULL;
        }
    node *temp;
    temp=root;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    node *temp1;
    temp1 = (node*)malloc(sizeof(node));
    temp1->info=data;
    temp1->link=NULL;
    temp->link=temp1;
}

void del(node **head_ref, int position)
{
   if (root == NULL)
      return;

   node *temp = root;

    if (position == 0)
    {
        root = temp->link;
        free(temp);
        return;
    }
    int i;
    for (i=0; temp!=NULL && i<position-1; i++)
         temp = temp->link;

    if (temp == NULL || temp->link == NULL)
         return;

    node *link = temp->link;
    link=link->link;

    free(temp->link);

    temp->link = link;
}
int main(){
    int i,n,val,x,pos;
while(1){
    printf("enter 1 for insert at beginning\n2 for insert at given pos\n3 for insert at end\n4 to view list\n5 to delete node\n6 to end program\n");
    scanf("%d",&x);
    switch(x){
        case 1: printf("enter the value\n");
                scanf("%d",&val);
                begin(val);
                print();
                break;
        case 2: printf("enter the value and position\n");
                scanf("%d %d",&val,&pos);
                middle(val,pos);
                print();
                break;
        case 3: printf("enter the value\n");
                scanf("%d",&val);
                last(val);
                print();
                break;
        case 4: print();
                break;
        case 5: printf("enter the position\n");
                scanf("%d",&pos);
                del(root,pos);
                print();
                break;
        case 6: return 0;
                break;
        default: printf("enter valid option\n");
                 break;
    }
}
    return 0;
}

