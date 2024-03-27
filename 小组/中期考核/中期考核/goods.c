#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include"shop.h"
#include"menu.h"
#include"goods.h"
Status addProduct();//添加商品
Status deleteProduct();  //删除商品
Status addProduct()  //添加商品
{
    int len;
    char ch;
    FILE* fp;
    GoodsLNode goods;

    while (1)
    {
        printf("||------------------------------------------||\n");
        printf("||    输入 0 可取消添加, 请输入 6 位数字    ||\n");
        printf("||------------------------------------------||\n");
        printf("||    商品编号： ");
        scanf("%d", &goods.ID);
        system("cls");  //清屏

        if (goods.ID == 0)  //输入 0 返回上一级
        {
            return 0;
        }

        if (goods.ID <= 100000 || goods.ID > 999999)  //不是六位的数字
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
            printf("||------------------------------------------||\n");
            printf("||      编号格式错误, 请输入 6 位数字       ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //暂停
            system("cls");  //清屏
            continue;
        }
        else
        {
            break;  //账号格式正确
        }
    }

    while (1)
    {
        printf("||------------------------------------------||\n");
        printf("||     输入 0 可取消添加, 8 位以内字母      ||\n");
        printf("||------------------------------------------||\n");
        printf("||     商品种类： ");
        scanf("%s", goods.type);
        system("cls");  //清屏

        if (strcmp(goods.type, "0") == 0)  //输入 0 返回上一级
        {
            return 0;
        }

        len = strlen(goods.type);

        if (len >= 8)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
            printf("||------------------------------------------||\n");
            printf("||        种类格式错误, 8 位以内字母        ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //暂停
            system("cls");  //清屏
            continue;
        }
        else
        {
            break;  //账号格式正确
        }
    }
    while (1)
    {
        printf("||------------------------------------------||\n");
        printf("||     输入 0 可取消添加, 8 位以内字母      ||\n");
        printf("||------------------------------------------||\n");
        printf("||     商品店铺： ");
        scanf("%s", goods.shop);
        system("cls");  //清屏

        if (strcmp(goods.shop, "0") == 0)  //输入 0 返回上一级
        {
            return 0;
        }

        len = strlen(goods.shop);

        if (len >= 8)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
            printf("||------------------------------------------||\n");
            printf("||        种类格式错误, 8 位以内字母        ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //暂停
            system("cls");  //清屏
            continue;
        }
        else
        {
            break;  //账号格式正确
        }
    }

    printf("||------------------------------------------||\n");
    printf("||    商品名字  ");
    scanf("%s", goods.name);
    system("cls");  //清屏

    printf("||------------------------------------------||\n");
    printf("||    商品价格：  ");
    scanf("%d", &goods.price);
    system("cls");  //清屏

    printf("||------------------------------------------||\n");
    printf("||    商品库存：  ");
    scanf("%d", &goods.inventory);
    system("cls");  //清屏
    goods.sell = 0;
  

    fp = fopen("GOODS.txt", "a");  //只写，追加
    file_open_error(fp);  //文件是否打开失败

    fprintf(fp, "%d\t%s\t%d\t%d\t%s\t%s\t%d\t\n", goods.ID, goods.type, goods.price, goods.inventory, goods.name,goods.shop,goods.sell);

    printf("||------------------------------------------||\n");
    printf("||             添  加  成  功               ||\n");
    printf("||------------------------------------------||\n");
    printf("|| 种类      名字               价格    库存||\n");
    printf("|| %-8d%-7s%-15s%-8d%d||\n", goods.ID, goods.type, goods.name, goods.price, goods.inventory);
    printf("||商品店铺：%s                            ||\n",goods.shop);
    printf("||------------------------------------------||\n");
    system("pause");  //暂停
    system("cls");  //清屏

    fclose(fp);
    return SUCCESS;
}
Status deleteProduct()  //删除商品
{
    char ch;
    int i = 0;
    int ID;
    GoodsLNode* MP;  //商品
    GoodsLNode* tail;  //指向尾部的指针
    FILE* fp;  //文件指针

    MP = (GoodsLNode*)malloc(sizeof(GoodsLNode));  //申请动态内存
    if (MP == NULL)
    {
        printf("||------------------------------------------||\n");
        printf("||          内  存  申  请  失  败          ||\n");
        printf("||------------------------------------------||\n");
        exit(0);
    }

    MP->next = NULL;
    tail = MP;  //指向尾部的指针

    fp = fopen("GOODS.txt", "r");  //可读写，写时清除原本内容
    file_open_error(fp);  //文件是否打开失败

    while (1)
    {
        printf("||------------------------------------------||\n");
        printf("||    输入 0 可取消删除, 请输入 6 位数字    ||\n");
        printf("||------------------------------------------||\n");
        printf("||    商品编号： ");
        scanf("%d", &ID);
        system("cls");  //清屏

        if (ID == 0)  //输入 0 返回上一级
        {
            return;
        }

        if (ID <= 100000 || ID > 999999)  //不是六位的数字
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
            printf("||------------------------------------------||\n");
            printf("||      编号格式错误, 请输入 6 位数字       ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //暂停
            system("cls");  //清屏
            continue;
        }
        else
        {
            break;  //账号格式正确
        }
    }

    while (!feof(fp))  //fp==EOF 返回 1
    {
        GoodsLNode* p;  //存放数据的指针
        p = (GoodsLNode*)malloc(sizeof(GoodsLNode));  //申请动态内存
     
        if (p == NULL)
        {
            printf("||------------------------------------------||\n");
            printf("||          内  存  申  请  失  败          ||\n");
            printf("||------------------------------------------||\n");
            exit(0);
        }
        fscanf(fp, "%d\t%s\t%d\t%d\t%s\t%s\t%d\t\n", &p->ID, p->type, &p->price, &p->inventory, p->name, p->shop, &p->sell);


     

        if (ID == p->ID)
        {
            i = 1;  //删除计为 1
            continue;  //如果信息相同，则不接入链表
        }

        tail->next = p;  //接到表尾
        tail = p;  //循环至表尾
        tail->next = NULL;  //表尾表尾赋空
    }

    printf("||------------------------------------------||\n");
    if (i)
    {
        printf("||             删  除  成  功               ||\n");
    }
    else
    {
        printf("||         无该商品或商品编号错误           ||\n");
    }
    printf("||------------------------------------------||\n");
    system("pause");  //暂停
    system("cls");  //清屏

    fclose(fp);

    if (i == 0)  //摧毁指针，并且返回
    {
        prod_Destrong_List(&MP);  //销毁链表
        return;
    }

    fp = fopen("GOODS.txt", "w");  //可读写，写时清除原本内容
    file_open_error(fp);  //文件是否打开失败

    tail = MP->next;  //指向尾部的指针

    while (tail != NULL)
    {
        fprintf(fp, "%d\t%s\t%d\t%d\t%s\t%s\t%d\t\n", tail->ID, tail->type, tail->price, tail->inventory, tail->name, tail->shop, tail->sell);

        tail = tail->next;  //继续写入下一个
    }

    prod_Destrong_List(&MP);  //销毁链表
    fclose(fp);  //释放文件指针
}
void showInfo()  //展示所有商品信息
{
    FILE* fp;  //文件指针
    GoodsLNode goods;

    fp = fopen("GOODS.txt", "r");  //只读，避免被修改
    file_open_error(fp);  //文件是否打开失败

    printf("||------------------------------------------||\n");
    printf("|| 种类      名字               价格    库存||\n");
    while (!feof(fp))
    {
         //中转站
        fscanf(fp, "%d\t%s\t%d\t%d\t%s\t%s\t%d\t\n", &goods.ID, goods.type, &goods.price, &goods.inventory, goods.name, goods.shop, &goods.sell);

        printf("||------------------------------------------||\n");
        
        printf("|| %-8d%-7s%-15s%-8d%d||\n", goods.ID, goods.type, goods.name, goods.price, goods.inventory);
        printf("||商品店铺：%s                             ||\n", goods.shop);
        printf("||商品销量：%d                              ||\n", goods.sell);
        printf("||------------------------------------------||\n");
    }
    printf("||------------------------------------------||\n");

    fclose(fp);
}
void reviseProduct()  //修改商品
{

    char ch;
    int i = 0;
    int ID;
    GoodsLNode* MP;  //商品
    GoodsLNode* tail;  //指向尾部的指针针
    FILE* fp;  //文件指针

    MP = (GoodsLNode*)malloc(sizeof(GoodsLNode));  //申请动态内存
    if (MP == NULL)
    {
        printf("||------------------------------------------||\n");
        printf("||          内  存  申  请  失  败          ||\n");
        printf("||------------------------------------------||\n");
        exit(0);
    }

    MP->next = NULL;
    tail = MP;  //指向尾部的指针

    while (1)
    {
        printf("||------------------------------------------||\n");
        printf("||    输入 0 可取消修改, 请输入 6 位数字    ||\n");
        printf("||------------------------------------------||\n");
        printf("||    需改商品编号：");
        scanf("%d", &ID);
        system("cls");  //清屏

        if (ID == 0)  //输入 0 返回上一级
        {
            return;
        }

        if (ID <= 100000 || ID > 999999)  //不是六位的数字
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
            printf("||------------------------------------------||\n");
            printf("||      编号格式错误, 请输入 6 位数字       ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //暂停
            system("cls");  //清屏
            continue;
        }
        else
        {
            break;  //账号格式正确
        }
    }

    fp = fopen("GOODS.txt", "r");  //可读写
    file_open_error(fp);  //文件是否打开失败

    while (!feof(fp))  //fp==EOF 返回 1
    {
        GoodsLNode* p;  //存放数据的指针

        p = (GoodsLNode*)malloc(sizeof(GoodsLNode));  //申请动态内存
        if (p == NULL)
        {
            printf("||------------------------------------------||\n");
            printf("||          内  存  申  请  失  败          ||\n");
            printf("||------------------------------------------||\n");
            exit(0);
        }

        fscanf(fp, "%d\t%s\t%d\t%d\t%s\t%s\t%d\t\n", &p->ID, p->type, &p->price, &p->inventory,p->name, p->shop, &p->sell);


        if (ID == p->ID)  //编号相同
        {
            printf("||------------------------------------------||\n");
            printf("|| 种类      名字               价格    库存||\n");


                printf("||------------------------------------------||\n");

                printf("|| %-8d%-7s%-15s%-8d%d||\n", p->ID, p->type, p->name, p->price, p->inventory);
                printf("||商品店铺：%s                             ||\n", p->shop);
                printf("||商品销量：%d                              ||\n", p->sell);
                printf("||------------------------------------------||\n");
 
            int choice = 0;
            printf("||---------------------------------------------||\n");
            printf("||           【1】 修  改    种  类            ||\n");
            printf("||           【2】 修  改    价  格            ||\n");
            printf("||           【3】 修  改    编  号            ||\n");
            printf("||           【4】 修  改    库  存            ||\n");
            printf("||           【5】 修  改    名  字            ||\n");
            printf("||           【5】 修  改    店  铺            ||\n");
            printf("||           【0】 退  出    界  面            ||\n");
            printf("||---------------------------------------------||\n");
            printf("||    你的选择： ");
            scanf("%d", &choice);
            fflush(stdin);
            switch (choice)
            {
            case 1:
                printf("||------------------------------------------||\n");
                printf("||            修  改  后  种  类            ||\n");
                printf("||------------------------------------------||\n");
                printf("||    商品种类： "); i = 1;
                scanf("%s", p->type); 
                break;
            case 2:      
                printf("||------------------------------------------||\n");
                printf("||            修  改  后  价  格            ||\n");
                printf("||------------------------------------------||\n");
                printf("||    商品价格： "); i = 1;
                scanf("%d", &p->price);
                break;
            case 3:
                printf("||------------------------------------------||\n");
                printf("||            修  改  后  编  号            ||\n");
                printf("||------------------------------------------||\n");
                printf("||    商品编号： "); i = 1;
                scanf("%d", &p->ID);
                break;
            case 4:
                printf("||------------------------------------------||\n");
                printf("||            修  改  后  库  存            ||\n");
                printf("||------------------------------------------||\n");
                printf("||    商品库存： ");
                scanf("%d", &p->inventory); i = 1;
                break;
            case 5:
                printf("||------------------------------------------||\n");
                printf("||            修  改  后  名  字            ||\n");
                printf("||------------------------------------------||\n");
                printf("||    商品名字： ");
                scanf("%s", p->name); i = 1;
                break;
            case 6:
                printf("||------------------------------------------||\n");
                printf("||            修  改  后  店  铺            ||\n");
                printf("||------------------------------------------||\n");
                printf("||    商品店铺： ");
                scanf("%s", p->shop); i = 1;
                break;
            case 0:break; system("pause");
            default:  
                printf("||------------------------------------------||\n");
                printf("||             输   入   无   效            ||\n");
                printf("||------------------------------------------||\n");
                printf("||    你的选择： ");
                scanf("%d", &choice); break;
            }

            system("cls");  //清屏
            
        }

        tail->next = p;  //接到表尾
        tail = p;  //循环至表尾
        tail->next = NULL;  //表尾表尾赋空
    }

    printf("||------------------------------------------||\n");
    if (i==1)
    {
        printf("||             修  改  成  功               ||\n");
    }
    else
    {
        printf("||         无该商品或商品编号错误           ||\n");
    }
    printf("||------------------------------------------||\n");
    system("pause");  //暂停
    system("cls");  //清屏

    fclose(fp);  //关闭文件

    if (i == 0)  //销毁链表，并且返回
    {
        prod_Destrong_List(&MP);
        return;
    }

    fp = fopen("GOODS.txt", "w");  //可读写，写时清除原本内容
    file_open_error(fp);  //文件是否打开失败

    tail = MP->next;  //指向尾部的指针

    while (tail != NULL)
    {
        fprintf(fp, "%d\t%s\t%d\t%d\t%s\t%s\t%d\t\n", tail->ID, tail->type, tail->price, tail->inventory, tail->name, tail->shop, tail->sell);
        tail = tail->next;  //继续写入下一个
    }

    prod_Destrong_List(&MP);  //销毁链表
    fclose(fp);  //释放文件指针
}