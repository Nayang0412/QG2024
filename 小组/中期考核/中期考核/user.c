#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include"shop.h"
#include"menu.h"
#include"goods.h"
#include"user.h"
#define str "0123456789abcdefghijklmnopqrstuvwxyz"  //字母和数字
Status admi_UserDestrong_List(UserLinkst* P)
{
    UserLNode* s = *P;

    UserLNode* q;
    if (NULL == s->next)
    {
        return ERROR;
    }
    while (s)
    {
        q = s;
        s = s->next;
        free(q);
    }
}
Status UserInitList()//用户登录
{
    UserLNode* ad;//用户账号
    char ch, sel;
    int flag = 0;//记录是否查询成功
    FILE* fp;
    int account;//账号
    char password[20];//密码
    int len_1, len_2;//密码长度


    while (1)
    {
        while (1)
        {
            printf("||------------------------------------------||\n");
            printf("||        输0取消登录，输入6位的账号        ||\n");
            printf("||------------------------------------------||\n");

            fflush(stdin);
            scanf("%d", &account);

            system("cls");  //清屏
            if (account == 0)  //输入 0 返回上一级
            {
                return;
            }

            else if (account <= 100000 || account > 999999)  //不是六位的数字
            {
                while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
                printf("||------------------------------------------||\n");
                printf("||      账号格式错误, 请输入 6 位数字       ||\n");
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
            printf("||   输入 0 可取消登录, 9-15 位字母或数字   ||\n");
            printf("||------------------------------------------||\n");
            printf("||  用户密码：");
            scanf("%s", password);
            system("cls");  //清屏
            if (strcmp(password, "0") == 0)
            {
                return;
            }
            len_1 = strlen(password);
            len_2 = strspn(password, str);

            if (len_1 < 9 || len_1>15 || len_2 < 9 || len_2>15)
            {
                while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
                printf("||------------------------------------------||\n");
                printf("||     密码格式错误, 9-15 位字母或数字      ||\n");
                printf("||------------------------------------------||\n");
                system("pause");  //暂停
                system("cls");  //清屏
                continue;
            }
            else
            {
                break;

            }
        }
        fp = fopen("USER.txt", "r+");  //打开文件
        file_open_error(fp);  //文件是否打开失败
        ad = (UserLNode*)malloc(sizeof(UserLNode));
        while (!feof(fp))  //文件指针到达末尾则返回 1
        {

            fscanf(fp, "%d\t%s\t%s\t%s\t%s\t%d\t\n", &ad->account, ad->username, ad->secert, ad->secertquestion, ad->secertanswer, &ad->money);
            if (account == ad->account && strcmp(password, ad->secert) == 0)  //账号密码都相同
            {
                flag = 1;  //登录成功
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
            printf("||       账号或密码错误, 请重新输入 ,或重新设置密码         ||\n");
            printf("||       输入1，重新设置密码 输入其余，重新输入密码         ||\n");
            printf("||----------------------------------------------------------||\n");
            scanf("%d", &key);
            if (key == 1)
            {



                system("cls");  //清屏
                printf("||------------------------------||\n");
                printf("||       请重新设置密码         ||\n");
                printf("||------------------------------||\n");
                system("cls");  //清屏
               if (UserreviseSecertPassword() == SUCCESS)
                    system("cls");  //清屏
                system("pause");  //暂停

                continue;

            }
            else
            {
                system("pause");  //暂停
                system("cls");  //清屏
                fclose(fp);  //关闭文件
                continue;
            }

        }

        printf("||------------------------------------------||\n");
        printf("||              登  陆  成  功              ||\n");
        printf("||------------------------------------------||\n");
        system("pause");  //暂停
        system("cls");  //清屏

        /* while (1)
         {
             printf("||------------------------------------------||\n");
             printf("||            商  家    菜  单              ||\n");
             printf("||------------------------------------------||\n");
             printf("||          【1】展示所有商品信息           ||\n");
             printf("||          【2】添加商品                   ||\n");
             printf("||          【3】删除商品                   ||\n");
             printf("||          【4】修改商品信息               ||\n");
             printf("||          【5】财务管理                   ||\n");
             printf("||          【6】查询订单                   ||\n");
             printf("||          【7】账户管理                   ||\n");
             printf("||          【0】退出登录                   ||\n");
             printf("||------------------------------------------||\n");
             printf("||   请选择： ");
             while ((sel = getchar()) == '\n');  //不管输入什么都只读取第一个字符(除换行)
             while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区(清空第一个字符后的每一个字符)
             system("cls");  //清屏

             switch (sel)
             {
             case '1':
                 showInfo();  //展示所有商品信息
                 system("pause");
                 system("cls");
                 break;

             case '2':
                 addProduct();  //添加商品
                 break;

             case '3':
                 deleteProduct();  //删除商品
                 break;

             case '4':
                 reviseProduct();  //修改商品价格
                 break;

             case '5':
                 merchandiseDiscount();  //添加商品折扣
                 break;

             case '6':
                 SearrchCt();  //查询顾客
                 break;

             case '0':
                 fclose(fp);  //关闭文件
                 return;  //返回上一级

             default:
                 input_error();  //输入错误显示
             }
         }*/

    }

    return SUCCESS;

}
Status UserInsertList()//用户注册
{



    char ch;
    UserLNode ad;  //用户 a_1
    FILE* fp;
    int len_1, len_2;  //记录密码个数, 记录密码合法字符个数

    while (1)
    {
        printf("||-----------------用户名注册---------------||\n");
        printf("||------------------------------------------||\n");
        printf("||     输入 0 可退出注册, 8 位以内字母      ||\n");
        printf("||------------------------------------------||\n");
        printf("||  用户名： ");
        scanf("%s", ad.username);
        system("cls");  //清屏

        if (strcmp(ad.username, "0") == 0)  // 0 退出注册
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
            while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
            printf("||------------------------------------------||\n");
            printf("||       姓名格式不正确, 8 位以内字母       ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //暂停
            system("cls");  //清屏
        }
    }

    while (1)
    {
        printf("||----------------账户输入------------------||\n");
        printf("||------------------------------------------||\n");
        printf("||     输入 0 可退出注册, 6位数字           ||\n");
        printf("||------------------------------------------||\n");
        printf("||   用户账户：  ");
        scanf("%d", &ad.account);
        system("cls");  //清屏

        if (ad.account == 0)
        {
            return 0;
        }



        if (ad.account <=100000  || ad.account>999999)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
            printf("||------------------------------------------||\n");
            printf("||             账号格式错误, 6位数字        ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //暂停
            system("cls");  //清屏
            continue;
        }
        else
        {
            break;
        }
    }



    while (1)
    {
        printf("||----------------密码输入------------------||\n");
        printf("||------------------------------------------||\n");
        printf("||   输入 0 可退出注册, 9-15 位字母或数字   ||\n");
        printf("||------------------------------------------||\n");
        printf("||   用户密码：  ");
        scanf("%s", ad.secert);
        system("cls");  //清屏

        if (strcmp(ad.secert, "0") == 0)
        {
            return;
        }

        len_1 = strlen(ad.secert);
        len_2 = strspn(ad.secert, str);

        if (len_1 < 9 || len_1>15 || len_2 < 9 || len_2>15)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
            printf("||------------------------------------------||\n");
            printf("||     密码格式错误, 9-15 位字母或数字      ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //暂停
            system("cls");  //清屏
            continue;
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        printf("||-------------------密保输入---------------||\n");
        printf("||------------------------------------------||\n");
        printf("||   输入 0 可退出注册, 9-19 位字母或数字   ||\n");
        printf("||------------------------------------------||\n");
        printf("||   用户密保：  ");
        scanf("%s", ad.secertquestion);
        system("cls");  //清屏

        if (strcmp(ad.secertquestion, "0") == 0)
        {
            return 0;
        }

        len_1 = strlen(ad.secertquestion);
        len_2 = strspn(ad.secertquestion, str);

        if (len_1 < 9 || len_1>19 || len_2 < 9 || len_2>19)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
            printf("||------------------------------------------||\n");
            printf("||     密保格式错误, 9-19 位字母或数字      ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //暂停
            system("cls");  //清屏
            continue;
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        rintf("||-------------------密保密码输入------------||\n");
        printf("||------------------------------------------||\n");
        printf("||   输入 0 可退出注册, 9-19 位字母或数字   ||\n");
        printf("||------------------------------------------||\n");
        printf("||   用户密保密码：  ");
        scanf("%s", ad.secertanswer);
        system("cls");  //清屏

        if (strcmp(ad.secertanswer, "0") == 0)
        {
            return 0;
        }

        len_1 = strlen(ad.secertanswer);
        len_2 = strspn(ad.secertanswer, str);

        if (len_1 < 9 || len_1>19 || len_2 < 9 || len_2>19)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
            printf("||------------------------------------------||\n");
            printf("||     密保格式错误, 9-19 位字母或数字      ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //暂停
            system("cls");  //清屏
            continue;
        }
        else
        {
            break;
        }
    }

     
    
    ad.money = 0;
   

    fp = fopen("USER.txt", "a");  //只写，在末尾添加
    file_open_error(fp);  //文件是否打开失败


    fprintf(fp, "%d\t%s\t%s\t%s\t%s\t%d\t\n", ad.account, ad.username, ad.secert, ad.secertquestion, ad.secertanswer,  ad.money);


    printf("||------------------------------------------||\n");
    printf("||             注  册  成  功               ||\n");
    printf("||------------------------------------------||\n");
    printf("|| 账号：%-8d  密码：%-16s   ||\n", ad.account, ad.secert);
    printf("|| 用户名: %-8s                 ||\n", ad.username);
    printf("||------------------------------------------||\n");
    system("pause");  //暂停
    system("cls");  //清屏

    fclose(fp);

    return SUCCESS;
}
Status UserrevisePassword()//修改用户密码

{
    char ch;
    int i = 0;
    int account;
    int len_1, len_2;  //记录密码个数, 记录密码合法字符个数
    char password[size];
    char password_1[size], password_2[size];
    FILE* fp;  //文件指针
    UserLNode* A;  //用户
    UserLNode* tail;  //指向尾部的指针

    while (1)
    {
        printf("||------------------------------------------||\n");
        printf("||   输入 0 即可取消修改, 请输入 6 位数字   ||\n");
        printf("||------------------------------------------||\n");
        printf("||   用户账号：  ");
        scanf("%d", &account);
        system("cls");  //清屏

        if (account == 0)
        {
            return;
        }

        if (account <= 100000 || account > 999999)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
            printf("||------------------------------------------||\n");
            printf("||      账号格式错误, 请输入 6 位数字       ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //暂停
            system("cls");  //清屏
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
        printf("||   输入 0 可取消修改, 9-15 位字母或数字   ||\n");
        printf("||------------------------------------------||\n");
        printf("||   用户密码：  ");
        scanf("%s", password);
        system("cls");  //清屏

        if (strcmp(password, "0") == 0)
        {
            return;
        }

        len_1 = strlen(password);
        len_2 = strspn(password, str);

        if (len_1 < 9 || len_1>15 || len_2 < 9 || len_2>15)
        {
            while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
            printf("||------------------------------------------||\n");
            printf("||     密码格式错误, 9-15 位字母或数字      ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //暂停
            system("cls");  //清屏
            continue;
        }
        else
        {
            break;
        }
    }

    fp = fopen("USER.txt", "r");  //可读写
    file_open_error(fp);  //文件是否打开失败

    A = (UserLNode*)malloc(sizeof(UserLNode));  //申请动态内存
     //内存是否申请失败
    if (A==NULL)
    {
        printf("||------------------------------------------||\n");
        printf("||            申 请 内 存 失 败             ||\n");
        printf("||------------------------------------------||\n");
        system("pause");  //暂停
        system("cls");  //清屏
        return ERROR;
    }

    A->next = NULL;
    tail = A;  //指向尾部的指针

    while (!feof(fp))  //fp==EOF 返回 1
    {
        UserLNode* p;  //存放数据的指针

        p = (UserLNode*)malloc(sizeof(UserLNode));  //申请动态内存
        if (A == NULL)
        {
            printf("||------------------------------------------||\n");
            printf("||            申 请 内 存 失 败             ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //暂停
            system("cls");  //清屏
            return ERROR;
        }


        fscanf(fp, "%d\t%s\t%s\t%s\t%s\t%d\t\n", &p->account, p->username, p->secert, p->secertquestion, p->secertanswer, &p->money);

        while ((account == p->account) && (strcmp(password, p->secert) == 0))  //账号密码相同
        {
            while (1)
            {
                printf("||------------------------------------------||\n");
                printf("||   输入 0 可取消修改, 9-15 位字母或数字   ||\n");
                printf("||------------------------------------------||\n");
                printf("||   新密码：  ");
                scanf("%s", password_1);
                system("cls");  //清屏

                if (strcmp(password_1, "0") == 0)
                {
                    return;
                }

                len_1 = strlen(password_1);
                len_2 = strspn(password_1, str);

                if (len_1 < 9 || len_1>15 || len_2 < 9 || len_2>15)
                {
                    while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
                    printf("||------------------------------------------||\n");
                    printf("||    新密码格式错误, 9-15 位字母或数字     ||\n");
                    printf("||------------------------------------------||\n");
                    system("pause");  //暂停
                    system("cls");  //清屏
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
                printf("||   输入 0 可取消修改, 9-15 位字母或数字   ||\n");
                printf("||------------------------------------------||\n");
                printf("||   请再次输入新密码： ");
                scanf("%s", password_2);
                system("cls");  //清屏

                if (strcmp(password_2, "0") == 0)
                {
                    return;
                }

                len_1 = strlen(password_2);
                len_2 = strspn(password_2, str);

                if (len_1 < 9 || len_1>15 || len_2 < 9 || len_2>15)
                {
                    while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
                    printf("||------------------------------------------||\n");
                    printf("||    新密码格式错误, 9-15 位字母或数字     ||\n");
                    printf("||------------------------------------------||\n");
                    system("pause");  //暂停
                    system("cls");  //清屏
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
                printf("||            密  码  不  相  同            ||\n");
                printf("||------------------------------------------||\n");
                system("pause");  //暂停
                system("cls");  //清屏
            }
        }

        tail->next = p;  //接到表尾
        tail = p;  //循环至表尾
        tail->next = NULL;  //表尾表尾赋空
    }

    printf("||------------------------------------------||\n");
    if (i)
    {
        printf("||             修  改  成  功               ||\n");
    }
    else
    {
        printf("||       无该用户或用户信息错误         ||\n");
    }
    printf("||------------------------------------------||\n");
    system("pause");  //暂停
    system("cls");  //清屏

    fclose(fp);

    if (i == 0)
    {
        admi_UserDestrong_List(&A);  //摧毁链表
        return;
    }

    fp = fopen("USER.txt", "w");  //可读写，写时清除原本内容
    file_open_error(fp);  //文件是否打开失败

    tail = A->next;  //指向尾部的指针

    while (tail != NULL)
    {
        fprintf(fp, "%d\t%s\t%s\t%s\t%s\t%d\t\n", tail->account, tail->username, tail->secert, tail->secertquestion, tail->secertanswer, tail->money);
        tail = tail->next;  //继续写入下一个
    }

    admi_UserDestrong_List(&A);  //摧毁链表
    fclose(fp);  //释放文件指针
}
Status UserreviseSecertPassword()
{

    //修改用户密码

    {
        char ch;
        int i = 0;
        int account;
        int len_1, len_2;  //记录密码个数, 记录密码合法字符个数
        char password[size];
        char password_1[size], password_2[size];
        FILE* fp;  //文件指针
        UserLNode* A;  //用户
        UserLNode* tail;  //指向尾部的指针
        int key = 0;
        while (1)
        {
            printf("||------------------------------------------||\n");
            printf("||   输入 0 即可取消修改, 请输入 6 位数字   ||\n");
            printf("||------------------------------------------||\n");
            printf("||   商家账号：  ");
            scanf("%d", &account);
            system("cls");  //清屏

            if (account == 0)
            {
                return;
            }

            if (account <= 100000 || account > 999999)
            {
                while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
                printf("||------------------------------------------||\n");
                printf("||      账号格式错误, 请输入 6 位数字       ||\n");
                printf("||------------------------------------------||\n");
                system("pause");  //暂停
                system("cls");  //清屏
                continue;
            }
            else
            {
                break;
            }
        }



        fp = fopen("USER.txt", "r");  //可读写
        file_open_error(fp);  //文件是否打开失败

        A = (UserLNode*)malloc(sizeof(UserLNode));  //申请动态内存
        if (A==NULL)
        {
            printf("||------------------------------------------||\n");
            printf("||              申请内存失败                ||\n");
            printf("||------------------------------------------||\n");
            system("pause");  //暂停
            system("cls");  //清屏
            return ERROR;
        }

        A->next = NULL;
        tail = A;  //指向尾部的指针

        while (!feof(fp))  //fp==EOF 返回 1
        {
            UserLNode* p;  //存放数据的指针

            p = (UserLNode*)malloc(sizeof(UserLNode)); //申请动态内存
            if (p == NULL)
            {
                printf("||------------------------------------------||\n");
                printf("||              申请内存失败                ||\n");
                printf("||------------------------------------------||\n");
                system("pause");  //暂停
                system("cls");  //清屏
                return ERROR;
            }


            fscanf(fp, "%d\t%s\t%s\t%s\t%s\t%d\t\n", &p->account, p->username, p->secert, p->secertquestion, p->secertanswer, &p->money);



            while ((account == p->account))  //账号相同
            {
                if (key == 0)
                {
                    char answer[size];
                    while (1)
                    {

                        printf("||---------------------------------------------||\n");
                        printf("||       输入0取消修改，回答密保问题           ||\n");
                        printf("||密保问题:%s                              ||\n", p->secertquestion);
                        printf("||---------------------------------------------||\n");
                        printf("||   密保答案：  ");
                        scanf("%s", answer);
                        system("cls");
                        if (strcmp(answer, "0") == 0)
                        {
                            printf("||------------------------------------------||\n");
                            printf("||                  返回界面                ||\n");
                            printf("||------------------------------------------||\n");
                            system("pause");
                            return ERROR;
                        }
                        if (strcmp(answer, p->secertanswer) == 0)
                        {
                            printf("||------------------------------------------||\n");
                            printf("||                  回答正确                ||\n");
                            printf("||------------------------------------------||\n");
                            system("pause");
                            break;
                        }
                        else
                        {
                            while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
                            printf("||------------------------------------------||\n");
                            printf("||                  回答错误                ||\n");
                            printf("||------------------------------------------||\n");
                            system("pause");  //暂停
                            system("cls");  //清屏
                            continue;
                        }


                    }
                    while (1)
                    {
                        while (1)
                        {
                            printf("||------------------------------------------||\n");
                            printf("||   输入 0 可取消修改, 9-15 位字母或数字   ||\n");
                            printf("||------------------------------------------||\n");
                            printf("||   新密码：  ");
                            scanf("%s", password_1);
                            system("cls");  //清屏

                            if (strcmp(password_1, "0") == 0)
                            {
                                return;
                            }

                            len_1 = strlen(password_1);
                            len_2 = strspn(password_1, str);

                            if (len_1 < 9 || len_1>15 || len_2 < 9 || len_2>15)
                            {
                                while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
                                printf("||------------------------------------------||\n");
                                printf("||    新密码格式错误, 9-15 位字母或数字     ||\n");
                                printf("||------------------------------------------||\n");
                                system("pause");  //暂停
                                system("cls");  //清屏
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
                            printf("||   输入 0 可取消修改, 9-15 位字母或数字   ||\n");
                            printf("||------------------------------------------||\n");
                            printf("||   请再次输入新密码： ");
                            scanf("%s", password_2);
                            system("cls");  //清屏

                            if (strcmp(password_2, "0") == 0)
                            {
                                return;
                            }

                            len_1 = strlen(password_2);
                            len_2 = strspn(password_2, str);

                            if (len_1 < 9 || len_1>15 || len_2 < 9 || len_2>15)
                            {
                                while ((ch = getchar()) != '\n' && ch != EOF);  //清空缓冲区
                                printf("||------------------------------------------||\n");
                                printf("||    新密码格式错误, 9-15 位字母或数字     ||\n");
                                printf("||------------------------------------------||\n");
                                system("pause");  //暂停
                                system("cls");  //清屏
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
                            printf("||            密  码  不  相  同            ||\n");
                            printf("||------------------------------------------||\n");
                            system("pause");  //暂停
                            system("cls");  //清屏
                        }
                    }


                }
                if (key == 1)

                {
                    break;
                }
            }
            tail->next = p;  //接到表尾
            tail = p;  //循环至表尾
            tail->next = NULL;  //表尾表尾赋空

        }

        printf("||------------------------------------------||\n");
        if (i)
        {
            printf("||             修  改  成  功               ||\n");
        }
        else
        {
            printf("||       无该用户或用户信息错误         ||\n");
        }
        printf("||------------------------------------------||\n");
        system("pause");  //暂停
        system("cls");  //清屏

        fclose(fp);

        if (i == 0)
        {
            admi_UserDestrong_List(&A);  //摧毁链表
            return;
        }

        fp = fopen("SHOP.txt", "w");  //可读写，写时清除原本内容
        file_open_error(fp);  //文件是否打开失败

        tail = A->next;  //指向尾部的指针

        while (tail != NULL)
        {
            fprintf(fp, "%d\t%s\t%s\t%s\t%s\t%d\t\n", tail->account, tail->username, tail->secert, tail->secertquestion, tail->secertanswer, tail->money);
            tail = tail->next;  //继续写入下一个
        }

        admi_UserDestrong_List(&A);  //摧毁链表
        fclose(fp);  //释放文件指针
        return SUCCESS;
    }
}