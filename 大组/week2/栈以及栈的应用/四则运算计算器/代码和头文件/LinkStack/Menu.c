#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include"LinkStack.h"
#define Max 50
Status transform(char str1[Max], char str2[Max]);
Status compute(char str[Max]);
int key = 0;
int priority(char op) 
{
    if (op == '+' || op == '-') 
    {
        return 1;
    }
    else if (op == '*' || op == '/') 
    {
        return 2;
    }
    else
    {
         return 0;
    }
   
}
void welcome()
{
    char express[Max];
    char buffer[Max];
    memset(express, '\0', sizeof(express));//��ʼ������
    memset(buffer, '\0', sizeof(buffer));//��ʼ������
    
        system("cls");
        printf("������������ʽ����֧�ָ����Ҳ����ո�,���ֲ�����ʮλ\n");
        
        gets_s(express,sizeof(express));
        
        transform(express,buffer);
        printf("ת����ĺ�׺���ʽΪ��%s\n", buffer);
        compute(buffer);
        
}
Status transform( char str1[Max],char str2[Max])
{
    int i, j;
    i = j = 0;
    LinkStack s;
    initLStack(&s);
    
    
   
    for ( i = 0; i < strlen(str1); i++)
    {
        if (str1[i] >= '0' && str1[i] <= '9') 
        {
            if (str1[i+1] >= '0' && str1[i+1] <= '9')
            {
                str2[j++] = str1[i];
            }
            else
            {
                str2[j++] = str1[i];
                str2[j++] = ' ';
            }

        }
        else if (str1[i]=='(')
        {
            pushLStack(&s,str1[i]);
            key++;
           
            
        }
        else if (str1[i]==')')
        {
            while (key!=ERROR&&getTopLStack(&s)!='(')
            {
                
                
                    str2[j++] = popLStack(&s);
                    key--;    
                
            }
            
            popLStack(&s);
            key--;
        }
        else if (priority(str1[i])!=0)
        {
            if (str1[i]=='/'&&str1[i+1]=='0')
            {
                printf("���ܳ�0\n");
                return ERROR;
            }
            while (key!=ERROR&&priority(str1[i])<=priority(getTopLStack(&s)))
            {
                str2[j++] = popLStack(&s);
                key--;
            }
            pushLStack(&s,str1[i]);
            key++;
        }
        else
        {
            printf("%c",str1[i]);
            printf("���ʽ���󣬺���δ֪����\n");
            return ERROR;
        }

 
    }
    while (key!=ERROR)
    {
        if (getTopLStack(&s) == '(')
        {
            printf("ȱʧ������\n");
        }
        else
        {
            str2[j++] = popLStack(&s);
            key--;
        }
    }
    return SUCCESS;
}
Status compute(char str[Max])
{
    LinkStack s;
    initLStack(&s);
    int key = 0;
    for (int i = 0; i <strlen(str) ; i++)
    {
        if (str[i]==' ')
        {
            continue;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            if (str[i + 1] >= '0' && str[i + 1] <= '9')
            {
                int digit = 0;
                digit = (str[i] - '0') * 10 + (str[i + 1]-'0');
                i++;
                pushLStack(&s,digit);
                key++;
                continue;
            }
            else
            {
                int digit = 0;
                digit = (str[i] - '0');
                pushLStack(&s, digit);
                key++;
            }
        }
        else if (key>=2&&priority(str[i])!=0)
        {
            int sum = 0;
            int slow = 0;
            int fast = 0;
            switch (str[i])
            {
            case'+':
                sum = popLStack(&s) + popLStack(&s); 
                pushLStack(&s, sum); 
                key--; 
                break;
            case'-':
                slow = popLStack(&s);
                fast = popLStack(&s);
                sum = fast - slow;
                pushLStack(&s, sum);
                key--;
                break;
            case'*':
                slow = popLStack(&s);
                fast = popLStack(&s);
                
                sum = slow * fast;
                
                pushLStack(&s, sum);
                key--;
                break;
            case'/':
                if (getTopLStack(&s)==0)
                {
                    printf("��������Ϊ0");
                    return ERROR;
                }  
                slow = popLStack(&s);
                
                fast = popLStack(&s);
                sum = fast/slow;
                pushLStack(&s, sum);
                key--;
                break;
            }
        }


    }
    int sum = popintLStack(&s);
    printf("������Ϊ��%d\n",sum);
    return SUCCESS;
}