//Sat Apr 17 16:31:10 CDT 2010
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

void kmp(string &str, vector<int> &data)
{
	int i = 0;
	int j = -1;
	data[0] = -1;
	while (i < (int) str.size())
	{
		if (j == -1 || str[i] == str[j])
		{
			i++;
			j++;
			data[i] = j;
		}
		else
		{
			j = data[j];
		}
	}
	return;
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	char s[1000000];
	while (scanf("%s", s))
	{
		string str = s;
		if (str == ".")
			break;
		int N = str.size();

		vector<int> next(N + 1, 0);
		kmp(str, next);
		if (N % (N - next[N]) == 0)
			cout << N / (N - next[N]) << endl;
		else
			cout << 1 << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
