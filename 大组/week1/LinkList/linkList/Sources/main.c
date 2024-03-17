#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "linkedList.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
LinkedList  L;

void  main()
{
	int key;
	char k = 0;
	while (1)
	{
		system("cls");
		welcome();
		printf("请输入数字0-10，选择对应功能\n");
		scanf("%d",&key);
		switch (key)
		{
		case 1:InitList(&L); k = 1; break;
		case 2:
			if (k==0)
		    {
			    printf("未初始化链表\n"); system("pause");
				break;
		    } 
			else
			{
				int *digit = 0;
				printf("请输入要删除的节点\n");
				scanf("%d",&digit);
				DeleteList(L,digit); system("pause"); break;
			}
		case 3:
			if (k == 0)
		    {
			   printf("未初始化链表\n"); system("pause");
			   break;
		    }
			else
			{
				int digit = 0;
				printf("请输入要查找的节点\n");
				scanf("%d", &digit);
				SearchList(L, digit); system("pause"); break;
			}
		case 4:
			if (k == 0)
		    {
			   printf("未初始化链表\n"); system("pause");
			   break;

		    }
			else
			{
				insert(L); system("pause"); break;
			}
		case 5:
			if (k == 0)
			{
				printf("未初始化链表\n"); system("pause");
				break;

			}
			else
			{
				TraverseList(L, outputer); system("pause"); break;
			}
		case 6:
			if (k == 0)
			{
				printf("未初始化链表\n"); system("pause");
				break;

			}
			else
			{
				DestoryList(&L); system("pause"); k = 0; break;
			}
		case 7:
			if (k == 0)
			{
				printf("未初始化链表\n"); system("pause");
				break;

			}
			else
			{
				loop(L); system("pause"); break;
			}
		case 8:
			if (k == 0)
			{
				printf("未初始化链表\n"); system("pause");
				break;

			}
			else
			{
				IsLoopList(L); system("pause"); break;
			}
		case 9:
			if (k == 0)
			{
				printf("未初始化链表\n"); system("pause");
				break;

			}
			else
			{
				FindMidNode(&L); system("pause"); break;
			}
		case 10:
			if (k == 0)
			{
				printf("未初始化链表\n"); system("pause");
				break;

			}
			else
			{
				ReverseEvenList(&L); system("pause"); break;
			}
		case 11:
			if (k == 0)
			{
				printf("未初始化链表\n"); system("pause");
				break;

			}
			else
			{
				ReverseList(&L); system("pause"); break;
			}
		case 0:
			exit(0); break;

		default:printf("输入无效，重新输入\n"); scanf("%d",&key);break;
		}
	}
	
	
}