#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include"shop.h"
#include"menu.h"
#include"goods.h"
#include"user.h"
void input_error();  //���������ʾ
void file_open_error(FILE* fp);  //�ļ���ʧ��
void malloc_defeat(ShopLNode* A);  //��̬�ڴ�����ʧ��
Status admi_Destrong_List(ShopLinkedList *A);//�ݻ�����

void input_error()
{
	printf("||------------------------------------------||\n");
	printf("||        ������󣬽�������һ������        ||\n");
	printf("||------------------------------------------||\n");

}
void file_open_error(FILE* fp)
{
	if (fp==NULL)
	{
		printf("||------------------------------------------||\n");
		printf("||          ���ļ�ʧ�ܣ��˳�����          ||\n");
		printf("||------------------------------------------||\n");
		exit(0);
	}

}
void malloc_defeat(ShopLNode* A)
{

	if (A == NULL)
	{
		printf("||------------------------------------------||\n");
		printf("||          �����ڴ�ʧ�ܣ��˳�����          ||\n");
		printf("||------------------------------------------||\n");
		exit(0);
	}
}
Status admi_Destrong_List(ShopLinkedList* A)
{
	ShopLNode* p=*A;
	if (p->next==NULL)
	{
		free(p);
		return SUCCESS;
	}
	ShopLNode* q;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	if (NULL == p)
	{
		return ERROR;
	}


}
Status prod_Destrong_List(GoodsLinkedList*MP)
{

	GoodsLNode* p = *MP;

	GoodsLNode* q;
	if (NULL == p->next)
	{
		return ERROR;
	}
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}

}
