#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#define size 20
typedef struct  UserLNode
{

	int account;//�˺�
	char secert[size];//����
	char username[size];//�û���
	char secertquestion[size];//�ܱ�����
	char secertanswer[size];//�ܱ���
	int money;//�˻����
	struct UserLNode* next;
} UserLNode, * UserLinkst;
Status UserInitList();
Status UserInsertList();
Status UserrevisePassword();
Status UserreviseSecertPassword();
#endif
