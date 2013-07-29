//Wed Apr 14 13:57:18 CDT 2010
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
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	string str;
	while (cin >> str)
	{
		int idx;
		int sum = 0;
		for (int i = 0; i < (int) str.size(); i++)
		{
			if (isdigit(str[i]))
				sum += (10 - i) * (str[i] - '0');
			else if (str[i] == 'X')
				sum += (10 - i) * 10;
			else
			{
				idx = i;
			}
		}
		sum %= 11;
		bool flag = false;
		for (int i = 0; i < 10; i++)
		{
			if ((sum + (10 - idx) * i) % 11 == 0)
			{
				cout << i << endl;
				flag = true;
				break;
			}
		}
		if((sum + (10 - idx) * 10) % 11 == 0 && idx == 9)
		{
			cout << "X" << endl;
			flag = true;
		}
		if(flag == false)
			cout << -1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
