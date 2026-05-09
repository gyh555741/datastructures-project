#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* pre;
} node;

node* creatnode(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->pre = NULL;
    return newnode;
}

node* insertattail(node* head, int data) {
    node* newnode = creatnode(data);
    if (head == NULL) return newnode;
    node* cur = head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = newnode;
    newnode->pre = cur;
    return head;
}

node* insertatmiddle(node* head, int data, int pos) {
    node* newnode = creatnode(data);
    if (head == NULL) return newnode;
    node* cur = head;
    node* pre = NULL;
    int i = 1;
    while (cur != NULL && i < pos) {
        pre = cur;
        cur = cur->next;
        i++;
    }
    if (pre == NULL) {          // 插入新头节点
        newnode->next = head;
        head->pre = newnode;
        return newnode;
    }
    newnode->next = cur;
    newnode->pre = pre;
    pre->next = newnode;
    if (cur != NULL) cur->pre = newnode;
    return head;
}

node* deletedata(node* head, int data) {
    if (head == NULL) return head;
    node* cur = head;
    while (cur != NULL && cur->data != data)  // ✅ 修复判断顺序
        cur = cur->next;
    if (cur == NULL) return head;
    if (cur == head) {                         // ✅ 删头节点提前return
        head = head->next;
        if (head != NULL) head->pre = NULL;
        free(cur);
        return head;
    }
    cur->pre->next = cur->next;
    if (cur->next != NULL) cur->next->pre = cur->pre;  // ✅ 防止尾节点崩溃
    free(cur);
    return head;
}

node* deletepos(node* head, int pos) {
    if (head == NULL) return head;
    node* cur = head;
    int i = 1;
    while (cur != NULL && i < pos) {
        cur = cur->next;
        i++;
    }
    if (cur == NULL) return head;
    if (cur == head) {                         // ✅ 删头节点提前return
        head = head->next;
        if (head != NULL) head->pre = NULL;
        free(cur);
        return head;
    }
    cur->pre->next = cur->next;
    if (cur->next != NULL) cur->next->pre = cur->pre;  // ✅ 防止尾节点崩溃
    free(cur);
    return head;
}

void printlist(node* head) {
    node* cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;
    head = insertattail(head, 1);
    head = insertattail(head, 2);
    head = insertattail(head, 3);
    head = insertatmiddle(head, 4, 2);
    head = insertatmiddle(head, 5, 4);
    head = insertatmiddle(head, 6, 1);
    printlist(head);
    head = deletedata(head, 2);
    head = deletepos(head, 3);
    printlist(head);
    return 0;
}