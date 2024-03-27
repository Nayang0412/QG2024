#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include"shop.h"
#include"menu.h"
#include"sell.h"
#include"goods.h"
Status addSell()  //��Ʒ
{
    int len;
    char ch;
    FILE* fp;
    GoodsLNode goods;

    while (1)
    {
        printf("||------------------------------------------||\n");
        printf("||    ���� 0 ��ȡ�����, ������ 6 λ����    ||\n");
        printf("||------------------------------------------||\n");
        printf("||    ��Ʒ��ţ� ");
        scanf("%d", &goods.ID);
        system("cls");  //����

        if (goods.ID == 0)  //���� 0 ������һ��
        {
            return 0;
        }

        if (goods.ID <= 100000 || goods.ID > 999999)  //������λ������
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
            printf("||------------------------------------------||\n");
            printf("||      ��Ÿ�ʽ����, ������ 6 λ����       ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //��ͣ
            system("cls");  //����
            continue;
        }
        else
        {
            break;  //�˺Ÿ�ʽ��ȷ
        }
    }

    while (1)
    {
        printf("||------------------------------------------||\n");
        printf("||     ���� 0 ��ȡ�����, 8 λ������ĸ      ||\n");
        printf("||------------------------------------------||\n");
        printf("||     ��Ʒ���ࣺ ");
        scanf("%s", goods.type);
        system("cls");  //����

        if (strcmp(goods.type, "0") == 0)  //���� 0 ������һ��
        {
            return 0;
        }

        len = strlen(goods.type);

        if (len >= 8)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
            printf("||------------------------------------------||\n");
            printf("||        �����ʽ����, 8 λ������ĸ        ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //��ͣ
            system("cls");  //����
            continue;
        }
        else
        {
            break;  //�˺Ÿ�ʽ��ȷ
        }
    }
    while (1)
    {
        printf("||------------------------------------------||\n");
        printf("||     ���� 0 ��ȡ�����, 8 λ������ĸ      ||\n");
        printf("||------------------------------------------||\n");
        printf("||     ��Ʒ���̣� ");
        scanf("%s", goods.shop);
        system("cls");  //����

        if (strcmp(goods.shop, "0") == 0)  //���� 0 ������һ��
        {
            return 0;
        }

        len = strlen(goods.shop);

        if (len >= 8)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
            printf("||------------------------------------------||\n");
            printf("||        �����ʽ����, 8 λ������ĸ        ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //��ͣ
            system("cls");  //����
            continue;
        }
        else
        {
            break;  //�˺Ÿ�ʽ��ȷ
        }
    }

    printf("||------------------------------------------||\n");
    printf("||    ��Ʒ����  ");
    scanf("%s", goods.name);
    system("cls");  //����

    printf("||------------------------------------------||\n");
    printf("||    ��Ʒ�۸�  ");
    scanf("%d", &goods.price);
    system("cls");  //����

    printf("||------------------------------------------||\n");
    printf("||    ��Ʒ��棺  ");
    scanf("%d", &goods.inventory);
    system("cls");  //����
    goods.sell = 0;


    fp = fopen("GOODS.txt", "a");  //ֻд��׷��
    file_open_error(fp);  //�ļ��Ƿ��ʧ��

    fprintf(fp, "%d\t%s\t%d\t%d\t%s\t%s\t%d\t\n", goods.ID, goods.type, goods.price, goods.inventory, goods.name, goods.shop, goods.sell);

    printf("||------------------------------------------||\n");
    printf("||             ��  ��  ��  ��               ||\n");
    printf("||------------------------------------------||\n");
    printf("|| ����      ����               �۸�    ���||\n");
    printf("|| %-8d%-7s%-15s%-8d%d||\n", goods.ID, goods.type, goods.name, goods.price, goods.inventory);
    printf("||��Ʒ���̣�%s                            ||\n", goods.shop);
    printf("||------------------------------------------||\n");
    system("pause");  //��ͣ
    system("cls");  //����

    fclose(fp);
    return SUCCESS;
}