//Fri May 28 12:55:30 CDT 2010
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

int SafeStrcpy2KeyWord(string &des, string src, string keyword)
{
	if (keyword == "NULL")
	{
		des.clear();
		return 0;
	}
	int N = keyword.size();
	int M = src.size();
	for (int i = 0; i + N <= M; i++)
	{
		string str = src.substr(i, N);
		if (str == keyword)
		{
			return i;
		}
		des += src[i];
	}
	return 0;
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	string str;
	while (cin >> str)
	{
		string s;
		getchar();
		while (getline(cin, s) && s != "END")
		{
			string des;
			int len = SafeStrcpy2KeyWord(des, str, s);
			if (len == 0 && des.size() == 0)
				cout << "0 NULL" << endl;
			else if (len == 0)
				cout << str.size() << " " << str << endl;
			else
				cout << len << " " << str.substr(0, len) << endl;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
