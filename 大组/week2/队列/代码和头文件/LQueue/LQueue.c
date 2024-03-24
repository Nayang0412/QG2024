#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q)
{
	Q->front = Q->rear = NULL;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	Node* point;
	Node*current= Q->front;
	while (current!=NULL)
	{
		point = current->next;
		free(current);
		current = point;
	}
	Q->front = NULL;
	Q->rear = NULL;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if (Q->front==Q->rear&&Q->front==NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void **e)
{

	if (IsEmptyLQueue(Q) == FALSE)
	{
		*e = Q->front->data;
		return TRUE;
	}
	else
	{
		printf("队列为空，无法获取首元素");
		return FALSE;
	}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	unsigned int intSize = (unsigned int)Q->length;
	return intSize;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
	Node* point = (Node*)malloc(sizeof(Node));
	point->data = data;
	point->next = NULL;
	if (NULL==Q->front)
	{
		Q->front = point;
	}
	else
	{
		Q->rear->next = point;
	}
	Q->rear = point;
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	Node* point;
	point = Q->front;
	Q->front = Q->front->next;
	free(point);
	return TRUE;

}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	Node* point;
	Node* current = Q->front;
	while (current != NULL)
	{
		point = current->next;
		free(current);
		current = point;
	}
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	Node* current = Q->front;
	for (; current != NULL; current = current->next)
	{
		(*foo)(current->data);
	}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */

void LPrint(void* q)
{
	if (type == 'i')
	{
		int* value = (int*)q; // 显式将 void* 转换为 int*
		printf("%d\n", *value);
	}
	else if (type == 'f')
	{
		float* value = (float*)q; // 显式将 void* 转换为 float*
		printf("%f\n", *value);
	}
	else if (type == 'c')
	{
		char* value = (char*)q; // 显式将 void* 转换为 char*
		printf("%c\n", *value);
	}
		
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
// LQUEUE_H_INCLUDED


