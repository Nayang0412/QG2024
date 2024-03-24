#include "LinkStack.h" 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s)
{
	s = (LinkStack*)malloc(sizeof(LinkStack));
	if (s==NULL)
	{
		return  ERROR;
	}
	s->top= NULL;
	s->count = 0;

	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s)
{
	if (s->count==0|s->top==NULL)
	{
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
	/*
		if (s->top==NULL)
	{
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
	*/
}

//�õ�ջ��Ԫ��
char getTopLStack(LinkStack *s)
{
	if (s->top == NULL||s->count==0)
	{
		printf("Ϊ��ջ�޷�����\n");
		return ERROR;
	}
	
	
	return s->top->data;;

}

//���ջ
Status clearLStack(LinkStack *s)
{
	if (s->top == NULL)
	{
		printf("��ջ��Ϊ��ջ\n");
		return ERROR;
	}
	StackNode* p;
	while (s->count!=0)
	{
		p = s->top;
		s->top = s->top->next;
		free(p);
		s->count--;
	}
	printf("ջ�����\n");
	return SUCCESS;
;
}

//����ջ
Status destroyLStack(LinkStack *s)
{
	StackNode* p;
	while (s->count != 0)
	{
		p = s->top;
		s->top = s->top->next;
		free(p);
		s->count--;
	}
	 p = s->top;
	free(p);
	return SUCCESS;

}

//���ջ����
Status LStackLength(LinkStack *s,int *length)
{
	*length = s->count;
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data)
{
	StackNode* p;
	
	p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}

//��ջ
char popLStack(LinkStack *s)
{
	StackNode* p;
	
	char op;
	if (s->top==NULL)
	{
		printf("Ϊ��ջ�޷�����\n");
		return ERROR;
	}
	else
	{
		op = s->top->data;
		p = s->top;
		s->top = s->top->next;
		free(p);
		s->count--;
		
		return op;
	}
}
int popintLStack(LinkStack* s)
{
	StackNode* p;
	int data = 0;
	
	
	if (s->top == NULL)
	{
		printf("Ϊ��ջ�޷�����\n");
		return ERROR;
	}
	else
	{
		data = s->top->data;
		p = s->top;
		s->top = s->top->next;
		free(p);
		s->count--;

		return data;
	}
}


 
