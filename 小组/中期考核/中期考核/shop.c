#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include"shop.h"
#include"menu.h"

#define str "0123456789abcdefghijklmnopqrstuvwxyz"  //��ĸ������
Status InitList();//�̼ҵ�¼
Status DeleteList();//ɾ���ڵ�
Status SearchList(ShopLinkedList* L, ShopLNode*e);//�ҵ�����Ľڵ�
Status InsertList(ShopLinkedList*L, ShopLNode* q);//�����½ڵ�

  
void revisePassword();//ͨ�������޸��̻�����
Status reviseSecertPassword();//ͨ���ܱ��޸��̻�����


Status InitList()//�̼ҵ�¼
{
    ShopLNode*ad;//�̼��˺�
	char ch, sel;
	int flag = 0;//��¼�Ƿ��ѯ�ɹ�
	FILE* fp;
	int account;//�˺�
	char password[20];//����
	int len_1, len_2;//���볤��


	while (1)
	{
		while (1) 
		{
			printf("||------------------------------------------||\n");
			printf("||        ��0ȡ����¼������6λ���˺�        ||\n");
			printf("||------------------------------------------||\n");

			fflush(stdin);
			scanf("%d",&account);
			
			system("cls");  //����
			if (account == 0)  //���� 0 ������һ��
			{
				return;
			}

			else if (account <= 100000 || account > 999999)  //������λ������
			{
				while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
				printf("||------------------------------------------||\n");
				printf("||      �˺Ÿ�ʽ����, ������ 6 λ����       ||\n");
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
            printf("||   ���� 0 ��ȡ����¼, 9-15 λ��ĸ������   ||\n");
            printf("||------------------------------------------||\n");
            printf("||  �̼����룺");
            scanf("%s", password);
            system("cls");  //����
            if (strcmp(password, "0") == 0)
            {
                return;
            }
            len_1 = strlen(password);
            len_2 = strspn(password, str);

            if (len_1 < 9 || len_1>15 || len_2 < 9 || len_2>15)
            {
                while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
                printf("||------------------------------------------||\n");
                printf("||     �����ʽ����, 9-15 λ��ĸ������      ||\n");
                printf("||------------------------------------------||\n");
                system("pause");  //��ͣ
                system("cls");  //����
                continue;
            }
            else
            {
                break;

            }
        }
            fp = fopen("SHOP.txt", "r+");  //���ļ�
            file_open_error(fp);  //�ļ��Ƿ��ʧ��
            ad = (ShopLNode*)malloc(sizeof(ShopLNode));
            while (!feof(fp))  //�ļ�ָ�뵽��ĩβ�򷵻� 1
            {
                
                fscanf(fp, "%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t\n", &ad->account, ad->username,ad->secert, ad->secertquestion, ad->secertanswer, &ad->income,&ad->order,&ad->money);
                if (account == ad->account && strcmp(password, ad->secert) == 0)  //�˺����붼��ͬ
                {
                    flag = 1;  //��¼�ɹ�
                    break;
                }
                else
                {
                    break;
                }
            }

            if (flag == 0)
            {
                int key = 0;
                printf("||----------------------------------------------------------||\n");
                printf("||       �˺Ż��������, ���������� ,��������������         ||\n");
                printf("||       ����1�������������� �������࣬������������         ||\n");
                printf("||----------------------------------------------------------||\n");
                scanf("%d",&key);
                if (key==1)
                {
                  


                        system("cls");  //����
                        printf("||------------------------------||\n");
                        printf("||       ��������������         ||\n");
                        printf("||------------------------------||\n");
                        system("cls");  //����
                        if(reviseSecertPassword()==SUCCESS)
                        system("cls");  //����
                        system("pause");  //��ͣ
                        
                        continue;
                    
                }
                else
                {
                    system("pause");  //��ͣ
                    system("cls");  //����
                    fclose(fp);  //�ر��ļ�
                    continue;
                }

            }

            printf("||------------------------------------------||\n");
            printf("||              ��  ½  ��  ��              ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //��ͣ
            system("cls");  //����

           /* while (1)
            {
                printf("||------------------------------------------||\n");
                printf("||            ��  ��    ��  ��              ||\n");
                printf("||------------------------------------------||\n");
                printf("||          ��1��չʾ������Ʒ��Ϣ           ||\n");
                printf("||          ��2�������Ʒ                   ||\n");
                printf("||          ��3��ɾ����Ʒ                   ||\n");
                printf("||          ��4���޸���Ʒ��Ϣ               ||\n");
                printf("||          ��5���������                   ||\n");
                printf("||          ��6����ѯ����                   ||\n");
                printf("||          ��7���˻�����                   ||\n");
                printf("||          ��0���˳���¼                   ||\n");
                printf("||------------------------------------------||\n");
                printf("||   ��ѡ�� ");
                while ((sel = getchar()) == '\n');  //��������ʲô��ֻ��ȡ��һ���ַ�(������)
                while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����(��յ�һ���ַ����ÿһ���ַ�)
                system("cls");  //����

                switch (sel)
                {
                case '1':
                    showInfo();  //չʾ������Ʒ��Ϣ
                    system("pause");
                    system("cls");
                    break;

                case '2':
                    addProduct();  //�����Ʒ
                    break;

                case '3':
                    deleteProduct();  //ɾ����Ʒ
                    break;

                case '4':
                    reviseProduct();  //�޸���Ʒ�۸�
                    break;

                case '5':
                    merchandiseDiscount();  //�����Ʒ�ۿ�
                    break;

                case '6':
                    SearrchCt();  //��ѯ�˿�
                    break;

                case '0':
                    fclose(fp);  //�ر��ļ�
                    return;  //������һ��

                default:
                    input_error();  //���������ʾ
                }
            }*/
        
    }

    return SUCCESS;

		}
Status InsertList()//�̼�ע��
{

    

    char ch;
    ShopLNode ad;  //����Ա a_1
    FILE* fp;
    int len_1, len_2;  //��¼�������, ��¼����Ϸ��ַ�����

    while (1)
    {
        printf("||-----------------�û���ע��---------------||\n");
        printf("||------------------------------------------||\n");
        printf("||     ���� 0 ���˳�ע��, 8 λ������ĸ      ||\n");
        printf("||------------------------------------------||\n");
        printf("||  �̼��û����� ");
        scanf("%s", ad.username);
        system("cls");  //����

        if (strcmp(ad.username, "0") == 0)  // 0 �˳�ע��
        {
            return 0;
        }

        len_1 = strlen(ad.username);

        if (len_1 < 8)
        {
            break;
        }
        else
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
            printf("||------------------------------------------||\n");
            printf("||       ������ʽ����ȷ, 8 λ������ĸ       ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //��ͣ
            system("cls");  //����
        }
    }

    while (1)
    {
        printf("||----------------�˻�����------------------||\n");
        printf("||------------------------------------------||\n");
        printf("||     ���� 0 ���˳�ע��, 6λ����           ||\n");
        printf("||------------------------------------------||\n");
        printf("||   �̼��˻���  ");
        scanf("%d", &ad.account);
        system("cls");  //����

        if (ad.account==0)
        {
            return 0;
        }

 

        if (ad.account < 111111 || ad.account>999999)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
            printf("||------------------------------------------||\n");
            printf("||             �˺Ÿ�ʽ����, 6λ����        ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //��ͣ
            system("cls");  //����
            continue;
        }
        else
        {
            break;
        }
    }



    while (1)
    {
        printf("||----------------��������------------------||\n");
        printf("||------------------------------------------||\n");
        printf("||   ���� 0 ���˳�ע��, 9-15 λ��ĸ������   ||\n");
        printf("||------------------------------------------||\n");
        printf("||   �̼����룺  ");
        scanf("%s", ad.secert);
        system("cls");  //����

        if (strcmp(ad.secert, "0") == 0)
        {
            return;
        }

        len_1 = strlen(ad.secert);
        len_2 = strspn(ad.secert, str);

        if (len_1 < 9 || len_1>15 || len_2 < 9 || len_2>15)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
            printf("||------------------------------------------||\n");
            printf("||     �����ʽ����, 9-15 λ��ĸ������      ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //��ͣ
            system("cls");  //����
            continue;
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        printf("||-------------------�ܱ�����---------------||\n");
        printf("||------------------------------------------||\n");
        printf("||   ���� 0 ���˳�ע��, 9-19 λ��ĸ������   ||\n");
        printf("||------------------------------------------||\n");
        printf("||   �̼��ܱ���  ");
        scanf("%s", ad.secertquestion);
        system("cls");  //����

        if (strcmp(ad.secertquestion, "0") == 0)
        {
            return 0;
        }

        len_1 = strlen(ad.secertquestion);
        len_2 = strspn(ad.secertquestion, str);

        if (len_1 < 9 || len_1>19 || len_2 < 9 || len_2>19)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
            printf("||------------------------------------------||\n");
            printf("||     �ܱ���ʽ����, 9-19 λ��ĸ������      ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //��ͣ
            system("cls");  //����
            continue;
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        rintf("||-------------------�ܱ���������------------||\n");
        printf("||------------------------------------------||\n");
        printf("||   ���� 0 ���˳�ע��, 9-19 λ��ĸ������   ||\n");
        printf("||------------------------------------------||\n");
        printf("||   �̼��ܱ����룺  ");
        scanf("%s", ad.secertanswer);
        system("cls");  //����

        if (strcmp(ad.secertanswer, "0") == 0)
        {
            return 0;
        }

        len_1 = strlen(ad.secertanswer);
        len_2 = strspn(ad.secertanswer, str);

        if (len_1 < 9 || len_1>19 || len_2 < 9 || len_2>19)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
            printf("||------------------------------------------||\n");
            printf("||     �ܱ���ʽ����, 9-19 λ��ĸ������      ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //��ͣ
            system("cls");  //����
            continue;
        }
        else
        {
            break;
        }
    }

  ///�̼����ݳ�ʼ��  
    ad.income = 0;
    ad.money = 0;
    ad.order = 0;

    fp = fopen("SHOP.txt", "a");  //ֻд����ĩβ���
    file_open_error(fp);  //�ļ��Ƿ��ʧ��

    
    fprintf(fp, "%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t\n", ad.account, ad.username, ad.secert, ad.secertquestion, ad.secertanswer, ad.income, ad.order, ad.money);


    printf("||------------------------------------------||\n");
    printf("||             ע  ��  ��  ��               ||\n");
    printf("||------------------------------------------||\n");
    printf("|| �˺ţ�%-8d  ���룺%-16s   ||\n", ad.account, ad.secert);
    printf("|| �û���: %-8s                 ||\n", ad.username);
    printf("||------------------------------------------||\n");
    system("pause");  //��ͣ
    system("cls");  //����

    fclose(fp);

    return SUCCESS;
}
void revisePassword()//�޸��̻�����

{
    char ch;
    int i = 0;
    int account;
    int len_1, len_2;  //��¼�������, ��¼����Ϸ��ַ�����
    char password[size];
    char password_1[size], password_2[size];
    FILE* fp;  //�ļ�ָ��
    ShopLNode* A;  //����Ա
    ShopLNode* tail;  //ָ��β����ָ��

    while (1)
    {
        printf("||------------------------------------------||\n");
        printf("||   ���� 0 ����ȡ���޸�, ������ 6 λ����   ||\n");
        printf("||------------------------------------------||\n");
        printf("||   �̼��˺ţ�  ");
        scanf("%d", &account);
        system("cls");  //����

        if (account == 0)
        {
            return;
        }

        if (account <= 100000 || account > 999999)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
            printf("||------------------------------------------||\n");
            printf("||      �˺Ÿ�ʽ����, ������ 6 λ����       ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //��ͣ
            system("cls");  //����
            continue;
        }
        else
        {
            break;
        }
    }


    while (1)
    {
        printf("||------------------------------------------||\n");
        printf("||   ���� 0 ��ȡ���޸�, 9-15 λ��ĸ������   ||\n");
        printf("||------------------------------------------||\n");
        printf("||   �̼����룺  ");
        scanf("%s", password);
        system("cls");  //����

        if (strcmp(password, "0") == 0)
        {
            return;
        }

        len_1 = strlen(password);
        len_2 = strspn(password, str);

        if (len_1 < 9 || len_1>15 || len_2 < 9 || len_2>15)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
            printf("||------------------------------------------||\n");
            printf("||     �����ʽ����, 9-15 λ��ĸ������      ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //��ͣ
            system("cls");  //����
            continue;
        }
        else
        {
            break;
        }
    }

    fp = fopen("SHOP.txt", "r");  //�ɶ�д
    file_open_error(fp);  //�ļ��Ƿ��ʧ��

    A = (ShopLNode*)malloc(sizeof(ShopLNode));  //���붯̬�ڴ�
    malloc_defeat(A);  //�ڴ��Ƿ�����ʧ��

    A->next = NULL;
    tail = A;  //ָ��β����ָ��

    while (!feof(fp))  //fp==EOF ���� 1
    {
        ShopLNode* p;  //������ݵ�ָ��

        p = (ShopLNode*)malloc(sizeof(ShopLNode));  //���붯̬�ڴ�
        malloc_defeat(p);  //�ڴ��Ƿ�����ʧ��

        
        fscanf(fp, "%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t\n", &p->account, p->username, p->secert, p->secertquestion, p->secertanswer, &p->income, &p->order, &p->money);

        while ((account == p->account) && (strcmp(password, p->secert) == 0))  //�˺�������ͬ
        {
            while (1)
            {
                printf("||------------------------------------------||\n");
                printf("||   ���� 0 ��ȡ���޸�, 9-15 λ��ĸ������   ||\n");
                printf("||------------------------------------------||\n");
                printf("||   �����룺  ");
                scanf("%s", password_1);
                system("cls");  //����

                if (strcmp(password_1, "0") == 0)
                {
                    return;
                }

                len_1 = strlen(password_1);
                len_2 = strspn(password_1, str);

                if (len_1 < 9 || len_1>15 || len_2 < 9 || len_2>15)
                {
                    while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
                    printf("||------------------------------------------||\n");
                    printf("||    �������ʽ����, 9-15 λ��ĸ������     ||\n");
                    printf("||------------------------------------------||\n");
                    system("pause");  //��ͣ
                    system("cls");  //����
                    continue;
                }
                else
                {
                    break;
                }
            }

            while (1)
            {
                printf("||------------------------------------------||\n");
                printf("||   ���� 0 ��ȡ���޸�, 9-15 λ��ĸ������   ||\n");
                printf("||------------------------------------------||\n");
                printf("||   ���ٴ����������룺 ");
                scanf("%s", password_2);
                system("cls");  //����

                if (strcmp(password_2, "0") == 0)
                {
                    return;
                }

                len_1 = strlen(password_2);
                len_2 = strspn(password_2, str);

                if (len_1 < 9 || len_1>15 || len_2 < 9 || len_2>15)
                {
                    while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
                    printf("||------------------------------------------||\n");
                    printf("||    �������ʽ����, 9-15 λ��ĸ������     ||\n");
                    printf("||------------------------------------------||\n");
                    system("pause");  //��ͣ
                    system("cls");  //����
                    continue;
                }
                else
                {
                    break;
                }
            }

            if (strcmp(password_1, password_2) == 0)
            {
                i = 1;
                strcpy(p->secert, password_2);
            }
            else
            {
                printf("||------------------------------------------||\n");
                printf("||            ��  ��  ��  ��  ͬ            ||\n");
                printf("||------------------------------------------||\n");
                system("pause");  //��ͣ
                system("cls");  //����
            }
        }

        tail->next = p;  //�ӵ���β
        tail = p;  //ѭ������β
        tail->next = NULL;  //��β��β����
    }

    printf("||------------------------------------------||\n");
    if (i)
    {
        printf("||             ��  ��  ��  ��               ||\n");
    }
    else
    {
        printf("||       �޸ù���Ա�����Ա��Ϣ����         ||\n");
    }
    printf("||------------------------------------------||\n");
    system("pause");  //��ͣ
    system("cls");  //����

    fclose(fp);

    if (i == 0)
    {
        admi_Destrong_List(&A);  //�ݻ�����
        return;
    }

    fp = fopen("SHOP.txt", "w");  //�ɶ�д��дʱ���ԭ������
    file_open_error(fp);  //�ļ��Ƿ��ʧ��

    tail = A->next;  //ָ��β����ָ��

    while (tail != NULL)
    {
        fprintf(fp, "%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t\n", tail->account, tail->username, tail->secert, tail->secertquestion, tail->secertanswer, tail->income, tail->order, tail->money);
        tail = tail->next;  //����д����һ��
    }

    admi_Destrong_List(A);  //�ݻ�����
    fclose(fp);  //�ͷ��ļ�ָ��
}
Status reviseSecertPassword()
{

    //�޸��̻�����

    {
        char ch;
        int i = 0;
        int account;
        int len_1, len_2;  //��¼�������, ��¼����Ϸ��ַ�����
        char password[size];
        char password_1[size], password_2[size];
        FILE* fp;  //�ļ�ָ��
        ShopLNode* A;  //����Ա
        ShopLNode* tail;  //ָ��β����ָ��
        int key = 0;
        while (1)
        {
            printf("||------------------------------------------||\n");
            printf("||   ���� 0 ����ȡ���޸�, ������ 6 λ����   ||\n");
            printf("||------------------------------------------||\n");
            printf("||   �̼��˺ţ�  ");
            scanf("%d", &account);
            system("cls");  //����

            if (account == 0)
            {
                return;
            }

            if (account <= 100000 || account > 999999)
            {
                while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
                printf("||------------------------------------------||\n");
                printf("||      �˺Ÿ�ʽ����, ������ 6 λ����       ||\n");
                printf("||------------------------------------------||\n");
                system("pause");  //��ͣ
                system("cls");  //����
                continue;
            }
            else
            {
                break;
            }
        }


       
        fp = fopen("SHOP.txt", "r");  //�ɶ�д
        file_open_error(fp);  //�ļ��Ƿ��ʧ��

        A = (ShopLNode*)malloc(sizeof(ShopLNode));  //���붯̬�ڴ�
        malloc_defeat(A);  //�ڴ��Ƿ�����ʧ��

        A->next = NULL;
        tail = A;  //ָ��β����ָ��

        while (!feof(fp))  //fp==EOF ���� 1
        {
            ShopLNode* p;  //������ݵ�ָ��

            p = (ShopLNode*)malloc(sizeof(ShopLNode));  //���붯̬�ڴ�
            malloc_defeat(p);  //�ڴ��Ƿ�����ʧ��


            fscanf(fp, "%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t\n", &p->account, p->username, p->secert, p->secertquestion, p->secertanswer, &p->income, &p->order, &p->money);
            


                while ((account == p->account))  //�˺���ͬ
                {
                    if (key == 0)
                  {
                    char answer[size];
                    while (1)
                    {

                        printf("||---------------------------------------------||\n");
                        printf("||       ����0ȡ���޸ģ��ش��ܱ�����           ||\n");
                        printf("||�ܱ�����:%s                              ||\n", p->secertquestion);
                        printf("||---------------------------------------------||\n");
                        printf("||   �ܱ��𰸣�  ");
                        scanf("%s", answer);
                        system("cls");
                        if (strcmp(answer, "0") == 0)
                        {
                            printf("||------------------------------------------||\n");
                            printf("||                  ���ؽ���                ||\n");
                            printf("||------------------------------------------||\n");
                            system("pause");
                            return ERROR;
                        }
                        if (strcmp(answer, p->secertanswer) == 0)
                        {
                            printf("||------------------------------------------||\n");
                            printf("||                  �ش���ȷ                ||\n");
                            printf("||------------------------------------------||\n");
                            system("pause");
                            break;
                        }
                        else
                        {
                            while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
                            printf("||------------------------------------------||\n");
                            printf("||                  �ش����                ||\n");
                            printf("||------------------------------------------||\n");
                            system("pause");  //��ͣ
                            system("cls");  //����
                            continue;
                        }
                   

                    }
                    while (1)
                    {
                        while (1)
                        {
                            printf("||------------------------------------------||\n");
                            printf("||   ���� 0 ��ȡ���޸�, 9-15 λ��ĸ������   ||\n");
                            printf("||------------------------------------------||\n");
                            printf("||   �����룺  ");
                            scanf("%s", password_1);
                            system("cls");  //����

                            if (strcmp(password_1, "0") == 0)
                            {
                                return;
                            }

                            len_1 = strlen(password_1);
                            len_2 = strspn(password_1, str);

                            if (len_1 < 9 || len_1>15 || len_2 < 9 || len_2>15)
                            {
                                while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
                                printf("||------------------------------------------||\n");
                                printf("||    �������ʽ����, 9-15 λ��ĸ������     ||\n");
                                printf("||------------------------------------------||\n");
                                system("pause");  //��ͣ
                                system("cls");  //����
                                continue;
                            }
                            else
                            {
                                break;
                            }
                        }

                        while (1)
                        {
                            printf("||------------------------------------------||\n");
                            printf("||   ���� 0 ��ȡ���޸�, 9-15 λ��ĸ������   ||\n");
                            printf("||------------------------------------------||\n");
                            printf("||   ���ٴ����������룺 ");
                            scanf("%s", password_2);
                            system("cls");  //����

                            if (strcmp(password_2, "0") == 0)
                            {
                                return;
                            }

                            len_1 = strlen(password_2);
                            len_2 = strspn(password_2, str);

                            if (len_1 < 9 || len_1>15 || len_2 < 9 || len_2>15)
                            {
                                while ((ch = getchar()) != '\n' && ch != EOF);  //��ջ�����
                                printf("||------------------------------------------||\n");
                                printf("||    �������ʽ����, 9-15 λ��ĸ������     ||\n");
                                printf("||------------------------------------------||\n");
                                system("pause");  //��ͣ
                                system("cls");  //����
                                continue;
                            }
                            else
                            {
                                break;
                            }
                        }

                        if (strcmp(password_1, password_2) == 0)
                        {
                            i = 1;
                            strcpy(p->secert, password_2);
                            key = 1;
                            break;
                        }
                        else
                        {
                            printf("||------------------------------------------||\n");
                            printf("||            ��  ��  ��  ��  ͬ            ||\n");
                            printf("||------------------------------------------||\n");
                            system("pause");  //��ͣ
                            system("cls");  //����
                        }
                    }
                
                    
                  }
                  if (key == 1)

                  {
                      break;
                  }
            }
            tail->next = p;  //�ӵ���β
            tail = p;  //ѭ������β
            tail->next = NULL;  //��β��β����
            
        }

        printf("||------------------------------------------||\n");
        if (i)
        {
            printf("||             ��  ��  ��  ��               ||\n");
        }
        else
        {
            printf("||       �޸��̼һ��̼���Ϣ����         ||\n");
        }
        printf("||------------------------------------------||\n");
        system("pause");  //��ͣ
        system("cls");  //����

        fclose(fp);

        if (i == 0)
        {
            admi_Destrong_List(&A);  //�ݻ�����
            return;
        }

        fp = fopen("SHOP.txt", "w");  //�ɶ�д��дʱ���ԭ������
        file_open_error(fp);  //�ļ��Ƿ��ʧ��

        tail = A->next;  //ָ��β����ָ��

        while (tail != NULL)
        {
            fprintf(fp, "%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t\n", tail->account, tail->username, tail->secert, tail->secertquestion, tail->secertanswer, tail->income, tail->order, tail->money);
            tail = tail->next;  //����д����һ��
        }

        admi_Destrong_List(&A);  //�ݻ�����
        fclose(fp);  //�ͷ��ļ�ָ��
        return SUCCESS;
    }
}