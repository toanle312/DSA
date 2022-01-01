#include"Examinee.h"

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
	f.open("data.txt", ios::in || ios::out);
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
// Hàm tính điểm các môn KHTN, KHXH và tổng điểm
float TotalScore(Examinee& candidate)
{
	candidate.natural_science = candidate.physic + candidate.chemistry + candidate.biology;
	candidate.social_science = candidate.history + candidate.geography + candidate.civic_education;
	return candidate.math + candidate.literature + candidate.foreign_language + candidate.natural_science + candidate.social_science;
}

void writeTotal(vector<Examinee> examinee_list, string out_file_name)
{
	fstream f;
	f.open(out_file_name, ios::out);
	// Kiểm tra file có mở được hay không
	if (!f.is_open())
	{
		cout << "This file is not exist !!!" << endl;
		return;
	}
	// Ghi các thông tin vào file
	for (int i = 0; i < examinee_list.size(); i++)
	{
		float total_score = TotalScore(examinee_list[i]);
		f << examinee_list[i].id << " " << total_score << endl;
	}
	f.close();
}