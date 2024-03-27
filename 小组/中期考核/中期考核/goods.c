#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include"shop.h"
#include"menu.h"
#include"goods.h"
Status addProduct();//�����Ʒ
Status deleteProduct();  //ɾ����Ʒ
Status addProduct()  //�����Ʒ
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

    fprintf(fp, "%d\t%s\t%d\t%d\t%s\t%s\t%d\t\n", goods.ID, goods.type, goods.price, goods.inventory, goods.name,goods.shop,goods.sell);

    printf("||------------------------------------------||\n");
    printf("||             ��  ��  ��  ��               ||\n");
    printf("||------------------------------------------||\n");
    printf("|| ����      ����               �۸�    ���||\n");
    printf("|| %-8d%-7s%-15s%-8d%d||\n", goods.ID, goods.type, goods.name, goods.price, goods.inventory);
    printf("||��Ʒ���̣�%s                            ||\n",goods.shop);
    printf("||------------------------------------------||\n");
    system("pause");  //��ͣ
    system("cls");  //����

    fclose(fp);
    return SUCCESS;
}
Status deleteProduct()  //ɾ����Ʒ
{
    char ch;
    int i = 0;
    int ID;
    GoodsLNode* MP;  //��Ʒ
    GoodsLNode* tail;  //ָ��β����ָ��
    FILE* fp;  //�ļ�ָ��

    MP = (GoodsLNode*)malloc(sizeof(GoodsLNode));  //���붯̬�ڴ�
    if (MP == NULL)
    {
        printf("||------------------------------------------||\n");
        printf("||          ��  ��  ��  ��  ʧ  ��          ||\n");
        printf("||------------------------------------------||\n");
        exit(0);
    }

    MP->next = NULL;
    tail = MP;  //ָ��β����ָ��

    fp = fopen("GOODS.txt", "r");  //�ɶ�д��дʱ���ԭ������
    file_open_error(fp);  //�ļ��Ƿ��ʧ��

    while (1)
    {
        printf("||------------------------------------------||\n");
        printf("||    ���� 0 ��ȡ��ɾ��, ������ 6 λ����    ||\n");
        printf("||------------------------------------------||\n");
        printf("||    ��Ʒ��ţ� ");
        scanf("%d", &ID);
        system("cls");  //����

        if (ID == 0)  //���� 0 ������һ��
        {
            return;
        }

        if (ID <= 100000 || ID > 999999)  //������λ������
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

    while (!feof(fp))  //fp==EOF ���� 1
    {
        GoodsLNode* p;  //������ݵ�ָ��
        p = (GoodsLNode*)malloc(sizeof(GoodsLNode));  //���붯̬�ڴ�
     
        if (p == NULL)
        {
            printf("||------------------------------------------||\n");
            printf("||          ��  ��  ��  ��  ʧ  ��          ||\n");
            printf("||------------------------------------------||\n");
            exit(0);
        }
        fscanf(fp, "%d\t%s\t%d\t%d\t%s\t%s\t%d\t\n", &p->ID, p->type, &p->price, &p->inventory, p->name, p->shop, &p->sell);


     

        if (ID == p->ID)
        {
            i = 1;  //ɾ����Ϊ 1
            continue;  //�����Ϣ��ͬ���򲻽�������
        }

        tail->next = p;  //�ӵ���β
        tail = p;  //ѭ������β
        tail->next = NULL;  //��β��β����
    }

    printf("||------------------------------------------||\n");
    if (i)
    {
        printf("||             ɾ  ��  ��  ��               ||\n");
    }
    else
    {
        printf("||         �޸���Ʒ����Ʒ��Ŵ���           ||\n");
    }
    printf("||------------------------------------------||\n");
    system("pause");  //��ͣ
    system("cls");  //����

    fclose(fp);

    if (i == 0)  //�ݻ�ָ�룬���ҷ���
    {
        prod_Destrong_List(&MP);  //��������
        return;
    }

    fp = fopen("GOODS.txt", "w");  //�ɶ�д��дʱ���ԭ������
    file_open_error(fp);  //�ļ��Ƿ��ʧ��

    tail = MP->next;  //ָ��β����ָ��

    while (tail != NULL)
    {
        fprintf(fp, "%d\t%s\t%d\t%d\t%s\t%s\t%d\t\n", tail->ID, tail->type, tail->price, tail->inventory, tail->name, tail->shop, tail->sell);

        tail = tail->next;  //����д����һ��
    }

    prod_Destrong_List(&MP);  //��������
    fclose(fp);  //�ͷ��ļ�ָ��
}
void showInfo()  //չʾ������Ʒ��Ϣ
{
    FILE* fp;  //�ļ�ָ��
    GoodsLNode goods;

    fp = fopen("GOODS.txt", "r");  //ֻ�������ⱻ�޸�
    file_open_error(fp);  //�ļ��Ƿ��ʧ��

    printf("||------------------------------------------||\n");
    printf("|| ����      ����               �۸�    ���||\n");
    while (!feof(fp))
    {
         //��תվ
        fscanf(fp, "%d\t%s\t%d\t%d\t%s\t%s\t%d\t\n", &goods.ID, goods.type, &goods.price, &goods.inventory, goods.name, goods.shop, &goods.sell);

        printf("||------------------------------------------||\n");
        
        printf("|| %-8d%-7s%-15s%-8d%d||\n", goods.ID, goods.type, goods.name, goods.price, goods.inventory);
        printf("||��Ʒ���̣�%s                             ||\n", goods.shop);
        printf("||��Ʒ������%d                              ||\n", goods.sell);
        printf("||------------------------------------------||\n");
    }
    printf("||------------------------------------------||\n");

    fclose(fp);
}
void reviseProduct()  //�޸���Ʒ
{

    char ch;
    int i = 0;
    int ID;
    GoodsLNode* MP;  //��Ʒ
    GoodsLNode* tail;  //ָ��β����ָ����
    FILE* fp;  //�ļ�ָ��

    MP = (GoodsLNode*)malloc(sizeof(GoodsLNode));  //���붯̬�ڴ�
    if (MP == NULL)
    {
        printf("||------------------------------------------||\n");
        printf("||          ��  ��  ��  ��  ʧ  ��          ||\n");
        printf("||------------------------------------------||\n");
        exit(0);
    }

    MP->next = NULL;
    tail = MP;  //ָ��β����ָ��

    while (1)
    {
        printf("||------------------------------------------||\n");
        printf("||    ���� 0 ��ȡ���޸�, ������ 6 λ����    ||\n");
        printf("||------------------------------------------||\n");
        printf("||    �����Ʒ��ţ�");
        scanf("%d", &ID);
        system("cls");  //����

        if (ID == 0)  //���� 0 ������һ��
        {
            return;
        }

        if (ID <= 100000 || ID > 999999)  //������λ������
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

    fp = fopen("GOODS.txt", "r");  //�ɶ�д
    file_open_error(fp);  //�ļ��Ƿ��ʧ��

    while (!feof(fp))  //fp==EOF ���� 1
    {
        GoodsLNode* p;  //������ݵ�ָ��

        p = (GoodsLNode*)malloc(sizeof(GoodsLNode));  //���붯̬�ڴ�
        if (p == NULL)
        {
            printf("||------------------------------------------||\n");
            printf("||          ��  ��  ��  ��  ʧ  ��          ||\n");
            printf("||------------------------------------------||\n");
            exit(0);
        }

        fscanf(fp, "%d\t%s\t%d\t%d\t%s\t%s\t%d\t\n", &p->ID, p->type, &p->price, &p->inventory,p->name, p->shop, &p->sell);


        if (ID == p->ID)  //�����ͬ
        {
            printf("||------------------------------------------||\n");
            printf("|| ����      ����               �۸�    ���||\n");


                printf("||------------------------------------------||\n");

                printf("|| %-8d%-7s%-15s%-8d%d||\n", p->ID, p->type, p->name, p->price, p->inventory);
                printf("||��Ʒ���̣�%s                             ||\n", p->shop);
                printf("||��Ʒ������%d                              ||\n", p->sell);
                printf("||------------------------------------------||\n");
 
            int choice = 0;
            printf("||---------------------------------------------||\n");
            printf("||           ��1�� ��  ��    ��  ��            ||\n");
            printf("||           ��2�� ��  ��    ��  ��            ||\n");
            printf("||           ��3�� ��  ��    ��  ��            ||\n");
            printf("||           ��4�� ��  ��    ��  ��            ||\n");
            printf("||           ��5�� ��  ��    ��  ��            ||\n");
            printf("||           ��5�� ��  ��    ��  ��            ||\n");
            printf("||           ��0�� ��  ��    ��  ��            ||\n");
            printf("||---------------------------------------------||\n");
            printf("||    ���ѡ�� ");
            scanf("%d", &choice);
            fflush(stdin);
            switch (choice)
            {
            case 1:
                printf("||------------------------------------------||\n");
                printf("||            ��  ��  ��  ��  ��            ||\n");
                printf("||------------------------------------------||\n");
                printf("||    ��Ʒ���ࣺ "); i = 1;
                scanf("%s", p->type); 
                break;
            case 2:      
                printf("||------------------------------------------||\n");
                printf("||            ��  ��  ��  ��  ��            ||\n");
                printf("||------------------------------------------||\n");
                printf("||    ��Ʒ�۸� "); i = 1;
                scanf("%d", &p->price);
                break;
            case 3:
                printf("||------------------------------------------||\n");
                printf("||            ��  ��  ��  ��  ��            ||\n");
                printf("||------------------------------------------||\n");
                printf("||    ��Ʒ��ţ� "); i = 1;
                scanf("%d", &p->ID);
                break;
            case 4:
                printf("||------------------------------------------||\n");
                printf("||            ��  ��  ��  ��  ��            ||\n");
                printf("||------------------------------------------||\n");
                printf("||    ��Ʒ��棺 ");
                scanf("%d", &p->inventory); i = 1;
                break;
            case 5:
                printf("||------------------------------------------||\n");
                printf("||            ��  ��  ��  ��  ��            ||\n");
                printf("||------------------------------------------||\n");
                printf("||    ��Ʒ���֣� ");
                scanf("%s", p->name); i = 1;
                break;
            case 6:
                printf("||------------------------------------------||\n");
                printf("||            ��  ��  ��  ��  ��            ||\n");
                printf("||------------------------------------------||\n");
                printf("||    ��Ʒ���̣� ");
                scanf("%s", p->shop); i = 1;
                break;
            case 0:break; system("pause");
            default:  
                printf("||------------------------------------------||\n");
                printf("||             ��   ��   ��   Ч            ||\n");
                printf("||------------------------------------------||\n");
                printf("||    ���ѡ�� ");
                scanf("%d", &choice); break;
            }

            system("cls");  //����
            
        }

        tail->next = p;  //�ӵ���β
        tail = p;  //ѭ������β
        tail->next = NULL;  //��β��β����
    }

    printf("||------------------------------------------||\n");
    if (i==1)
    {
        printf("||             ��  ��  ��  ��               ||\n");
    }
    else
    {
        printf("||         �޸���Ʒ����Ʒ��Ŵ���           ||\n");
    }
    printf("||------------------------------------------||\n");
    system("pause");  //��ͣ
    system("cls");  //����

    fclose(fp);  //�ر��ļ�

    if (i == 0)  //�����������ҷ���
    {
        prod_Destrong_List(&MP);
        return;
    }

    fp = fopen("GOODS.txt", "w");  //�ɶ�д��дʱ���ԭ������
    file_open_error(fp);  //�ļ��Ƿ��ʧ��

    tail = MP->next;  //ָ��β����ָ��

    while (tail != NULL)
    {
        fprintf(fp, "%d\t%s\t%d\t%d\t%s\t%s\t%d\t\n", tail->ID, tail->type, tail->price, tail->inventory, tail->name, tail->shop, tail->sell);
        tail = tail->next;  //����д����һ��
    }

    prod_Destrong_List(&MP);  //��������
    fclose(fp);  //�ͷ��ļ�ָ��
}