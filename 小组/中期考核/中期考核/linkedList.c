#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
Status InitList(LinkedList* L);//初始化列表
void DestroyList(LinkedList* L);//摧毁列表
Status InsertList(LNode* p, LNode* q);//插入新节点
Status DeleteList(LNode* p, ElemType* e);//删除节点
void TraverseList(LinkedList L, void (*visit)(ElemType e));
Status SearchList(LinkedList L, ElemType e);//找到链表的节点
Status ReverseList(LinkedList* L);//链表倒转
Status IsLoopList(LinkedList L);//判断链表是否成环
LNode* ReverseEvenList(LinkedList* L);//奇偶调换
LNode* FindMidNode(LinkedList* L);//查找中间节点
//

Status InitList(LinkedList* L)
{
	printf("初始化成功\n");
	int digit = 0;//链表节点数量
	*L= (LNode*)malloc(sizeof(LNode));
	LNode* head = *L;
	LNode* q=NULL;
	if (*L==NULL)
	{
		printf("申请空间失败");
		return ERROR;
	}
	printf("请输入1~20，来创建链表节点的个数\n");
	scanf("%d",&digit);
	if (digit > 20||digit<=0)
	{
		printf("输入不规划，再次输入\n");
		scanf("%d", &digit);
	}
	else
	{
		for (int i = 1; i <= digit; i++)
		{
			LNode* p = (LNode*)malloc(sizeof(LNode));
			if (p == NULL)
			{
				printf("申请空间失败");
				return ERROR;
			}
			printf("请输入%d个节点的数据,不超过10位\n",i);
			scanf("%d",&p->data);
			if (i==1)
			{
				head->next = p;
			}
			else
			{
				q->next = p;
			}
		
			q = p;
			p->next = NULL;

		}

	}
	printf("创建链表成功");
	system("pause");
	return SUCCESS;

}

void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	LNode* p = L->next;
	
	for (; p != NULL; p = p->next)
	{
		
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

void DestoryList(LinkedList* L)
{
	LNode* p = *L;
	LNode* q = NULL;
	while (q)
	{
		p = p->next;
		free(q);
		q = p;
	}

	printf("摧毁链表成功");

}
Status SearchList(LinkedList L, ElemType e)
{
	LNode* q = L;
	q = q->next;
	for (;q!=NULL;q=q->next )
	{
		if (e==q->data)
		{
			printf("该节点存在链表中\n"); 
			return SUCCESS;
		}
	}
	printf("该节点不存在链表中");
	return ERROR;

}
Status DeleteList(LNode* p, ElemType* e)
{
	LNode* q = p;
	LNode* st;
	for (; q != NULL; q = q->next)
	{
		if (e == q->next->data)
		{
			st = q->next;
			q->next = st->next;
			free(st);
			printf("删除节点成功");
			return SUCCESS;
		}
	}
	printf("删除节点失败");
	return ERROR;
}
Status InsertList(LNode* p, LNode* q)
{
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}
Status IsLoopList(LinkedList L)
{
	LNode* p, * q;
	p = L;
	q = L;
	while (q!=NULL&&q->next!=NULL)
	{
		p = p->next;
		q = q->next->next;
		if (p==q)
		{
			printf("链表成环"); 
			return SUCCESS;
		}
	}
	printf("链表不成环");
	return ERROR;

}
LNode* FindMidNode(LinkedList* L)
{
	LNode* p = *L;
	LNode* q = *L;
	while (q!=NULL&&q->next!=NULL)
	{
		p = p->next;
		q = q->next->next;

	}
	printf("中间节点数据为%d",p->data);
	return p;

}
LNode* ReverseEvenList(LinkedList* L)
{
	
	LNode* p = *L;
	LNode* q = *L;
	int digit = 0;
	p = p->next;
	q = p->next;
	while (q != NULL&&q->next!=NULL)
	{
		if ((p->data%2==0&&q->data%2==1)||(q->data % 2 == 0 && p->data % 2 == 1))
		{
			digit = p->data;
			p->data = q->data;
			q->data = digit;
		}
	
		if ( q->next->next == NULL)
		{
			break;
		}
		p = p->next->next;
		q = p->next;
	}
	if (q->next == NULL)
	{
		if (p->data % 2 == 0 && q->data % 2 == 1)
		{
			digit = p->data;
			p->data = q->data;
			q->data = digit;
		}
		else if (q->data % 2 == 0 && p->data % 2 == 1)
		{
			digit = p->data;
			p->data = q->data;
			q->data = digit;
		}

	}
	printf("反转成功\n");
	return *L;
}
Status ReverseList(LinkedList* L)
{/*
	LNode* q = NULL;
	 static int exc = 0;
	
		LNode* p = *L; exc ++;
		p = p->next;
		LNode* st = ReverseList(&p);
		p->next->next = p;
		p->next = NULL;
		return st;
	

	
	LNode* temp = NULL;
	*/
	
//递归



//非递归
	LNode* p = *L;
	LNode* temp = NULL;
	LNode* q = NULL;
	LNode* st = *L;
	while (p->next != NULL)
	{
		temp = p->next;
		p->next = q;
		q = p;
		p = temp;
	}
	p->next = q;
	st->next = p;
	printf("链表反转成功\n");
	return SUCCESS;


}
