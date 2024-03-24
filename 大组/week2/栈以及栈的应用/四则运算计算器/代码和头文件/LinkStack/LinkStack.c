#include "LinkStack.h" 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//链栈

//初始化栈
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

//判断栈是否为空
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

//得到栈顶元素
char getTopLStack(LinkStack *s)
{
	if (s->top == NULL||s->count==0)
	{
		printf("为空栈无法操作\n");
		return ERROR;
	}
	
	
	return s->top->data;;

}

//清空栈
Status clearLStack(LinkStack *s)
{
	if (s->top == NULL)
	{
		printf("该栈已为空栈\n");
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
	printf("栈已清空\n");
	return SUCCESS;
;
}

//销毁栈
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

//检测栈长度
Status LStackLength(LinkStack *s,int *length)
{
	*length = s->count;
	return SUCCESS;
}

//入栈
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

//出栈
char popLStack(LinkStack *s)
{
	StackNode* p;
	
	char op;
	if (s->top==NULL)
	{
		printf("为空栈无法操作\n");
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
		printf("为空栈无法操作\n");
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


 
