#include <stdio.h>
#include <stdlib.h>

#define max 100
typedef struct seqlist{
    int data[max];
    int length;
}seqlist;
//初始化线性表
void initlist(seqlist* s){
    s->length=0;
    printf("初始化成功！\n");
}
//插入元素
void insertdata(seqlist* s,int data){
    if(s->length>=max){
        printf("线性表已满！\n");
        return;
    }
    s->data[s->length]=data;
    s->length++;
}
//删除元素
void deletedata(seqlist* s,int pos){
    if(pos<0||pos>=s->length){
        printf("位置不合法！\n");
        return;
    }
    for(int i=pos-1;i<s->length-1;i++){
            s->data[i]=s->data[i+1];
    }
    s->length--;
}
//打印线性表
void printlist(seqlist* s){
    for(int i=0;i<s->length;i++){
        printf("%d ",s->data[i]);
    }
    printf("\n");
}
int main()
{
 
    seqlist s;
    initlist(&s);
    insertdata(&s,1);
    insertdata(&s,2);
    insertdata(&s,3);
    insertdata(&s,4);
    insertdata(&s,5);
    printf("线性表长度：%d\n",s.length);
    deletedata(&s,2);
    printlist(&s);

    return 0;
} 