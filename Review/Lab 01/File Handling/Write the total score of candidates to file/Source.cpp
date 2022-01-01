#include"Examinee.h"

int main()
{
	string file_name = "data.txt";
	vector<Examinee> List = readExamineeList(file_name);

	string out_file_name = "TotalScore.txt";
	writeTotal(List, out_file_name);

	return 0;
}