#ifndef SELL_H_INCLUDED
#define SELL_H_INCLUDED
#define size 20
typedef struct SellLNode
{

    struct GoodsLNode e;//商品信息
    char sellname[size];//购买人信息
    char location[size];//购买人收货地点
    int state;//商品发货的状态//state=0,为未发货，为1等于已发货，为2等于已收货
    int piece;//商品的订购量
    struct SellLNode* next;

} SellLNode,*SellLinkst;
#endif