#include"Examinee.h"
int main()
{
	string line_info = "BD1200124,,3.6,5.25,3.25,1.25,2.25,3.0,5.25,6.25,,,3.2,N1,BinhDinh";
	//Examinee info = readExaminee_strtok(line_info);
	Examinee info = readExaminee_token(line_info);
	return 0;
}