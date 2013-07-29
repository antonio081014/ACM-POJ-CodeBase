//Wed Apr 14 13:26:22 CDT 2010
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
	int N;
	while (cin >> N)
	{
		for (int i = 0; i < N; i++)
		{
			string str;
			cin >> str;
			int a = 0;
			int b = 0;
			int c = 0;
			int d = 0;
			for (int idx = 0; idx < 8; idx++)
			{
				a = a * 2 + str[idx] - '0';
			}
			for (int idx = 8; idx < 16; idx++)
			{
				b = b * 2 + str[idx] - '0';
			}
			for (int idx = 16; idx < 24; idx++)
			{
				c = c * 2 + str[idx] - '0';
			}
			for (int idx = 24; idx < 32; idx++)
			{
				d = d * 2 + str[idx] - '0';
			}
			cout << a << "." << b << "." << c << "." << d << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
