#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stack>
using namespace std;

struct Node
{
     vector<int> key;
};

int **File_To_AdjMatrix(string filename, int &n)
{
     ifstream f;
     f.open(filename.c_str());

     f >> n;

     int **a = new int *[n];

     for (int i = 0; i < n; i++)
     {
          a[i] = new int[n];
          for (int j = 0; j < n; j++)
          {
               f >> a[i][j];
          }
     }

     f.close();

     return a;
}

void AdjMatrix_To_AdjList(string filename)
{
     int n = 0;

     int **a = File_To_AdjMatrix(filename, n);

     // Khởi tạo danh sách kề
     Node *AdjList = new Node[n];

     // Ứng với mỗi dòng i thêm các vị trí j mà a[i][j]!=0 vào node có CTDL vector
     for (int i = 0; i < n; i++)
     {
          Node p;

          for (int j = 0; j < n; j++)
          {
               if (a[i][j] != 0)
               {
                    p.key.push_back(j);
               }
          }

          // Gán vào từng node danh sách kề
          AdjList[i] = p;
     }

     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < AdjList[i].key.size(); j++)
          {
               cout << AdjList[i].key[j] << " ";
          }
          cout << "\n";
     }
}

// CAU 2
Node *File_To_AdjList(string filename, int &n)
{
     ifstream f;
     f.open(filename.c_str());

     string s = "";
     getline(f, s);

     n = atoi(s.c_str());

     Node *AdjList = new Node[n];

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

               AdjList[i].key.push_back(value);

               element = strtok(NULL, " "); // Cắt chuỗi từ vị trí dừng lại trước đó
          }

          i++;
     }

     f.close();

     return AdjList;
}

void AdjList_To_AdjMatrix(string filename)
{
     int n = 0;

     Node *AdjList = File_To_AdjList(filename, n);

     int **AdjMatrix = new int *[n];

     for (int i = 0; i < n; i++)
     {
          // Khởi tạo tất cả các vị trí = 0
          AdjMatrix[i] = new int[n]{0};

          for (int k = 0; k < AdjList[i].key.size(); k++)
          {
               // Kiểm tra trong danh sách kề xem i nối với ai thì gán = 1
               AdjMatrix[i][AdjList[i].key[k]] = 1;
          }
     }

     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               cout << AdjMatrix[i][j] << " ";
          }
          cout << "\n";
     }
}

bool Direct_Undirect(int **a, int n)
{
     for (int i = 0; i < n; i++)
     {
          for (int j = i + 1; j < n; j++)
          {
               if (a[i][j] != a[j][i])
               {
                    return false;
               }
          }
     }
     return true;
}

void Edges_Vertices(int **a, int n)
{
     cout << "Number of edges: " << n << endl;
     int count = 0;
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               count += a[i][j];
          }
     }
     cout << "Number of vertices: " << count << endl;
}

void Degree(int **a, int n)
{
     if (Direct_Undirect(a, n))
     {
          for (int i = 0; i < n; i++)
          {
               int deg = 0;
               for (int j = 0; j < n; j++)
               {
                    deg += a[i][j];
               }
               cout << "Degree of " << i << ": " << deg << endl;
          }
     }
     else
     {
          for (int i = 0; i < n; i++)
          {
               int deg_in = 0;
               int deg_out = 0;
               for (int j = 0; j < n; j++)
               {
                    deg_in += a[i][j];
                    deg_out += a[j][i];
               }
               cout << "In_degree  of " << i << ": " << deg_in << endl;
               cout << "Out_degree of " << i << ": " << deg_out << endl;
               cout << endl;
          }
     }
}

int Leaf_Vertices(int **a, int n)
{
     int count = 0;
     if (Direct_Undirect(a, n))
     {
          for (int i = 0; i < n; i++)
          {
               int deg = 0;
               for (int j = 0; j < n; j++)
               {
                    deg += a[i][j];
               }
               if (deg == 1)
               {
                    count += 1;
               }
          }
          return count;
     }
     else
     {
          for (int i = 0; i < n; i++)
          {
               int deg_in = 0;
               int deg_out = 0;
               for (int j = i; j < n; j++)
               {
                    deg_in += a[i][j];
                    deg_out += a[j][i];
               }
               if (deg_in + deg_out == 1)
               {
                    count += 1;
               }
          }
          return count;
     }
}

