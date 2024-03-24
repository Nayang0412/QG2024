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
	/* �˴�����������������Ǹ������ͼ��������Ǹ�д������̫���ˣ�����......���û���ʵ  */
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
		printf("�����������Ҫ����ʲô���������:\n");
		printf("'i' ��ʾ������'f' ��ʾ��������'c' ��ʾ�ַ�!\n");
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
		printf("\n--- ��ʽ���в����˵� ---\n");
		printf("1. ���\n");
		printf("2. ����\n");
		printf("3. ��ȡ��ͷԪ��\n");
		printf("4. �ж϶����Ƿ�Ϊ��\n");
		printf("5. ��ն���\n");
		printf("6. �������Ԫ��\n");
		printf("0. �˳�\n");
		printf("������ѡ�");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("������Ҫ��ӵ�Ԫ�أ�\n");
			get_data(&addData);
			key++;
			// ���������ǻ�ȡ�û���������ݣ�������洢�� data ��
			EnLQueue(Q, addData);
			system("pause");
			break;
		case 2:
			if (key==0)
			{
				printf("�ն��У��޷�����");
				break;
			}
			DeLQueue(Q); 
			key --;
			printf("���ӳɹ�\n");
			system("pause");
			break;
		case 3:
			if (key == 0)
			{
				printf("�ն��У��޷�����");
				system("pause");
				break;
			}
			if (GetHeadLQueue(Q, &data)==TRUE) 
			{
				// �����ȡ���Ķ�ͷԪ�� data
				printf("��ͷԪ��Ϊ��");
				LPrint(data);
			}
			system("pause");
			break;
		case 4:
			if (IsEmptyLQueue(Q)) {
				printf("����Ϊ��\n");
			}
			else {
				printf("���в�Ϊ��\n");
			}
			system("pause");
			break;
		case 5:
			if (key == 0)
			{
				printf("�ն��У��޷�����");
				system("pause");
				break;
			}
			ClearLQueue(Q); key = 0;
			system("pause");
			break;
		case 6:
			if (key == 0)
			{
				printf("�ն��У��޷�����");
				system("pause");
				break;
			}
			TraverseLQueue(Q,LPrint);
			system("pause");
			break;
		case 0:
			exit(0);
			printf("�˳�����\n");
			break;
		default:
			printf("��Чѡ��\n");
			system("pause");
		}

	} while (choice != 0);

	DestoryLQueue(Q);

	return 0;
}
