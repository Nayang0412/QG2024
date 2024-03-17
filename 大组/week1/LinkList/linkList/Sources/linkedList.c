#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
Status InitList(LinkedList* L);//��ʼ���б�
void DestroyList(LinkedList* L);//�ݻ��б�
Status InsertList(LNode* p, LNode* q);//�����½ڵ�
Status DeleteList(LNode* p, ElemType* e);//ɾ���ڵ�
void TraverseList(LinkedList L, void (*visit)(ElemType e));
Status SearchList(LinkedList L, ElemType e);//�ҵ�����Ľڵ�
Status ReverseList(LinkedList* L);//����ת
Status IsLoopList(LinkedList L);//�ж������Ƿ�ɻ�
LNode* ReverseEvenList(LinkedList* L);//��ż����
LNode* FindMidNode(LinkedList* L);//�����м�ڵ�
//

Status InitList(LinkedList* L)
{
	printf("��ʼ���ɹ�\n");
	int digit = 0;//����ڵ�����
	*L= (LNode*)malloc(sizeof(LNode));
	LNode* head = *L;
	LNode* q=NULL;
	if (*L==NULL)
	{
		printf("����ռ�ʧ��");
		return ERROR;
	}
	printf("������1~20������������ڵ�ĸ���\n");
	scanf("%d",&digit);
	if (digit > 20||digit<=0)
	{
		printf("���벻�滮���ٴ�����\n");
		scanf("%d", &digit);
	}
	else
	{
		for (int i = 1; i <= digit; i++)
		{
			LNode* p = (LNode*)malloc(sizeof(LNode));
			if (p == NULL)
			{
				printf("����ռ�ʧ��");
				return ERROR;
			}
			printf("������%d���ڵ������,������10λ\n",i);
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
	printf("��������ɹ�");
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

	printf("�ݻ�����ɹ�");

}
Status SearchList(LinkedList L, ElemType e)
{
	LNode* q = L;
	q = q->next;
	for (;q!=NULL;q=q->next )
	{
		if (e==q->data)
		{
			printf("�ýڵ����������\n"); 
			return SUCCESS;
		}
	}
	printf("�ýڵ㲻����������");
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
			printf("ɾ���ڵ�ɹ�");
			return SUCCESS;
		}
	}
	printf("ɾ���ڵ�ʧ��");
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
			printf("����ɻ�"); 
			return SUCCESS;
		}
	}
	printf("�����ɻ�");
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
	printf("�м�ڵ�����Ϊ%d",p->data);
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
	printf("��ת�ɹ�\n");
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
	
//�ݹ�



//�ǵݹ�
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
	printf("����ת�ɹ�\n");
	return SUCCESS;


}
