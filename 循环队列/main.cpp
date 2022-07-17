#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int front, rear;
}SqQueue;
//初始化
void InitQueue(SqQueue& Q) {
	Q.rear = Q.front = 0;
}
//判空
bool isEmpty(SqQueue Q) {
	if (Q.rear == Q.front) {
		return true;
	}
	return false;
}
bool EnQueue(SqQueue& Q,ElemType x) {
	if ((Q.rear + 1) % MAXSIZE == Q.front) {
		return false;
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}
bool DeQueue(SqQueue& Q, ElemType& x) {
	if (Q.rear == Q.front) {
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}
int main()
{
	SqQueue Q;
	bool ret;
	ElemType element;
	InitQueue(Q);
	ret = isEmpty(Q);
	if (ret) {
		printf("队列为空\n");
	}
	else {
		printf("队列不为空\n");
	}
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	EnQueue(Q, 5);
	ret =EnQueue(Q, 6);
	ret =EnQueue(Q,7);
	if (ret) {
		printf("入队成功\n");
	}
	else {
		printf("入队失败\n");
	}
	ret = DeQueue(Q, element);
	if (ret) {
		printf("出队成功，元素值为%d\n",element);
	}
	else {
		printf("出队失败\n");
	}
	ret = DeQueue(Q, element);
	if (ret) {
		printf("出队成功，元素值为%d\n", element);
	}
	else {
		printf("出队失败\n");
	}
	return 0;
}