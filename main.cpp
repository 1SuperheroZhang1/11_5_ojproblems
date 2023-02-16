#include <iostream>
/*
 * 课时13作业
Description
    新建一个栈，读取标准输入3个整数3 4 5，入栈3 4 5，依次出栈，打印 5 4 3，
    新建循环队列（Maxsize为5），读取标准输入3 4 5 6 7，
    入队7时，队满，打印false，然后依次出队，输出 3 4 5 6
Input
    读取标准输入，内容依次是3 4 5，换行后，接着是3 4 5 6 7
Output
    如果输入是3 4 5，换行，接着是3 4 5 6 7，那么输出是
    5 4 3
    false
    3 4 5 6
注意每个数字占用两个字符的位置，5之前是有一个空格的，第三行的3之前也是有一个空格的
 * */
#define MaxSize 5
typedef int ElemType;
//用数组方式实现栈
typedef struct {
    ElemType data[MaxSize];//数组
    int top;//栈顶指针
}SqStack;

//初始化栈
void InitStack(SqStack &S){
    S.top=-1;//代表栈为空
}
//入栈
bool Push(SqStack &S,ElemType x){
    if(S.top==MaxSize-1){//判断栈是否满了 数组的大小不能改变，避免访问越界
        return false;
    }
    S.data[++S.top]=x;//等价于S.top=S.top+1; S.data[S.top]=x;
    return true;
}
//出栈
bool Pop(SqStack &S,ElemType &x){
    if(S.top==-1){//判断栈是否为空
        return false;
    }
    x=S.data[S.top--];//等价于x=S.data[S.top];S.top--;
    return true;
}

typedef int ElemType;
//用数组方式实现循环队列
typedef struct{
    ElemType data[MaxSize];//数组，存储MaxSize-1个元素
    int front,rear;//队列头 队列尾
}SqQueue;

//初始化队列
void InitQueue(SqQueue &Q){
    Q.front=Q.rear=0;
}
//入队
bool EnQueue(SqQueue &Q,ElemType x){
    if((Q.rear+1)%MaxSize==Q.front){//判断是否队满
        return false;
    }
    Q.data[Q.rear]=x;//3 4 5 6
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}
//出队
bool DeQueue(SqQueue &Q,ElemType &x){
    if(Q.rear==Q.front){//判断队列是否为空
        return false;
    }
    x=Q.data[Q.front];//先进先出
    Q.front=(Q.front+1)%MaxSize;
    return true;
}
int main() {
    SqStack S;//先进后出 FILO LIFO
    ElemType m;//用于存储出栈的元素
    InitStack(S);
    int i,num;
    for(i=0;i<3;i++){
        scanf("%d",&num);
        Push(S,num);
    }
    for(i=0;i<3;i++){
        Pop(S,m);
        printf("%2d",m);
    }
    printf("\n");
    SqQueue Q;
    bool flag;//用来判断入队是否成功
    ElemType element;//用于存储出队元素
    InitQueue(Q);
   for(i=0;i<5;i++){//入队5个元素，最后一个元素不会入队成功
       scanf("%d",&num);
       flag=EnQueue(Q,num);
       if(!flag){
           printf("false\n");
       }
   }
   for(i=0;i<4;i++){//出队4个元素并打印每一个
       DeQueue(Q,element);
       printf("%2d",element);
   }
   printf("\n");

    return 0;
}
