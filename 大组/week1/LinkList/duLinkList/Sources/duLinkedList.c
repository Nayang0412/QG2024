#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "dulinkedList.h"
Status InitList_DuL(DuLinkedList* L);//��ʼ����
void DestroyList_DuL(DuLinkedList* L);//ɾ������
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q);//����ڵ�ǰ
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q);//����ڵ��
Status DeleteList_DuL(DuLNode* p, ElemType* e);//ɾ���ڵ�
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));//�����ڵ�
////////////////////////


Status InitList_DuL(DuLinkedList* L)
{
	printf("��ʼ���ɹ�\n");
	int digit = 0;//����ڵ�����
	*L = (DuLNode*)malloc(sizeof(DuLNode));
	DuLNode* head = *L;
	DuLNode* q = NULL;
	if (*L == NULL)
	{
		printf("����ռ�ʧ��");
		return ERROR;
	}
	head->prior = NULL;
	printf("������1~20������������ڵ�ĸ���\n");
	scanf("%d", &digit);
	if (digit > 20 || digit <= 0)
	{
		printf("���벻�滮���ٴ�����\n");
		scanf("%d", &digit);
	}
	else
	{
		for (int i = 1; i <= digit; i++)
		{
			DuLNode* p = (DuLNode*)malloc(sizeof(DuLNode));
			if (p == NULL)
			{
				printf("����ռ�ʧ��");
				return ERROR;
			}
			printf("������%d���ڵ������,������10λ\n", i);
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
printf("��������ɹ�");
system("pause");
return SUCCESS;

}
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	DuLNode* p = L->next;
	DuLNode* q = L->next;
	printf("������:");
	for (; p != NULL; p = p->next)
	{

		printf("%d->", p->data);
		if (p->next==NULL)
		{
			printf("NULL\n");
			DuLNode* st = p;
			printf("������:");
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

	printf("�ݻ�����ɹ�");
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

			if (q->prior ==p) // �ڵ�������ĵ�һ���ڵ�
			{
				p = q->next;
				if (q->next != NULL) {
					q->next->prior = NULL;
				}
			}
			else if (q->next == NULL) // �ڵ�����������һ���ڵ�
			{
				q->prior->next = NULL;
			}
			else // �ڵ��������м�
			{
				q->prior->next = q->next;
				q->next->prior = q->prior;
			}

			DuLNode* temp = q;
			q = q->next;
			free(temp);
			break; // �ж�ѭ��
		}

		q = q->next;
	}

	return SUCCESS;
}*/
