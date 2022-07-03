#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50

typedef int ElemType;
//定义栈的结构体
typedef struct {
	ElemType data[MAXSIZE];
	int top;
}SqStack;
//初始化栈
void InitStack(SqStack& S) {
	S.top = -1;
}
//判断栈空
bool StackEmpty(SqStack S) {
	if (S.top == -1) {
		return true;
	}
	return false;
}
//入栈
bool Push(SqStack& S, ElemType x) {
	if (S.top == MAXSIZE - 1) {
		return false;
	}
	S.top++;
	S.data[S.top] = x;
	return true;
}
//出栈
bool Pop(SqStack& S, ElemType& x) {
	if (S.top == -1) {
		return false;
	}
	x = S.data[S.top];
	S.top--;
	return true;
}
//获取栈顶元素
bool GetTop(SqStack S, ElemType& x) {
	if (S.top == -1) {
		return false;
	}
	x = S.data[S.top];
	return true;
}
int main() {
	SqStack S;
	bool flag;
	ElemType m;
	InitStack(S);
	flag = StackEmpty(S);
	if (flag) {
		printf("栈是空的\n");
	}
	Push(S, 3);
	Push(S, 4);
	Push(S, 5);
	flag = GetTop(S, m);
	if (flag) {
		printf("栈顶元素为%d\n", m);
	}
	flag = Pop(S, m);
	if (flag) {
		printf("出栈元素为%d\n", m);
	}
	return 0;
}