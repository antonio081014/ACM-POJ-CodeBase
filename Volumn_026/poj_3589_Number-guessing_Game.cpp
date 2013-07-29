//Sun 31 Jan 2010 02:14:54 PM CST 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		string str1;
		string str2;
		cin >> str1 >> str2;
		int A = 0;
		int B = 0;
		for(int j=0; j<4; j++)
		{
			if(str1[j] == str2[j])
				A ++;
			else
			{
				for(int k=0; k<4; k++)
				{
					if(str2[j] == str1[k])
					{
						B++;
						break;
					}
				}
			}
		}
		cout << A << "A" << B << "B" << endl;
	}
	return 0;
}
