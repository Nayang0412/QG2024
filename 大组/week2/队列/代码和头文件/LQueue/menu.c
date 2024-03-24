#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"

void get_int(void** data)
{
	while (getchar() != '\n');
	int* p = (int*)malloc(sizeof(int));
	char s[50];
	int flag = 1;
	while (1)
	{
		gets_s(s, sizeof(s));
		if (*s == '-')
		{
			if (strlen(s) < 6)
			{
				int i;
				for (i = 1; i < 6 && s[i] != '\0'; i++)
					if (s[i] < '0' || s[i]>'9');
				{
					flag = 0;
					break;
				}
				if (flag == 1)
				{
					*p = 0;
					for (i = 1; i < 6 && s[i] != '\0'; i++)
						*p = (*p) * 10 + s[i] - '0';
					(*p) *= -1;
					*data = (void*)p;
					return;
				}
			}
		}
		else if (strlen(s) < 5)
		{
			int i;
			for (i = 0; i < 5 && s[i] != '\0'; i++)
				if (s[i] < '0' || s[i]>'9')
				{
					flag = 0;
					break;
				}
			if (flag == 1)
			{
				*p = 0;
				for (i = 0; i < 5 && s[i] != '\0'; i++)
					*p = (*p) * 10 + s[i] - '0';
				*data = (void*)p;
				return;
			}
		}
		printf("Please give me a right int number which is bigger than -10000 and smaller than 10000;\n");
	}
}
void get_float(void** data)
{

	float* p = (float*)malloc(sizeof(float));
	*p = 0.0;
	/* 此处可以用类比于上面那个函数和计算器中那个写，但是太长了，所以......靠用户诚实  */
	scanf("%f", p);
	*data = (void*)p;
	while (getchar() != '\n');
}

void get_char(void** data)
{
	
	char* p = (char*)malloc(sizeof(char));
	*p = '0';
	while (getchar() != '\n');
	scanf("%c", p);
	while (getchar() != '\n');
	*data = (void*)(p);
}
void get_type()
{
	while (1)
	{
		type = '\0';
		printf("请告诉我您想要保存什么种类的数据:\n");
		printf("'i' 表示整数，'f' 表示浮点数，'c' 表示字符!\n");
		scanf("%c", &type);
		while (getchar() != '\n');
		if (type == 'i' || type == 'f' || type == 'c')
			break;
		else
		{
			system("cls");
			printf("Please don't give me others!\n");
		}
	}
}
void get_data(void** data)
{
	if (type == 'i')
		get_int(data);
	else if (type == 'f')
		get_float(data);
	else if (type == 'c')
		get_char(data);
}
void menu()
{
	int key = 0;
	LQueue *Q=(LQueue*)malloc(sizeof(LQueue));
	InitLQueue(Q);
	get_type();
	int choice;
	void* data=NULL;
	if (type == 'i')
		data = (void*)malloc(sizeof(int));
	else if (type == 'f')
		data = (void*)malloc(sizeof(float));
	else if (type == 'c')
		data = (void*)malloc(sizeof(char));
	void* addData=NULL;
	do {
		system("cls");
		printf("\n--- 链式队列操作菜单 ---\n");
		printf("1. 入队\n");
		printf("2. 出队\n");
		printf("3. 获取队头元素\n");
		printf("4. 判断队列是否为空\n");
		printf("5. 清空队列\n");
		printf("6. 输出队列元素\n");
		printf("0. 退出\n");
		printf("请输入选项：");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("请输入要入队的元素：\n");
			get_data(&addData);
			key++;
			// 假设这里是获取用户输入的数据，并将其存储在 data 中
			EnLQueue(Q, addData);
			system("pause");
			break;
		case 2:
			if (key==0)
			{
				printf("空队列，无法操作");
				break;
			}
			DeLQueue(Q); 
			key --;
			printf("出队成功\n");
			system("pause");
			break;
		case 3:
			if (key == 0)
			{
				printf("空队列，无法操作");
				system("pause");
				break;
			}
			if (GetHeadLQueue(Q, &data)==TRUE) 
			{
				// 处理获取到的队头元素 data
				printf("队头元素为：");
				LPrint(data);
			}
			system("pause");
			break;
		case 4:
			if (IsEmptyLQueue(Q)) {
				printf("队列为空\n");
			}
			else {
				printf("队列不为空\n");
			}
			system("pause");
			break;
		case 5:
			if (key == 0)
			{
				printf("空队列，无法操作");
				system("pause");
				break;
			}
			ClearLQueue(Q); key = 0;
			system("pause");
			break;
		case 6:
			if (key == 0)
			{
				printf("空队列，无法操作");
				system("pause");
				break;
			}
			TraverseLQueue(Q,LPrint);
			system("pause");
			break;
		case 0:
			exit(0);
			printf("退出程序\n");
			break;
		default:
			printf("无效选项\n");
			system("pause");
		}

	} while (choice != 0);

	DestoryLQueue(Q);

	return 0;
}
