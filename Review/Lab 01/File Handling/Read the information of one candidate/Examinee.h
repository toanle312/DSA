#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
struct Examinee
{
	string id;
	float math = 0, literature = 0, physic = 0, chemistry = 0, biology = 0, history = 0, geography = 0, civic_education = 0, natural_science = 0, social_science = 0, foreign_language = 0;
};

// Các hàm dưới đây là các hàm tách chuỗi và lưu thông tin vào struct

// Làm theo cách bình thường
Examinee readExaminee(string);
// Làm theo vector
Examinee readExaminee_token(string);
// Làm theo hàm strtok: xử lý cắt chuỗi
Examinee readExaminee_strtok(string);
