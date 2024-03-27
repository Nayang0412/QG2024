#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


void input_error();  //输入错误显示
void file_open_error(FILE* fp);  //文件打开失败
void malloc_defeat(ShopLNode* A);  //动态内存申请失败
Status admi_Destrong_List(ShopLinkedList* A);


#endif
