#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include"shop.h"
#include"menu.h"
#include"sell.h"
#include"goods.h"
Status addSell()  //商品
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

    fprintf(fp, "%d\t%s\t%d\t%d\t%s\t%s\t%d\t\n", goods.ID, goods.type, goods.price, goods.inventory, goods.name, goods.shop, goods.sell);

    printf("||------------------------------------------||\n");
    printf("||             添  加  成  功               ||\n");
    printf("||------------------------------------------||\n");
    printf("|| 种类      名字               价格    库存||\n");
    printf("|| %-8d%-7s%-15s%-8d%d||\n", goods.ID, goods.type, goods.name, goods.price, goods.inventory);
    printf("||商品店铺：%s                            ||\n", goods.shop);
    printf("||------------------------------------------||\n");
    system("pause");  //暂停
    system("cls");  //清屏

    fclose(fp);
    return SUCCESS;
}