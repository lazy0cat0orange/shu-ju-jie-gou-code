#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <corecrt_malloc.h>
typedef int ElemType;
typedef struct DNode {
	ElemType data;
	struct DNode* prior;
	struct DNode* next;
}DNode,*DLinkList;
//头插法新建链表
DLinkList CreatDList1(DLinkList& DL);
//打印链表
void PrintDList(DLinkList DL);
//尾插法新建链表
DLinkList CreatDList2(DLinkList& DL);
//按序号查找元素
DLinkList GetElem(DLinkList DL, int i);
//插入新元素
bool DListInsert(DLinkList& DL, int i, ElemType e);
//删除元素
bool DListDelete(DLinkList& DL, int i);
int main(void) {
	DLinkList DL;
	DLinkList search;
	//CreatDList1(DL);
	CreatDList2(DL);
	PrintDList(DL);
	search = GetElem(DL, 2);
	if (search != NULL) {
		printf("按序号查找成功\n");
		printf("%d\n", search->data);
	}
	int ret = DListInsert(DL, 2, 8);
	if (ret) {
		printf("插入成功\n");
		PrintDList(DL);
	}
	ret = DListDelete(DL, 2);
	if (ret) {
		printf("删除成功\n");
		PrintDList(DL);
	}
	return 0;
}
DLinkList CreatDList1(DLinkList& DL) {
	DNode* s;
	int x;
	DL = (DNode*)malloc(sizeof(DNode));
	DL->next = NULL;
	DL->prior = NULL;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DLinkList)malloc(sizeof(DNode));
		s->data = x;
		s->next = DL->next;
		if (DL->next != NULL)
		{
			DL->next->prior = s;
		}
		s->prior = DL;
		DL->next = s;
		scanf("%d", &x);
	}
	return DL;
}
DLinkList CreatDList2(DLinkList& DL) {
	int x;
	DL = (DNode*)malloc(sizeof(DNode));
	DNode* s, * r = DL;
	DL->prior = NULL;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DLinkList)malloc(sizeof(DNode));
		s->data = x;
		r->next = s;
		s->prior = r;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return DL;
}
void PrintDList(DLinkList DL) {
	DL = DL->next;
	while (DL != NULL) {
		printf("%3d", DL->data);
		DL = DL->next;
	}
	printf("\n");
}
DLinkList GetElem(DLinkList DL, int i) {
	DLinkList p = DL->next;
	if (i == 0) {
		return DL;
	}
	if (i < 1) {
		return NULL;
	}
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
bool DListInsert(DLinkList& DL, int i, ElemType e) {
	DLinkList p = GetElem(DL, i - 1);
	if (NULL == p) {
		return false;
	}
	DLinkList s = (DLinkList)malloc(sizeof(DNode));
	s->data = e;
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}
bool DListDelete(DLinkList& DL, int i) {
	DLinkList p = GetElem(DL, i - 1);
	if (NULL == p) {
		return false;
	}
	DLinkList q = p->next;
	if (NULL == q) {
		return false;
	}
	p->next = q->next;
	if (q->next  != NULL) {
		q->next->prior = p;
	}
	free(q);
	q = NULL;
	return true;
}