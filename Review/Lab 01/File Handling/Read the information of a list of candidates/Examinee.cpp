#include "Examinee.h"
// Hàm tách chuỗi, lưu vào struct
Examinee readExaminee_token(string s)
{
	vector<string> token;
	string temp = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ',')
		{
			token.push_back(temp);
			temp = "";
		}
		else
		{
			temp += s[i];
		}
	}
	// Lưu các thông tin của sinh viên
	Examinee Candidate;
	Candidate.id = token[0];
	Candidate.math = atof(token[2].c_str());
	Candidate.literature = atof(token[3].c_str());
	Candidate.physic = atof(token[4].c_str());
	Candidate.chemistry = atof(token[5].c_str());
	Candidate.biology = atof(token[6].c_str());
	Candidate.history = atof(token[7].c_str());
	Candidate.geography = atof(token[8].c_str());
	Candidate.civic_education = atof(token[9].c_str());
	Candidate.natural_science = atof(token[10].c_str());
	Candidate.social_science = atof(token[11].c_str());
	Candidate.foreign_language = atof(token[12].c_str());
	return Candidate;
}

vector<Examinee> readExamineeList(string file_name)
{
	vector<Examinee> List;
	fstream f;
	f.open(file_name, ios::in || ios::out);
	// Kiểm tra xem file có tồn tại hay không
	if (!f.is_open())
	{
		cout << "This file is not exist !!!" << endl;
		return List;
	}
	// Biến đếm dòng
	int count = 0;
	while (!f.eof())
	{
		// chuỗi tạm thời để lưu thông tin
		string s = "";
		// Bỏ qua thao tác ở dòng đầu tiên
		if (count == 0)
		{
			getline(f, s);
			count++;
		}
		else
		{
			// Lấy thông tin của một dòng trong file
			getline(f, s);
			// Nếu không có thông tin nào thì bỏ qua
			if (s == "")
			{
				continue;
			}
			else
			{
				Examinee candidate;
				// Lấy thông tin của sinh viên đó
				candidate = readExaminee_token(s);
				// thêm vào cuối mảng vector
				List.push_back(candidate);
			}
		}
	}
	// Đóng file
	f.close();
	return List;
}