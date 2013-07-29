//Tue May  4 00:05:17 CDT 2010
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
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int ncase = 1;
	int N;
	while (cin >> N && N != 0)
	{
		//		length = N;
		string str;
		cin >> str;
		vector<int> next(N + 1, 0);
		cout << "Test case #" << ncase << endl;
		kmp(str, next);
		for (int i = 0; i < N; i++)
		{
			cout << " " << next[i];
		}
		cout << endl;
		for (int k = 1; k <= N; k++)
		{
			if (k % (k - next[k]) == 0 && k / (k - next[k]) > 1)
			{
				cout << k << " " << (k) / (k - next[k]) << endl;
			}
		}
		ncase++;
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
