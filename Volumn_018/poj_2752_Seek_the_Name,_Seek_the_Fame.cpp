//Wed May 26 16:05:21 CDT 2010
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
	string str;
	while (cin >> str)
	{
		int N = str.size();
		vector<int> next(N + 1, 0);
		kmp(str, next);
//		for (int i = 0; i <= N; i++)
//		{
//			cout << " " << next[i];
//		}
//		cout << endl;
		int j = N;
		vector<int> position;
		while (j != 0)
		{
			position.push_back(j);
			j = next[j];
		}
		int temp = position[position.size() - 1];
		cout << temp;
		position.pop_back();
		while (position.empty() == false)
		{
			temp = position[position.size() - 1];
			cout << " " << temp;
			position.pop_back();
		}
		cout << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
