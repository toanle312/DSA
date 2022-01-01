#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <string.h>
using namespace std;
vector<vector<int>> fileToAdjList(string filename)
{
     ifstream f;
     f.open(filename.c_str());

     string s = "";
     getline(f, s);

     int n = stoi(s);

     vector<vector<int>> adj_list(n, vector<int>());

     int i = 0;

     string string_temp = "";
     while (getline(f, string_temp))
     {
          string temp = "";
          for (int j = 0; j < string_temp.size(); j++)
          {
               // Nếu đọc đến kí tự ' ' thì thêm các đỉnh kề ở trước vào
               if (string_temp[j] == ' ')
               {
                    adj_list[i].push_back(stoi(temp));
                    temp = "";
               }
               // Nếu không là kí tự ' ' thì vẫn cứ cộng chuỗi để lấy đỉnh kề
               else
                    temp += string_temp[j];
          }

          // Thêm đỉnh kề cuối của đỉnh i
          if (temp != "")
          {
               adj_list[i].push_back(stoi(temp));
          }

          // Xét đỉnh tiếp theo
          i++;
     }

     f.close();

     return adj_list;
}
// Lưu ý: Chỉ làm cho đơn đồ thị vô hướng
vector<vector<int>> findSpanningTree_DFS(vector<vector<int>> adj_list)
{
     vector<vector<int>> spanning_tree(adj_list.size(), vector<int>());

     // Mảng đánh dấu thăm hay chưa
     vector<int> is_visited(adj_list.size(), false);

     // Mảng kiểm tra đã có đỉnh ở trong cây khung hay chưa
     vector<int> in_spanning_tree(adj_list.size(), false);

     // DFS sử dụng Stack
     stack<int> s;

     int vertex;
     int adj_vertex;

     // Mặc định xét từ đỉnh 0
     s.push(0);

     while (!s.empty())
     {
          vertex = s.top();
          s.pop();

          // Đánh dấu đã thăm
          is_visited[vertex] = true;

          for (int i = 0; i < adj_list[vertex].size(); i++)
          {
               // Lưu lại đỉnh kề
               adj_vertex = adj_list[vertex][i];

               // Nếu chưa thăm thì đánh dấu đã thăm
               if (is_visited[adj_vertex] == false)
               {
                    is_visited[adj_vertex] = true;

                    // Kiếm tra cạnh kề đó được thêm vào cây khung hay chưa
                    if (in_spanning_tree[adj_vertex] == false)
                    {
                         spanning_tree[vertex].push_back(adj_vertex);
                         spanning_tree[adj_vertex].push_back(vertex);

                         in_spanning_tree[vertex] = true;
                         in_spanning_tree[adj_vertex] = true;
                    }

                    // Thêm lại đỉnh cha của đỉnh kề đang xét vào Stack
                    s.push(vertex);
                    s.push(adj_vertex);

                    // Ngắt vòng for để xét tiếp đỉnh vừa được thêm vào
                    break;
               }
          }
     }
     return spanning_tree;
}

int main()
{
     vector<vector<int>> adjlist = fileToAdjList("AdjList.txt");
     vector<vector<int>> spanning_tree = findSpanningTree_DFS(adjlist);
     for (int i = 0; i < spanning_tree.size(); i++)
     {
          for (int j = 0; j < spanning_tree[i].size(); j++)
          {
               cout << spanning_tree[i][j] << " ";
          }
          cout << endl;
     }
     system("pause");
     return 0;
}