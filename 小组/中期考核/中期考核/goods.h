#ifndef GOODS_H_INCLUDED
#define GOODS_H_INCLUDED
#define size 20
typedef struct GoodsLNode
{

    int ID;  //编号  6位
    char type[size];  //种类  8位以内
    int price;  //价格
    
    char name[size];  //名字 小于16位
    int inventory;//库存
    int sell;//售出
    char shop[size];//所属店铺

	struct GoodsLNode* next;
} GoodsLNode, * GoodsLinkedList;

Status addProduct();//添加商品
Status deleteProduct();  //删除商品
void showInfo();  //展示所有商品信息
void reviseProduct();//修改商品
#endif
