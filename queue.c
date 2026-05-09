#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct{
    int front,rear;
    int data[MAX];
}queue;
void initqueue(queue* q){
    q->front=0;
    q->rear=0;
}
void movefront(queue* q){
    int i=0;
    for(i=0;i<q->rear-q->front;i++){
        q->data[i]=q->data[i+q->front];
    }
    q->rear=q->rear-q->front;
    q->front=0;
}
int isempty(queue* q){
    if(q->front==q->rear){
        return 1;
    }
    return 0;
}
int isfull(queue* q){
    if(q->rear==MAX){
        if(q->front==0){
            return 1;
        }else{
            movefront(q);
            return 0;
        }
    }
    return 1;
}
void enqueue(queue* q,int data){
    if(!isfull(q)){
        printf("该队列已满！无法入队\n");
        return;
    }
    q->data[q->rear++]=data;
}
void dequeue(queue* q){
    if(isempty(q)){
        printf("该队列为空！无法出队\n");
        return;
    }
    printf("%d出队",q->data[q->front]);
    q->front++;
}
int main()
{
    queue q;
    initqueue(&q);
    dequeue(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    dequeue(&q);
    enqueue(&q,40);

    return 0;
}