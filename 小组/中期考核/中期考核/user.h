#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#define size 20
typedef struct  UserLNode
{

	int account;//账号
	char secert[size];//密码
	char username[size];//用户名
	char secertquestion[size];//密保问题
	char secertanswer[size];//密保答案
	int money;//账户金额
	struct UserLNode* next;
} UserLNode, * UserLinkst;
Status UserInitList();
Status UserInsertList();
Status UserrevisePassword();
Status UserreviseSecertPassword();
#endif
