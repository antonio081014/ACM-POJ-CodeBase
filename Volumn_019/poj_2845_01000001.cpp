//Fri May 21 12:34:00 CDT 2010
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int T;
	cin >> T;
	for (int ncase = 1; ncase <= T; ncase++)
	{
		string a, b;
		cin >> a >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int flag = 0;
		int i;
		string c;
		for (i = 0; i < (int) min(a.size(), b.size()); i++)
		{
			int temp = a[i] - '0' + b[i] - '0' + flag;
			if (temp > 1)
			{
				temp %= 2;
				flag = 1;
			}
			else
			{
				flag = 0;
			}
			c += '0' + temp;
		}
		if (a.size() > b.size())
		{
			for (; i < (int) a.size(); i++)
			{
				int temp = a[i] - '0' + flag;
				if (temp > 1)
				{
					temp %= 2;
					flag = 1;
				}
				else
				{
					flag = 0;
				}
				c += '0' + temp;
			}
		}
		else
		{
			for (; i < (int) b.size(); i++)
			{
				int temp = b[i] - '0' + flag;
				if (temp > 1)
				{
					temp %= 2;
					flag = 1;
				}
				else
				{
					flag = 0;
				}
				c += '0' + temp;
			}
		}
		if (flag == 1)
			c += '1';
		int idx;
		for(idx = c.size(); idx>1; idx--)
		{
			if(c[idx-1]!='0')
				break;
		}
		c = c.substr(0, idx);
		if(c.size() > 81)
			c = c.substr(0, 81);
		reverse(c.begin(), c.end());
		cout << ncase << " " << c << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
