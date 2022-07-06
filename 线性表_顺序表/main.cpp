#include <stdio.h>

#define MaxSize 50
typedef int ElemType;

//定义结构体
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;
//函数声明
bool ListInsert(SqList& L, int i, ElemType e);//插入函数
void PrintList(SqList L);//打印函数
bool ListDelete(SqList& L, int i, ElemType& e);//删除函数
int LocateElem(SqList L, ElemType e);//查找元素位置函数

int main()
{
	SqList L;
	bool ret;
	ElemType del;
	int elem_pos;

	//手动放入三个值
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;

	//在第2个位置插入60
	ret = ListInsert(L, 2, 60);
	if (ret) {
		printf("插入成功\n");
		PrintList(L);
	}
	else {
		printf("插入失败");
	}


	//删除第一个位置的元素，并把元素值输出
	ret = ListDelete(L, 1, del);
	if (ret) {
		printf("删除成功\n");
		printf("删除的元素值为%d\n", del);
		PrintList(L);
	}
	else {
		printf("删除失败");
	}

	//查找元素60的位序
	elem_pos = LocateElem(L, 60);
	if (elem_pos) {
		printf("查找成功\n");
		printf("元素位置为%d", elem_pos);
	}
	else {
		printf("查找失败\n");
	}

	return 0;
}

//函数定义
bool ListInsert(SqList& L,int i,ElemType e) 
{	
	//判断插入位置是否合理
	if (i<1 || i>L.length + 1) {
		return false;				
	}
	//判断表空间是否足够
	if (L.length >= MaxSize) {
		return false;				
	}
	//移动元素
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];	
	}
	//赋值、表长加一
	L.data[i - 1] = e;				
	L.length++;					

	return true;
}
void PrintList(SqList L) 
{
	for (int i = 0; i < L.length; i++) {
		printf("%3d", L.data[i]);
	}
	printf("\n");
}
bool ListDelete(SqList& L, int i, ElemType &e)
{
	//判断删除位置是否合理
	if (i<1 || i>L.length ) {
		return false;
	}
	if (L.length == 0) {
		return false;
	}
	//赋值
	e = L.data[i - 1];
	//移动元素
	for (int j = i; j <= L.length; j++) {
		L.data[j-1] = L.data[j];
	}
	//表长减一
	L.length--;

	return true;
}
int LocateElem(SqList L, ElemType e)
{
	int i;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		}
	}
	return 0;
}