bool Complete_Graph(int **a, int n)
{
     // Chỉ xét đồ thị vô hướng
     if (Direct_Undirect(a, n) == false)
     {
          return false;
     }
     for (int i = 0; i < n; i++)
     {
          int deg = 0;
          for (int j = 0; j < n; j++)
          {
               if (a[i][j] == 1)
                    deg += a[i][j];
          }
          // đỉnh bất kì kề với n - 1 đỉnh còn lại
          if (deg != n - 1)
          {
               return false;
          }
     }
     return true;
}

bool Circular_Graph(int **a, int n)
{
     if (Direct_Undirect(a, n) == false)
     {
          return false;
     }
     for (int i = 0; i < n; i++)
     {
          // Đỉnh đang xét kề với hai đỉnh kề bên của nó
          if (i == 0)
          {
               if (a[i][n - 1] && a[i][i + 1] && a[i][n - 1] == a[i][i + 1] == 1)
               {
                    continue;
               }
               else
                    return false;
          }
          else if (i == n - 1)
          {
               if (a[i][i - 1] && a[i][0] && a[i][i - 1] == a[i][0] == 1)
               {
                    continue;
               }
               else
                    return false;
          }
          else
          {
               if (a[i][i - 1] && a[i][i + 1] && a[i][i - 1] == a[i][i + 1] == 1)
               {
                    continue;
               }
               else
                    return false;
          }
     }
     return true;
}

// Struct Queue dùng để phục vụ cho việc tô màu khi xét đồ thị lưỡng phân
struct Queue
{
     int capacity;
     int *data;
     int rear;
     int front;
};

void initQ(Queue &q)
{
     q.data = new int[100];
     q.rear = 0;
     q.front = 0;
}

void enQueue(Queue &q, int p)
{
     q.data[q.rear] = p;
     q.rear++;
}

int popQueue(Queue &q)
{
     if (q.front == q.rear)
     {
          return 0;
     }
     int temp = q.data[q.front];
     for (int i = 0; i < q.rear - 1; i++)
     {
          q.data[i] = q.data[i + 1];
     }
     q.rear--;
     return temp;
}
// Tham khảo từ nguồn sau:
// https://www.geeksforgeeks.org/bipartite-graph/?fbclid=IwAR3kAkKb8sSbNGSTQc-sa_C1URw8-XPjxOYMnQBvKjK_uq7sh5eXcqxNsHo
bool Bigraph(int **a, int n, int *&color)
{
     // mặc định là chưa tô màu
     color = new int[n]{0};
     for (int i = 0; i < n; i++)
     {
          if (color[i] == 0)
          {
               Queue q;
               initQ(q);
               // Tô đỉnh đang xét có màu là 1
               color[i] = 1;
               enQueue(q, i);

               while (q.rear != 0)
               {
                    // Lấy đỉnh u đang xét trong queue
                    int u = popQueue(q);
                    if (a[u][u] == 1)
                    {
                         return false;
                    }
                    // hello everyone
                    for (int v = 0; v < n; v++)
                    {
                         if (a[u][v] && color[v] == 0)
                         {
                              // Tô màu KHÁC đỉnh u cho các đỉnh kề với nó
                              color[v] -= color[u];
                              // Thêm đỉnh kề vào queue để xét tiếp
                              enQueue(q, v);
                         }
                         // Nếu như đỉnh kề trùng màu với đỉnh đỉnh đang xét thì không là Bigraph
                         else if (a[u][v] && color[v] == color[u])
                         {
                              return false;
                         }
                    }
               }
          }
     }
     return true;
}

