//Sun 31 Jan 2010 02:00:16 AM CST 
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
		string str;
		cin >> str;
		int len = str.size();
		char ch = str[0];
		int count = 1;
		for(int i=1; i<len; i++)
		{
			if(ch == str[i])
				count++;
			else
			{
				cout << count << (ch-'0');
				ch = str[i];
				count = 1;
			}
		}
		cout << count << (ch - '0') << endl;
	}
	return 0;
}
