#ifndef SELL_H_INCLUDED
#define SELL_H_INCLUDED
#define size 20
typedef struct SellLNode
{

    struct GoodsLNode e;//��Ʒ��Ϣ
    char sellname[size];//��������Ϣ
    char location[size];//�������ջ��ص�
    int state;//��Ʒ������״̬//state=0,Ϊδ������Ϊ1�����ѷ�����Ϊ2�������ջ�
    int piece;//��Ʒ�Ķ�����
    struct SellLNode* next;

} SellLNode,*SellLinkst;
#endif