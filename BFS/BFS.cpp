#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string.h>
using namespace std;
vector<vector<int>> fileToAdjList(string filename)
{
     ifstream f;
     f.open(filename.c_str());

     string s = "";
     getline(f, s);

     int n = atoi(s.c_str());

     vector<vector<int>> adj_list(n, vector<int>());

     int i = 0;

     while (i < n)
     {
          string s_temp;
          getline(f, s_temp);

          char *temp_arr = new char[s_temp.size() + 1];
          strcpy(temp_arr, s_temp.c_str());

          char *element = strtok(temp_arr, " ");
          while (element != NULL)
          {
               int value = atoi(element);

               adj_list[i].push_back(value);

               element = strtok(NULL, " ");
          }

          i++;
     }

     f.close();

     return adj_list;
}
// Lưu ý: Chỉ làm cho đơn đồ thị vô hướng
vector<vector<int>> findSpanningTree_BFS(vector<vector<int>> adj_list)
{
     vector<vector<int>> spanning_tree(adj_list.size(), vector<int>());

     // Mảng đánh dấu thăm hay chưa
     vector<int> is_visited(adj_list.size(), false);

     // Mảng kiểm tra đã có đỉnh ở trong cây khung hay chưa
     vector<int> in_spanning_tree(adj_list.size(), false);

     // BFS sử dụng Queue
     queue<int> q;

     int vertex;
     int adj_vertex;

     // Mặc định xét từ đỉnh 0
     q.push(0);

     while (!q.empty())
     {
          vertex = q.front();
          q.pop();

          // Đánh dấu đã thăm
          is_visited[vertex] = true;

          for (int i = 0; i < adj_list[vertex].size(); i++)
          {
               // Lưu lại đỉnh kề
               adj_vertex = adj_list[vertex][i];

               // Nếu đỉnh kề đó chưa được thăm thì đi thăm
               if (is_visited[adj_vertex] == false)
               {
                    is_visited[adj_vertex] = true;
                    q.push(adj_vertex);
               }

               // Nếu đỉnh kề đó chưa được thêm vào cây khung
               if (in_spanning_tree[adj_vertex] == false)
               {
                    spanning_tree[vertex].push_back(adj_vertex);
                    spanning_tree[adj_vertex].push_back(vertex);

                    in_spanning_tree[vertex] = true;
                    in_spanning_tree[adj_vertex] = true;
               }
          }
     }

     return spanning_tree;
}

int main()
{
     int n = 0;
     vector<vector<int>> adjlist = fileToAdjList("AdjList.txt");
     vector<vector<int>> spanning_tree = findSpanningTree_BFS(adjlist);
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