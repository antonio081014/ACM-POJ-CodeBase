//Tue Nov 23 14:10:28 CST 2010
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
	string str;
	while (getline(cin, str))
	{
		int sz = str.size();
		string ret = "";
		for (int i = 0; i < sz;)
		{
			if (str[i] != 'y')
			{
				ret += str[i];
				i++;
			}
			else
			{
				if (i + 2 < sz && str[i + 1] == 'o' && str[i + 2] == 'u')
				{
					ret += "we";
					i += 3;
				}
				else
				{
					ret += str[i];
					i++;
				}
			}
		}
		cout << ret << endl;
	}
	//	fclose(stdin);
	//	fclose(stdout);
	return 0;
}
