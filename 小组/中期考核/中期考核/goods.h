#ifndef GOODS_H_INCLUDED
#define GOODS_H_INCLUDED
#define size 20
typedef struct GoodsLNode
{

    int ID;  //���  6λ
    char type[size];  //����  8λ����
    int price;  //�۸�
    
    char name[size];  //���� С��16λ
    int inventory;//���
    int sell;//�۳�
    char shop[size];//��������

	struct GoodsLNode* next;
} GoodsLNode, * GoodsLinkedList;

Status addProduct();//�����Ʒ
Status deleteProduct();  //ɾ����Ʒ
void showInfo();  //չʾ������Ʒ��Ϣ
void reviseProduct();//�޸���Ʒ
#endif
