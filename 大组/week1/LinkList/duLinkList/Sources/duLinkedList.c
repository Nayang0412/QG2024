#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "dulinkedList.h"
Status InitList_DuL(DuLinkedList* L);//初始链表
void DestroyList_DuL(DuLinkedList* L);//删除链表
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q);//插入节点前
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q);//插入节点后
Status DeleteList_DuL(DuLNode* p, ElemType* e);//删除节点
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));//遍历节点
////////////////////////


Status InitList_DuL(DuLinkedList* L)
{
	printf("初始化成功\n");
	int digit = 0;//链表节点数量
	*L = (DuLNode*)malloc(sizeof(DuLNode));
	DuLNode* head = *L;
	DuLNode* q = NULL;
	if (*L == NULL)
	{
		printf("申请空间失败");
		return ERROR;
	}
	head->prior = NULL;
	printf("请输入1~20，来创建链表节点的个数\n");
	scanf("%d", &digit);
	if (digit > 20 || digit <= 0)
	{
		printf("输入不规划，再次输入\n");
		scanf("%d", &digit);
	}
	else
	{
		for (int i = 1; i <= digit; i++)
		{
			DuLNode* p = (DuLNode*)malloc(sizeof(DuLNode));
			if (p == NULL)
			{
				printf("申请空间失败");
				return ERROR;
			}
			printf("请输入%d个节点的数据,不超过10位\n", i);
			scanf("%d", &p->data);
			if (i == 1)
			{
				head->next = p;
				p->prior = head;
			}
			else
			{
				q->next = p;
				p->prior = q;
			}

			q = p;
			p->next = NULL;

		}
	}
printf("创建链表成功");
system("pause");
return SUCCESS;

}
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	DuLNode* p = L->next;
	DuLNode* q = L->next;
	printf("正链表:");
	for (; p != NULL; p = p->next)
	{

		printf("%d->", p->data);
		if (p->next==NULL)
		{
			printf("NULL\n");
			DuLNode* st = p;
			printf("反链表:");
			for ( ;  st!=L; st=st->prior)
			{
				printf("%d->",st->data);
			}
			printf("NULL\n");
		}
	}

}
void DestroyList_DuL(DuLinkedList* L)
{
	DuLNode* p = *L;
	DuLNode* q = NULL;
	while (q)
	{
		p = p->next;
		free(q);
		q = p;
	}

	printf("摧毁链表成功");
}
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	q->next = p;
	q->prior = p->prior;
	q->prior->next = q;
	p->prior = q;
	return SUCCESS;

}
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	q->next = p->next;
	q->prior = p;
	p->next = q;
	return SUCCESS;

}
Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	DuLNode * q = p;
	DuLNode* st = NULL;
	char key = 0;
	for ( ; q!=NULL;q=q->next )
	{
		
		if (q->data==e)
		{
			key = 1; printf("ok");
			if (q->next == NULL) 
			{
				q->prior->next = NULL;
				st = q;
				break;
				
			}
			else
			{
				q->prior->next = q->next;
				q->next->prior = q->prior;
				st = q;
				break;
			}
		}
	}
	q = q->next;
	free(st);
	if (key==1)
	{
		return SUCCESS;
	}
	return ERROR;
	

}
/*Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	DuLNode* q = p;
	char key = 0;

	while (q != NULL)
	{
		if (q->data == e)
		{
			key = 1;
			printf("ok");

			if (q->prior ==p) // 节点是链表的第一个节点
			{
				p = q->next;
				if (q->next != NULL) {
					q->next->prior = NULL;
				}
			}
			else if (q->next == NULL) // 节点是链表的最后一个节点
			{
				q->prior->next = NULL;
			}
			else // 节点在链表中间
			{
				q->prior->next = q->next;
				q->next->prior = q->prior;
			}

			DuLNode* temp = q;
			q = q->next;
			free(temp);
			break; // 中断循环
		}

		q = q->next;
	}

	return SUCCESS;
}*/
