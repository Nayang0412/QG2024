#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q)
{
	Q->front = Q->rear = NULL;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
		printf("����Ϊ�գ��޷���ȡ��Ԫ��");
		return FALSE;
	}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	unsigned int intSize = (unsigned int)Q->length;
	return intSize;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */

void LPrint(void* q)
{
	if (type == 'i')
	{
		int* value = (int*)q; // ��ʽ�� void* ת��Ϊ int*
		printf("%d\n", *value);
	}
	else if (type == 'f')
	{
		float* value = (float*)q; // ��ʽ�� void* ת��Ϊ float*
		printf("%f\n", *value);
	}
	else if (type == 'c')
	{
		char* value = (char*)q; // ��ʽ�� void* ת��Ϊ char*
		printf("%c\n", *value);
	}
		
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
// LQUEUE_H_INCLUDED


