#include <vector>
#include <iostream>
using namespace std;
void dijkstraMST(vector<vector<int>> a, int source)
{
     vector<bool> inMST(a.size(), false);    // Kiem tra dinh do da thuoc cay khung nho nhat hay chua
     vector<int> dist(a.size(), 1000000009); // Độ dài đường đi ngắn nhất từ đỉnh ban đầu đến đỉnh đang xét

     // Bat dau tu dinh 0
     dist[source] = 0; // duong di ngan nhat den 0 la 0

     // Đồ thị có n đỉnh thì ta chỉ xét n - 1 cạnh
     for (int i = 0; i < a.size() - 1; i++)
     {
          // Tìm đỉnh kề nhất với đỉnh vừa được thêm vào MST
          int min_index, min = 1000000009;
          for (int j = 0; j < a.size(); j++)
          {
               if (inMST[j] == false && dist[j] < min)
               {
                    min = dist[j]; // Cập nhập trọng số nhỏ nhất
                    min_index = j; // Cập nhật vị trí gần với đỉnh đó nhất
               }
          }

          int u = min_index; // Bắt đầu xét từ đỉnh vừa tìm được

          inMST[u] = true; // Thêm nó vào MST

          // Tìm đỉnh kề gần nhất với đỉnh đang xét
          for (int v = 0; v < a.size(); v++)
          {
               if (a[u][v] && inMST[v] == false && dist[u] != 1000000009 && dist[u] + a[u][v] < dist[v])
               /* Nếu tốn tại đường đi từ đỉnh u đến v, đỉnh v chưa được thêm vào cây khung
               và độ dài đường đi từ u đến v nhỏ hơn key[v] thì ta sẽ cập nhật lại*/
               {
                    dist[v] = dist[u] + a[u][v]; // cập nhật lại đường đi ngắn nhất từ đỉnh ban đầu đến đỉnh v
               }
          }
     }
     // In cây khung ngắn nhất
     for (int i = 0; i < a.size(); i++)
     {
          cout << i << " : " << dist[i] << endl;
     }
}
int main()
{
     vector<vector<int>> graph{{0, 2, 0, 6, 0},
                               {2, 0, 3, 8, 5},
                               {0, 3, 0, 0, 7},
                               {6, 8, 0, 0, 9},
                               {0, 5, 7, 9, 0}};

     dijkstraMST(graph, 0);
     system("pause");
     return 0;
}