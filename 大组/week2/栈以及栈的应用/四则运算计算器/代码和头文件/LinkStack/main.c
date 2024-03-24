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
		printf("    1   中缀转后缀    \n");
		printf("    0   结束程序啊      \n");
		printf("------------------------------------\n");
		printf("请输入你选择的菜单号<1, 0>:\n");
		scanf("%d",&ch);
		while (getchar() != '\n');
		switch (ch)
		{
		
		case 1:welcome();
			system("pause");
			   break;
	    case 0:
			exit(0);
		default:printf("输入无效");
			break;
		}
		
	}
}