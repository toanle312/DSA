#include "Examinee.h"

Examinee readExaminee(string line_info)
{
	Examinee Candidate;
	// Lấy kích thước chuỗi
	int n = size(line_info);
	// Lưu vị trí của các dấu ','
	int pos = 0;
	// Chuỗi tạm thời
	string s_temp = "";
	for (int i = 0; i < n; i++)
	{
		// ID
		if (line_info[i] != ',' && pos == 0)
		{
			// Lưu lại thông tin của sinh viên
			Candidate.id += line_info[i];
			if (line_info[i + 1] == ',')
			{
				pos = 1;
			}
		}
		// Tên
		else if (line_info[i] == ',' && line_info[i + 1] == ',' && pos == 1)
		{
			pos = 2;
		}
		// Toán
		else if (line_info[i] != ',' && pos == 2)
		{
			s_temp += line_info[i];
			if (line_info[i + 1] == ',')
			{
				// Lưu thông tin điểm của sinh viên
				// Hàm atof(char* variable): chuyển chuỗi về dạng số thực
				Candidate.math = atof(s_temp.c_str());
				pos = 3;
				// khởi tạo lại chuỗi tạm
				s_temp = "";
			}
		}
		else if (line_info[i] == ',' && line_info[i + 1] == ',' && pos == 2)
		{
			pos = 3;
			Candidate.math = 0;
		}
		// Văn
		else if (line_info[i] != ',' && pos == 3)
		{
			s_temp += line_info[i];
			if (line_info[i + 1] == ',')
			{
				Candidate.literature = atof(s_temp.c_str());
				pos = 4;
				s_temp = "";
			}
		}
		else if (line_info[i] == ',' && line_info[i + 1] == ',' && pos == 3)
		{
			pos = 4;
			Candidate.literature = 0;
		}
		// Lý
		else if (line_info[i] != ',' && pos == 4)
		{
			s_temp += line_info[i];
			if (line_info[i + 1] == ',')
			{
				Candidate.physic = atof(s_temp.c_str());
				pos = 5;
				s_temp = "";
			}
		}
		else if (line_info[i] == ',' && line_info[i + 1] == ',' && pos == 4)
		{
			pos = 5;
			Candidate.physic = 0;
		}
		// Hóa
		else if (line_info[i] != ',' && pos == 5)
		{
			s_temp += line_info[i];
			if (line_info[i + 1] == ',')
			{
				Candidate.chemistry = atof(s_temp.c_str());
				pos = 6;
				s_temp = "";
			}
		}
		else if (line_info[i] == ',' && line_info[i + 1] == ',' && pos == 5)
		{
			pos = 6;
			Candidate.chemistry = 0;
		}
		// Sinh
		else if (line_info[i] != ',' && pos == 6)
		{
			s_temp += line_info[i];
			if (line_info[i + 1] == ',')
			{
				Candidate.biology = atof(s_temp.c_str());
				pos = 7;
				s_temp = "";
			}
		}
		else if (line_info[i] == ',' && line_info[i + 1] == ',' && pos == 6)
		{
			pos = 7;
			Candidate.biology = 0;
		}
		// Sử
		else if (line_info[i] != ',' && pos == 7)
		{
			s_temp += line_info[i];
			if (line_info[i + 1] == ',')
			{
				Candidate.history = atof(s_temp.c_str());
				pos = 8;
				s_temp = "";
			}
		}
		else if (line_info[i] == ',' && line_info[i + 1] == ',' && pos == 7)
		{
			pos = 8;
			Candidate.history = 0;
		}
		// Địa
		else if (line_info[i] != ',' && pos == 8)
		{
			s_temp += line_info[i];
			if (line_info[i + 1] == ',')
			{
				Candidate.geography = atof(s_temp.c_str());
				pos = 9;
				s_temp = "";
			}
		}
		else if (line_info[i] == ',' && line_info[i + 1] == ',' && pos == 8)
		{
			pos = 9;
			Candidate.geography = 0;
		}
		// GDCD
		else if (line_info[i] != ',' && pos == 9)
		{
			s_temp += line_info[i];
			if (line_info[i + 1] == ',')
			{
				Candidate.civic_education = atof(s_temp.c_str());
				pos = 10;
				s_temp = "";
			}
		}
		else if (line_info[i] == ',' && line_info[i + 1] == ',' && pos == 9)
		{
			pos = 10;
			Candidate.civic_education = 0;
		}
		// KHTN
		else if (line_info[i] != ',' && pos == 10)
		{
			s_temp += line_info[i];
			if (line_info[i + 1] == ',')
			{
				Candidate.natural_science = atof(s_temp.c_str());
				pos = 11;
				s_temp = "";
			}
		}
		else if (line_info[i] == ',' && line_info[i + 1] == ',' && pos == 10)
		{
			pos = 11;
			Candidate.natural_science = 0;
		}
		// KHXH
		else if (line_info[i] != ',' && pos == 11)
		{
			s_temp += line_info[i];
			if (line_info[i + 1] == ',')
			{
				Candidate.social_science = atof(s_temp.c_str());
				pos = 12;
				s_temp = "";
			}
		}
		else if (line_info[i] == ',' && line_info[i + 1] == ',' && pos == 11)
		{
			pos = 12;
			Candidate.social_science = 0;
		}
		// Ngoại ngữ
		else if (line_info[i] != ',' && pos == 12)
		{
			s_temp += line_info[i];
			if (line_info[i + 1] == ',')
			{
				Candidate.foreign_language = atof(s_temp.c_str());
				pos = 13;
				s_temp = "";
			}
		}
		else if (line_info[i] == ',' && line_info[i + 1] == ',' && pos == 12)
		{
			pos = 13;
			Candidate.foreign_language = 0;
		}
		if (pos == 13)
			break;
	}
	return Candidate;
}
// Làm theo vector
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
// Làm theo hàm strtok: xử lý cắt chuỗi
Examinee readExaminee_strtok(string s)
{
	vector<string> token;
	char *temp = new char[s.length() + 1];
	strcpy(temp, s.c_str());

	char *s_temp;

	s_temp = strtok(temp, ",");
	while (s_temp != NULL)
	{
		token.push_back(s_temp);
		s_temp = strtok(NULL, ",");
		;
	}

	delete[] temp;
	// Lưu thông tin của sinh viên
	Examinee Candidate;
	Candidate.id = token[0];
	Candidate.math = atof(token[1].c_str());
	Candidate.literature = atof(token[2].c_str());
	Candidate.physic = atof(token[3].c_str());
	Candidate.chemistry = atof(token[4].c_str());
	Candidate.biology = atof(token[5].c_str());
	Candidate.history = atof(token[6].c_str());
	Candidate.geography = atof(token[7].c_str());
	Candidate.civic_education = atof(token[8].c_str());
	Candidate.natural_science = atof(token[9].c_str());
	Candidate.social_science = atof(token[10].c_str());
	Candidate.foreign_language = atof(token[11].c_str());
	return Candidate;
}