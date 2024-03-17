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
	printf("请输入链表存在的元素元素\n");
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
		printf("扣1选择元素前的位置，扣2选择元素后的位置\n");
		scanf("%d",&digit);
		DuLNode* point = NULL;
		point = (DuLNode*)malloc(sizeof(DuLNode));
		printf("输入想要插入的数据\n");
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
			printf("输入无效,再次输入"); scanf("%d",&digit);
		}
	}
	
}
 void welcome()
{
	printf("************************\n");
	printf("*     1.初始链表       *\n");
	printf("*     2.删除节点       *\n");
	printf("*     3.插入节点       *\n");
	printf("*     4.输出链表       *\n");
	printf("*     5.摧毁链表       *\n");
	printf("*     0.退出系统       *\n");
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
		 printf("请输入数字0-5，选择对应功能\n");
		 scanf("%d",&key);
		 switch (key)
		 {
		 case 1:InitList_DuL(&L); k = 1;   break;
		 case 2:		
			 if (k == 0)
		 {
			 printf("未初始化链表\n"); system("pause");
			 break;
		 }
			   else
		 {
			 int *digit = 0;
			 printf("请输入要删除的节点\n");
			 scanf("%d", &digit); 
			 DuLNode* st = L;
			 st = st->next;
			 DeleteList_DuL(st,digit); system("pause"); break;
		 }
		 case 3:
			 if (k == 0)
			 {
				 printf("未初始化链表\n"); system("pause");
				 break;

			 }
			 else
			 {
				 isinsert(); system("pause"); break;
			 }
		 case 4:
			 if (k == 0)
			 {
				 printf("未初始化链表\n"); system("pause");
				 break;

			 }
			 else
			 {
				 
				 TraverseList_DuL(L, outputer); system("pause"); break;
			 }
		 case 5:
			 if (k == 0)
			 {
				 printf("未初始化链表\n"); system("pause");
				 break;

			 }
			 else
			 {
				 k = 0; DestroyList_DuL(&L); system("pause"); break;
			 }
		 case 0:
			 exit(0); break;
		 default:
			 printf("输入无效，重新输入\n"); scanf("%d", &key); break;
		 }
	 }
 }