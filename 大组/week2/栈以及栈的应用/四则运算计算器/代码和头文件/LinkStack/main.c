# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include"Menu.h"
#include"LinkStack.h"

void main()
{
	
	int ch = 0;
	while (1)
	{
		system("cls");
		printf("------------------------------------\n");
		printf("         Main Menu         \n");
		printf("    1   ��׺ת��׺    \n");
		printf("    0   ��������      \n");
		printf("------------------------------------\n");
		printf("��������ѡ��Ĳ˵���<1, 0>:\n");
		scanf("%d",&ch);
		while (getchar() != '\n');
		switch (ch)
		{
		
		case 1:welcome();
			system("pause");
			   break;
	    case 0:
			exit(0);
		default:printf("������Ч");
			break;
		}
		
	}
}