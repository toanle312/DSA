#include<iostream>
using namespace std;

void permu3(char x, char y, char z)
{
	for (char t = 'A'; t <= 'D'; t++)
	{
		if (t != x && t != y && t != z)
		{
			cout << x << y << z << t << endl;
		}
	}
}
void permu2(char x, char y)
{
	for (char z = 'A'; z <= 'D'; z++)
	{
		if (z != x && z != y)
		{
			permu3(x, y, z);
		}
	}
}
void permu1(char x)
{
	for (char y = 'A'; y <= 'D'; y++)
	{
		if (y != x)
		{
			permu2(x, y);
		}
	}
}
void permu()
{
	for (char x = 'A'; x <= 'D'; x++)
	{
		permu1(x);
	}
}

void print_permutation_simple()
{
	string s = "ABCD";
	for (int i = 0; i < 4; i++)
	{
		// Chọn những phần tử khác phần tử đầu
		for (int j = 0; j < 4; j++)
		{
			if (i != j)
			{
				// Chọn những phần tử khác phần tử đầu và phần tử thứ 2
				for (int k = 0; k < 4; k++)
				{
					if (k != j && k != i)
					{
						// Chọn những phần tử khác phần tử đầu ,phần tử thứ 2 và phần tử thứ 3
						for (int l = 0; l < 4; l++)
						{
							if (l != k && l != j && l != i)
							{
								// In ra từng kết quả
								cout << s[i] << s[j] << s[k] << s[l] << endl;
							}
						}
					}
				}
			}
		}
	}
}

void print_permutation_medium()
{
	permu();
}

int main()
{
	print_permutation_medium();
	return 0;
}