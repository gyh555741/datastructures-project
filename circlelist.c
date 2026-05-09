#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* createnode(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
node* insertattail(node* head,int data){
    node* newnode=createnode(data);
    if(head==NULL){
        return newnode;
    }
    node* cur=head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=newnode;
    return head;
}
node* insertathead(node* head,int data){
    node* newnode=createnode(data);
    newnode->next=head;
    return newnode;
}
node* insertatpos(node* head,int data,int pos){
    node* newnode=createnode(data);
    if(pos==1){
        insertathead(head,data);
        return head;
    }
    int i=1;
    node* cur=head;
    while(i<pos-1){
        if(head==NULL){
        }
        cur=cur->next;
        i++;
        }
    newnode->next=cur->next;
    cur->next=newnode;
    return head;
}
node* deletedata(node* head,int pos){
    if(head==NULL){
        return NULL;
    }
    int i=1;
    if(pos==1){
        head=head->next;
        return head;
    }
    node* cur=head;
    while(cur->next!=NULL&&i<pos-1){
        cur=cur->next;
        i++;
    }
    cur->next=cur->next->next;
    return head;
}
node* finddata(node* head,int data){
    if(head==NULL){
        printf("链表不存在");
        return 0;
    }
    node* cur=head;
    while(cur->next!=NULL&&cur->data!=data){
        cur=cur->next;
    }
    if(cur->data==data){
        printf("%d存在",data);
        return NULL;
    }else{
        printf("%d不存在",data);
        return NULL;
    }
}
void printlist(node* head){
    node* cur=head;
    while(cur->next!=head){
        printf("%d -> ",cur->data);
        cur=cur->next;
    }
    printf("NULL\n");
}
node* circlelist(node* head){
    if(head==NULL){
        return NULL;
    }
    node* cur=head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=head;
    return head;
}
int main()
{
    node* head=NULL;
    head=insertattail(head,1);
    head=insertattail(head,2);
    head=insertattail(head,3);
    head=insertattail(head,4);
    head=insertattail(head,5);
    head=insertathead(head,0);
    head=insertatpos(head,6,3);
    head=deletedata(head,3);
    head=circlelist(head);
    printlist(head);
    finddata(head,6);

    return 0;
}