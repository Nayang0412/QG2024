
#ifndef SHOP_H_INCLUDED
#define SHOP_H_INCLUDED
#define size 20
typedef struct ShopLNode 
{
	int account;//�˺�
	char secert[size];//����
	char username[size];//�û���
	char secertquestion[size];//�ܱ�����
	char secertanswer[size];//�ܱ���
	int income;//����
	int order;//������
	int money;//���ֽ��
	struct ShopLNode* next;
} ShopLNode, * ShopLinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;

Status InitList();//��ʼ���б�
Status InsertList();//�̼�ע��
void revisePassword();//ͨ�������޸��̻�����
Status reviseSecertPassword();//ͨ���ܱ��޸��̻�����

#endif