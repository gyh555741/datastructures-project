#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct stack{
    int data[MAX];
    int top;
}stack;
void initstack(stack* s){
    s->top=-1;
}
void pushback(stack* s,int data){
    if(s->top>=MAX-1){
        printf("栈已满，无法入栈\n");
        return;
    }
    s->top++;
    s->data[s->top]=data;
}
void popback(stack* s){
    if(s->top==-1){
        printf("无数据可出栈！\n");
        return;
    }
    printf("%d出栈\n",s->data[s->top]);
    s->top--;
}
int main()
{
    stack s;
    initstack(&s);
    popback(&s);
    pushback(&s,10);
    pushback(&s,20);
    pushback(&s,30);
    pushback(&s,40);
    popback(&s);
    pushback(&s,50);

    return 0;
}