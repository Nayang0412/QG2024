#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "linkedList.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
void outputer(ElemType e)
{
	printf("%d->", e);

}
welcome()
{
	printf("************************                                                        ************************\n");											
	printf("*     1.初始链表       *                                                        *     6.摧毁链表       *\n");											
	printf("*     2.删除节点       *                                                        *     7.链表成环       *\n");											
	printf("*     3.查询节点       *                          * 0.退出系统  *               *     8.判断成环       *\n");
	printf("*     4.插入节点       *                          * 11.链表反转 *               *     9.中间节点       *\n");											
	printf("*     5.输出链表       *                                                        *    10.奇偶反转       *\n");	                                      
	printf("************************                                                        ************************\n");											
	

	
	
	

}
Status insert(LinkedList L)
{
	
	int digit = 0;
	LNode* e = L;
	LNode* st = (LNode*)malloc(sizeof(LNode));
	if (st==NULL)
	{
		printf("分配内存失败\n");
		return ERROR;
	}
	else
	{
		printf("请输入要插入的位置\n");
		scanf("%d",&digit);
		if (digit == 1)
		{
			printf("请输入要插入的数据");
			
			scanf("%d", &st->data);
			InsertList(L, st);
			TraverseList(L, outputer);
			printf("插入成功");
			return SUCCESS;
		}
		for (int i = 1; i < digit; i++, e = e->next);
		printf("请输入要插入的数据");
		scanf("%d", &st->data);
		InsertList(e, st);
		TraverseList(L, outputer);
		printf("插入成功");
		return SUCCESS;


	}
}
void loop(LinkedList L)
{
	LNode* p = L->next;
	while (p->next!=NULL)
	{
		p = p->next;
	}
	p->next = L;
	printf("链表成环\n");
}