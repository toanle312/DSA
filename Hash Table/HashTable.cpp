#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>

#define M 1000000009
#define P 31
#define HASHTABLE_SIZE 2000

using namespace std;

struct Company
{
     string name;
     string profit_tax;
     string address;
};

vector<Company> ReadCompanyList(string file_name)
{
     vector<Company> list_company;
     ifstream f;
     f.open(file_name.c_str());
     if (!f.is_open())
     {
          return list_company;
     }
     string temp = "";
     getline(f, temp);
     while (!f.eof())
     {
          // Lay thong tin cua cong ty
          string name_company = "";
          string phone_company = "";
          string address_company = "";

          getline(f, name_company, '|');
          if (name_company == "")
          {
               break;
          }
          getline(f, phone_company, '|');
          getline(f, address_company, '\n');

          // Tao phan tu voi cau truc Company
          Company com;
          com.name = name_company;
          com.profit_tax = phone_company;
          com.address = address_company;

          // Tao danh sach cong ty
          list_company.push_back(com);
     }
     f.close();
     return list_company;
}

// Ham dung de chuyen doi string thanh gia tri khoa
long long HashString(string company_name)
{
     long long pow = 1;
     long long key = 0;

     // Cap nhat do dai chuoi
     int length = 0;

     // Neu ten cong ty nho hon 20 (khac) thi lay do dai cua chuoi
     if (company_name.size() != 20)
     {
          length = company_name.size();
     }
     // Neu du ki tu thi gan bang 20
     else
          length = 20;

     for (int i = 0; i < length; i++)
     {
          // Tinh chat dong du
          long long s = ((pow % M) * (company_name[i] % M)) % M;
          key = ((key % M) + (s % M)) % M;
          pow = ((pow % M) * P) % M;
     }

     return key;
}

// Ham lay 20 phan tu cuoi cung cua chuoi
string GetCompanyName(string s)
{
     string temp = "";

     if (s.size() <= 20)
     {
          return s;
     }
     else
     {
          for (int i = s.size() - 20; i < s.size(); i++)
          {
               temp += s[i];
          }
     }

     return temp;
}

// Tham khao tren trang web https://nguyenvanhieu.vn/bang-bam-hash-tables/ phan Linear Probing, ham insert()
void Insert(Company *hash_table, Company company)
{
     string get_20last_name = GetCompanyName(company.name);

     int index = HashString(get_20last_name) % HASHTABLE_SIZE;

     while (hash_table[index].name != "" && hash_table[index].profit_tax != "" && hash_table[index].address != "")
     {
          index = (index + 1) % HASHTABLE_SIZE;
     }

     hash_table[index].name = company.name;
     hash_table[index].profit_tax = company.profit_tax;
     hash_table[index].address = company.address;
}

Company *CreateHashTable(vector<Company> list_company)
{
     Company *HashTable = new Company[HASHTABLE_SIZE];

     for (int i = 0; i < list_company.size(); i++)
     {
          Insert(HashTable, list_company[i]);
     }

     return HashTable;
}

// Tham khao tren trang web https://nguyenvanhieu.vn/bang-bam-hash-tables/ phan Linear Probing, ham search()
Company *Search(Company *hash_table, string company_name)
{
     string get_20last_name = GetCompanyName(company_name);

     int index = HashString(get_20last_name) % HASHTABLE_SIZE;

     while ((hash_table[index].name != company_name) && (hash_table[index].name != "" && hash_table[index].profit_tax != "" && hash_table[index].address != ""))
     {
          index = (index + 1) % HASHTABLE_SIZE;
     }

     Company *found_company = new Company;

     if (hash_table[index].name == company_name)
     {
          found_company->name = hash_table[index].name;
          found_company->profit_tax = hash_table[index].profit_tax;
          found_company->address = hash_table[index].address;
          return found_company;
     }

     return NULL;
}

int main()
{
     vector<Company> list_company = ReadCompanyList("MST.txt");

     Company *HashTable = CreateHashTable(list_company);

     string input;
     cout << "Nhap ten cong ty muon tim ";
     cout << "(Ghi day du ten cong ty va in hoa tat ca cac chu cai - VD: CONG TY TNHH BEE VIET NAM): " << endl;
     getline(cin, input, '\n');

     Company *p = Search(HashTable, input);
     if (p == NULL || input == "")
     {
          cout << "Khong tim thay cong ty !!!" << endl;
     }
     else
     {
          cout << "- Thong tin cua cong ty do la: " << endl;
          cout << '\n';
          cout << "+ Ten cong ty: " << p->name << endl;
          cout << '\n';
          cout << "+ So dien thoai lien lac: " << p->profit_tax << endl;
          cout << '\n';
          cout << "+ Dia chi cong ty: " << p->address << endl;
     }
     cout << '\n';
     system("pause");
     return 0;
}