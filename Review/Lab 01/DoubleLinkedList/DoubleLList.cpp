#include "DoubleLList.h"

int main()
{
     D_node *p = createD_node(2);
     D_list *L = createD_list(p);
     addHead(L, 1);
     addTail(L, 5);
     addHead(L, 1);
     addTail(L, 3);
     addBefore(L, 2, 3);
     addTail(L, 3);
     addTail(L, 4);
     addTail(L, 5);
     addTail(L, 6);
     addAfter(L, 7, 6);
     addTail(L, 5);
     addTail(L, 3);
     addTail(L, 7);
     addTail(L, 8);
     printD_list(L);
     cout << "So luong phan tu trong danh sach: " << countElements(L) << endl;
     removeHead(L);
     cout << "Danh sach sau khi xoa node dau" << endl;
     printD_list(L);
     removeTail(L);
     cout << "Danh sach sau khi xoa node cuoi" << endl;
     printD_list(L);
     removeAfter(L, 3);
     cout << "Danh sach sau khi xoa node sau node co gia tri 3" << endl;
     printD_list(L);
     removeBefore(L, 5);
     cout << "Danh sach sau khi xoa node truoc node co gia tri 5" << endl;
     printD_list(L);
     addPos(L, 2, 3);
     cout << "Danh sach sau khi them node co gia tri 2 vao vi tri thu 3" << endl;
     printD_list(L);
     RemovePos(L, 2, 3);
     cout << "Danh sach sau khi xoa node co gia tri 2 o vi tri thu 3" << endl;
     printD_list(L);
     reverseD_list(L);
     cout << "Danh sach sau khi duoc dao nguoc" << endl;
     printD_list(L);
     removeDuplicate(L);
     cout << "Danh sach sau khi xoa cac node trung nhau" << endl;
     printD_list(L);
     removeElement(L, 2);
     cout << "Danh sach sau khi xoa cac node co gia tri 2" << endl;
     printD_list(L);
     removeAll(L);
     cout << "Danh sach sau khi xoa tat ca cac node" << endl;
     printD_list(L);
     system("pause");
     return 0;
}