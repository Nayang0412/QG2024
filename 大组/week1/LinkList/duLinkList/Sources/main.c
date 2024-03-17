#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "dulinkedList.h"
DuLinkedList L;
void outputer(ElemType e)
{
	printf("%d->", e);
}
void isinsert()
{
	int digit = 0;
	TraverseList_DuL(L,outputer);
	printf("������������ڵ�Ԫ��Ԫ��\n");
	scanf("%d",&digit);
	DuLNode* st = L->next;
	for ( ;  st!=NULL; st=st->next)
	{
		if (st->data == digit)
		{
			break;
		}
	}
	if (st)
	{
		printf("��1ѡ��Ԫ��ǰ��λ�ã���2ѡ��Ԫ�غ��λ��\n");
		scanf("%d",&digit);
		DuLNode* point = NULL;
		point = (DuLNode*)malloc(sizeof(DuLNode));
		printf("������Ҫ���������\n");
		scanf("%d", &point->data);
		if (digit==1)
		{
			InsertBeforeList_DuL(st,point);
		}
		else if(digit==2)
		{
			InsertAfterList_DuL(st,point);
		}
		else
		{
			printf("������Ч,�ٴ�����"); scanf("%d",&digit);
		}
	}
	
}
 void welcome()
{
	printf("************************\n");
	printf("*     1.��ʼ����       *\n");
	printf("*     2.ɾ���ڵ�       *\n");
	printf("*     3.����ڵ�       *\n");
	printf("*     4.�������       *\n");
	printf("*     5.�ݻ�����       *\n");
	printf("*     0.�˳�ϵͳ       *\n");
	printf("************************\n");


}
 void main()
 {
	 int key;
	 char k = 0;
	
	 while (1)
	 {
		 system("cls");
		 welcome();
		 printf("����������0-5��ѡ���Ӧ����\n");
		 scanf("%d",&key);
		 switch (key)
		 {
		 case 1:InitList_DuL(&L); k = 1;   break;
		 case 2:		
			 if (k == 0)
		 {
			 printf("δ��ʼ������\n"); system("pause");
			 break;
		 }
			   else
		 {
			 int *digit = 0;
			 printf("������Ҫɾ���Ľڵ�\n");
			 scanf("%d", &digit); 
			 DuLNode* st = L;
			 st = st->next;
			 DeleteList_DuL(st,digit); system("pause"); break;
		 }
		 case 3:
			 if (k == 0)
			 {
				 printf("δ��ʼ������\n"); system("pause");
				 break;

			 }
			 else
			 {
				 isinsert(); system("pause"); break;
			 }
		 case 4:
			 if (k == 0)
			 {
				 printf("δ��ʼ������\n"); system("pause");
				 break;

			 }
			 else
			 {
				 
				 TraverseList_DuL(L, outputer); system("pause"); break;
			 }
		 case 5:
			 if (k == 0)
			 {
				 printf("δ��ʼ������\n"); system("pause");
				 break;

			 }
			 else
			 {
				 k = 0; DestroyList_DuL(&L); system("pause"); break;
			 }
		 case 0:
			 exit(0); break;
		 default:
			 printf("������Ч����������\n"); scanf("%d", &key); break;
		 }
	 }
 }