
#ifndef SHOP_H_INCLUDED
#define SHOP_H_INCLUDED
#define size 20
typedef struct ShopLNode 
{
	int account;//账号
	char secert[size];//密码
	char username[size];//用户名
	char secertquestion[size];//密保问题
	char secertanswer[size];//密保答案
	int income;//收入
	int order;//订单数
	int money;//提现金额
	struct ShopLNode* next;
} ShopLNode, * ShopLinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;

Status InitList();//初始化列表
Status InsertList();//商家注册
void revisePassword();//通过密码修改商户密码
Status reviseSecertPassword();//通过密保修改商户密码

#endif