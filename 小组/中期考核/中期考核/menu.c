#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include"shop.h"
#include"menu.h"
#include"goods.h"
#include"user.h"
void input_error();  //输入错误显示
void file_open_error(FILE* fp);  //文件打开失败
void malloc_defeat(ShopLNode* A);  //动态内存申请失败
Status admi_Destrong_List(ShopLinkedList *A);//摧毁链表

void input_error()
{
	printf("||------------------------------------------||\n");
	printf("||        输入错误，将返回上一级界面        ||\n");
	printf("||------------------------------------------||\n");

}
void file_open_error(FILE* fp)
{
	if (fp==NULL)
	{
		printf("||------------------------------------------||\n");
		printf("||          打开文件失败，退出程序          ||\n");
		printf("||------------------------------------------||\n");
		exit(0);
	}

}
void malloc_defeat(ShopLNode* A)
{

	if (A == NULL)
	{
		printf("||------------------------------------------||\n");
		printf("||          申请内存失败，退出程序          ||\n");
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