bool Complete_Bigraph(int **a, int n, int *&color)
{
     if (Bigraph(a, n, color))
     {
          int count_color_minus1 = 0;
          int count_color_1 = 0;
          for (int i = 0; i < n; i++)
          {
               if (color[i] == -1)
               {
                    // số đỉnh tô màu -1
                    count_color_minus1++;
               }
               if (color[i] == 1)
               {
                    // số đỉnh tô màu 1
                    count_color_1++;
               }
          }
          for (int i = 0; i < n; i++)
          {
               int count = 0;
               if (color[i] == 1)
               {
                    for (int j = 0; j < n; j++)
                    {
                         if (a[i][j] == 1)
                         {
                              count += a[i][j];
                         }
                    }
                    // Đỉnh tô màu 1 kề với tất cả các đỉnh màu -1
                    if (count != count_color_minus1)
                         return false;
               }
               else if (color[i] == -1)
               {
                    for (int j = 0; j < n; j++)
                    {
                         if (a[i][j] == 1)
                         {
                              count += a[i][j];
                         }
                    }
                    // Đỉnh tô màu -1 kề với tất cả các đỉnh màu 1
                    if (count != count_color_1)
                         return false;
               }
          }
     }
     else
          return false;
     return true;
}

int **Direct_To_Undirect(int &n)
{
     int **b = File_To_AdjMatrix("graph01.txt", n);
     for (int i = 0; i < n; i++)
     {
          for (int j = i; j < n; j++)
          {
               if (b[i][j] != b[j][i])
               {
                    b[i][j] += b[j][i];
                    b[j][i] = b[i][j];
               }
          }
     }
     return b;
}

// struct dùng để lưu số lượng thành phần liên thông và sô lượng cây
struct count
{
     int connected_component;
     int tree;
};

// Tham khảo từ nguồn sau: https://www.youtube.com/watch?v=IGrIwpAX9Qk&t=759s
count CountConnectedComponent_CountTree(int **arr, int n)
{
     count c;
     c.connected_component = 0;
     c.tree = 0;
     // Chỉ xét vô hướng
     if (!Direct_Undirect(arr, n))
     {
          return c;
     }
     int *visit = new int[n]{0};
     for (int u = 0; u < n; u++)
     {
          // Nếu chưa thăm thì đi thăm
          if (visit[u] == 0)
          {
               // Tạo một stack và thêm phần tử đó vào stack
               stack<int> s;
               s.push(u);

               visit[u] = 1;

               // Cứ xét tiếp nếu stack không rỗng
               while (!s.empty())
               {
                    // Lấy đỉnh đầu stack để xét
                    int v = s.top();

                    // xóa đỉnh đầu ra khỏi stack
                    s.pop();

                    // Xét các đỉnh kều với đỉnh đang xét
                    for (int t = 0; t < n; t++)
                    {
                         // Nếu tồn tại đường đi và chưa được thăm thì đi thăm
                         // và thêm đỉnh kề và đỉnh đang xét vào
                         if (arr[v][t] && visit[t] == 0)
                         {
                              visit[t] = 1;
                              s.push(v);
                              s.push(t);

                              // ngắt vòng lặp để xét tiếp đỉnh vừa thêm vào stack
                              break;
                         }
                    }
               }
               int deg = 0;
               int vertices = 0;

               // Tính tổng bậc của đỉnh và số cạnh của tplt
               for (int i = 0; i < n; i++)
               {
                    if (visit[i] == 1)
                    {
                         for (int j = 0; j < n; j++)
                         {
                              deg += arr[i][j];
                         }
                         vertices++;
                    }
               }

               // Sử dụng tính chất của đồ thị
               // Số cạnh bằng tổng bậc chia 2
               int edges = deg / 2;

               // Do là đồ thị liên thông nên nếu có n - 1 cạnh thì là cây
               if (edges == vertices - 1)
               {
                    c.tree++;
               }
               c.connected_component++;
          }
     }
     return c;
}

int **Complement_Graph(int **a, int n)
{
     int **temp = new int *[n];
     // Chỉ làm cho đồ thị vô hướng
     if (Direct_Undirect(a, n))
     {
          for (int i = 0; i < n; i++)
          {
               temp[i] = new int[n]{0};
          }
          for (int i = 0; i < n; i++)
          {
               for (int j = i + 1; j < n; j++)
               {
                    if (a[i][j] == 1)
                    {
                         continue;
                    }
                    else if (a[i][j] == 0)
                    {
                         temp[i][j] = 1;
                         temp[j][i] = 1;
                    }
                    else
                         return NULL;
               }
          }
     }
     else
          return NULL;
     return temp;
}

