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
	printf("*     1.��ʼ����       *                                                        *     6.�ݻ�����       *\n");											
	printf("*     2.ɾ���ڵ�       *                                                        *     7.����ɻ�       *\n");											
	printf("*     3.��ѯ�ڵ�       *                          * 0.�˳�ϵͳ  *               *     8.�жϳɻ�       *\n");
	printf("*     4.����ڵ�       *                          * 11.����ת *               *     9.�м�ڵ�       *\n");											
	printf("*     5.�������       *                                                        *    10.��ż��ת       *\n");	                                      
	printf("************************                                                        ************************\n");											
	

	
	
	

}
Status insert(LinkedList L)
{
	
	int digit = 0;
	LNode* e = L;
	LNode* st = (LNode*)malloc(sizeof(LNode));
	if (st==NULL)
	{
		printf("�����ڴ�ʧ��\n");
		return ERROR;
	}
	else
	{
		printf("������Ҫ�����λ��\n");
		scanf("%d",&digit);
		if (digit == 1)
		{
			printf("������Ҫ���������");
			
			scanf("%d", &st->data);
			InsertList(L, st);
			TraverseList(L, outputer);
			printf("����ɹ�");
			return SUCCESS;
		}
		for (int i = 1; i < digit; i++, e = e->next);
		printf("������Ҫ���������");
		scanf("%d", &st->data);
		InsertList(e, st);
		TraverseList(L, outputer);
		printf("����ɹ�");
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
	printf("����ɻ�\n");
}