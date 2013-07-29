//Sun 31 Jan 2010 02:03:36 PM CST 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	int sum1 = 0;
	int sum2 = 0;
	int sz1 = s1.size();
	int sz2 = s2.size();
	for(int i=0; i<sz1; i++)
	{
		sum1 += s1[i]-'0';
	}
	for(int i=0; i<sz2; i++)
	{
		sum2 += s2[i]-'0';
	}
	cout << sum1*sum2 << endl;
	return 0;
}