int **Converse_Graph(int **a, int n)
{
     int **temp = new int *[n];
     // Chỉ làm cho đồ thị có hướng
     if (Direct_Undirect(a, n) == false)
     {
          for (int i = 0; i < n; i++)
          {
               temp[i] = new int[n]{0};
          }
          for (int i = 0; i < n; i++)
          {
               for (int j = 0; j < n; j++)
               {
                    temp[i][j] = a[j][i];
               }
          }
     }
     else
          return NULL;
     return temp;
}

// Tham khảo từ nguồn sau: https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
void CutVertices(int **&a, int n)
{
     if (Direct_Undirect(a, n))
     {
          // Xóa từng đỉnh và kiểm tra tính liên thông khi xóa từng đỉnh
          for (int i = 0; i < n; i++)
          {
               int **temp = File_To_AdjMatrix("graph01.txt", n);
               // Tạo ma trận mới với từng đỉnh muốn xóa
               for (int j = 0; j < n; j++)
               {
                    temp[i][j] = 0;
                    temp[j][i] = 0;
               }
               count c = CountConnectedComponent_CountTree(temp, n);
               // Do chỉ xóa các cạnh nối đến đỉnh đang xét
               // Nên bản thân đỉnh đó là một TPLT nên t phải trừ bớt đi
               if (c.connected_component != 0 && c.connected_component - 1 != 1)
               {
                    cout << i << endl;
               }
          }
     }
     else
          cout << "This is not undirected graph !!!" << endl;
}

// Tham khảo từ nguồn sau: https://www.geeksforgeeks.org/bridge-in-a-graph/?ref=lbp
void BridgeEdges(int **&a, int n)
{
     if (Direct_Undirect(a, n))
     {
          // Thử xóa từng cạnh của đồ thị để xét tính liên thống
          for (int i = 0; i < n; i++)
          {
               for (int j = i; j < n; j++)
               {
                    if (a[i][j] == 0)
                    {
                         continue;
                    }
                    else if (a[i][j] == 1 && a[i][j] == 1)
                    {
                         // Xóa các cạnh hiện tại đang xóa
                         a[i][j] = 0;
                         a[j][i] = 0;
                         count c = CountConnectedComponent_CountTree(a, n);
                         if (c.connected_component != 0 && c.connected_component != 1)
                         {
                              cout << i << " " << j << endl;
                         }
                         // Cập nhật lại các cạnh vừa xóa
                         a[i][j] = 1;
                         a[j][i] = 1;
                    }
               }
          }
     }
     else
          cout << "This is not undirected graph !!!" << endl;
}
void Cau01()
{
     cout << "AdjList from AdjMatrix: " << endl;
     AdjMatrix_To_AdjList("graph01.txt");
}

void Cau02()
{
     cout << "AdjMatrix from AdjList: " << endl;
     AdjList_To_AdjMatrix("graph02.txt");
}

void Cau03_1(int **a, int n)
{
     if (Direct_Undirect(a, n))
     {
          cout << "Undirected Graph !!!" << endl;
     }
     else
          cout << "Directed Graph !!!" << endl;
}

void Cau03_2(int **a, int n)
{
     Edges_Vertices(a, n);
}

void Cau03_3(int **a, int n)
{
     Degree(a, n);
}

void Cau03_4(int **a, int n)
{
     cout << "Leaf vertices of graph: ";
     cout << Leaf_Vertices(a, n) << endl;
}

void Cau03_5_1(int **a, int n)
{
     if (Complete_Graph(a, n))
     {
          cout << "Complete Graph !!!" << endl;
     }
     else
          cout << "Uncomplete Graph !!!" << endl;
}
void Cau03_5_2(int **a, int n)
{
     if (Circular_Graph(a, n))
     {
          cout << "Circular Graph !!!" << endl;
     }
     else
          cout << "Not Circular Graph !!!" << endl;
}
void Cau03_5_3(int **a, int n)
{
     int *color;
     if (Bigraph(a, n, color))
     {
          cout << "Is Bigraph !!!" << endl;
     }
     else
          cout << "Not Bigraph !!!" << endl;
}
void Cau03_5_4(int **a, int n)
{
     int *color;
     if (Complete_Bigraph(a, n, color))
     {
          cout << "Complete Bigraph !!!" << endl;
     }
     else
          cout << "Uncomplete Bigraph !!!" << endl;
}

