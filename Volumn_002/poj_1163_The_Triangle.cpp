//Tue Apr 13 15:36:30 CDT 2010
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
	int N;
	while (cin >> N)
	{
		vector<vector<int> > number(N, vector<int> (N, 0));
		vector<vector<int> > sum(N, vector<int> (N, 0));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> number[i][j];
			}
		}
		sum[0][0] = number[0][0];
		int ret = 0;
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j == 0)
					sum[i][j] = sum[i - 1][j] + number[i][j];
				else
					sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j])
							+ number[i][j];
				if (i == N - 1)
					ret = max(ret, sum[i][j]);
			}
		}
		cout << ret << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
