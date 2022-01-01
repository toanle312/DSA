#include "Examinee.h"

int main()
{
	string file_name = "data.txt";
	vector<Examinee> List = readExamineeList(file_name);
	return 0;
}