void Cau03_6(int **a, int n)
{
     count c = CountConnectedComponent_CountTree(a, n);
     if (c.connected_component == 0)
     {
          cout << "This is directed graph !!!" << endl;
     }
     else
     {
          cout << "Number of connected component: " << c.connected_component << endl;
          cout << "\n";
          cout << "Number of tree: " << c.tree << endl;
     }
}

void Cau03_7(int **a, int n)
{
     cout << "All cut vertices of graph: " << endl;
     CutVertices(a, n);
     cout << "\n";
     cout << "All bridge edges of graph: " << endl;
     BridgeEdges(a, n);
}

void Cau04(int **a, int n)
{
     if (Direct_Undirect(a, n))
     {
          cout << "This is undirected graph, don't need to direct !!!" << endl;
          return;
     }
     cout << "Before undirected !!!" << endl;
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               cout << a[i][j] << " ";
          }
          cout << endl;
     }
     int **b = Direct_To_Undirect(n);
     cout << "After undirected !!!" << endl;
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               cout << b[i][j] << " ";
          }
          cout << endl;
     }
}

void Cau05(int **a, int n)
{
     int **complement_graph = Complement_Graph(a, n);
     if (complement_graph != NULL)
     {
          cout << "Complement Graph :" << endl;
          for (int i = 0; i < n; i++)
          {
               for (int j = 0; j < n; j++)
               {
                    cout << complement_graph[i][j] << " ";
               }
               cout << endl;
          }
     }
     else
          cout << "Error !!!" << endl;
}

void Cau06(int **a, int n)
{
     int **converse_graph = Converse_Graph(a, n);
     if (converse_graph != NULL)
     {
          cout << "Graph after converse:" << endl;
          for (int i = 0; i < n; i++)
          {
               for (int j = 0; j < n; j++)
               {
                    cout << converse_graph[i][j] << " ";
               }
               cout << endl;
          }
     }
     else
          cout << "Error !!!" << endl;
}

int main()
{
     int n = 0;
     int **a = File_To_AdjMatrix("graph01.txt", n);
     cout << "CAU 01: " << endl;
     cout << "\n";
     Cau01();
     cout << "---------------------------\n";
     cout << "CAU 02: " << endl;
     cout << "\n";
     Cau02();
     cout << "---------------------------\n";
     cout << "CAU 03_1: " << endl;
     cout << "\n";
     Cau03_1(a, n);
     cout << "---------------------------\n";
     cout << "CAU 03_2: " << endl;
     cout << "\n";
     Cau03_2(a, n);
     cout << "---------------------------\n";
     cout << "CAU 03_3: " << endl;
     cout << "\n";
     Cau03_3(a, n);
     cout << "---------------------------\n";
     cout << "CAU 03_4: " << endl;
     cout << "\n";
     Cau03_4(a, n);
     cout << "---------------------------\n";
     cout << "CAU 03_5_1: " << endl;
     cout << "\n";
     Cau03_5_1(a, n);
     cout << "---------------------------\n";
     cout << "CAU 03_5_2: " << endl;
     cout << "\n";
     Cau03_5_2(a, n);
     cout << "---------------------------\n";
     cout << "CAU 03_5_3: " << endl;
     cout << "\n";
     Cau03_5_3(a, n);
     cout << "---------------------------\n";
     cout << "CAU 03_5_4: " << endl;
     cout << "\n";
     Cau03_5_4(a, n);
     cout << "---------------------------\n";
     cout << "CAU 03_6: " << endl;
     cout << "\n";
     Cau03_6(a, n);
     cout << "---------------------------\n";
     cout << "CAU 03_7: " << endl;
     cout << "\n";
     Cau03_7(a, n);
     cout << "---------------------------\n";
     cout << "CAU 04: " << endl;
     cout << "\n";
     Cau04(a, n);
     cout << "---------------------------\n";
     cout << "CAU 05: " << endl;
     cout << "\n";
     Cau05(a, n);
     cout << "---------------------------\n";
     cout << "CAU 06: " << endl;
     cout << "\n";
     Cau06(a, n);
     cout << "---------------------------\n";
     system("pause");
     return 0;
}