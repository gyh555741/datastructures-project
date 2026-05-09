#include <stdio.h>
#include <stdlib.h>
#define ElemType int
typedef struct node{
    ElemType data;
    struct node* next;
}node;
node* createdata(int data){
    node* p = (node*)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    return p;
}
node* insert(node* head,int data){
    node* p = createdata(data);
    if(head == NULL){
        head = p;
    }else{
        node* q = head;
        while(q->next!= NULL){
            q = q->next;
        }
        q->next = p;
    }
    return head;
}
//找到链表中的最大值
node* findmax(node* head){
    if(head==NULL){
        return NULL;
    }
    node* left=head;
    node* right=head;
    while(right->next!=NULL){
        if(right->data>left->data){
            left=right;
        }
        right=right->next;
    }
    return left;
}
int main()
{
    node* head=NULL;
    head=insert(head,3);
    head=insert(head,5);
    head=insert(head,1);
    head=insert(head,4);
    head=insert(head,2);
    node* p=findmax(head);
    printf("%d\n",p->data);

    return 0;
}