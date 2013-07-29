//Fri Apr  9 00:58:12 CDT 2010
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

int maxincome = -1;
int n, m;

void Solve(vector<vector<int> > cost, vector<vector<int> > income, int city,
		int currentDay, int day, int maximum)
{
	maximum += income[city][currentDay - 1];
	if (day == m)
	{
		maxincome = max(maxincome, maximum);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (i == city)
			Solve(cost, income, city, currentDay + 1, day + 1, maximum
					- cost[city][city]);
		else
			Solve(cost, income, i, 1, day + 1, maximum - cost[city][i]);
	}
}

int main(int argc, char* argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	while (cin >> n >> m && (n || m))
	{
		vector<vector<int> > cost(100, vector<int> (100, 0));
		vector<vector<int> > income(100, vector<int> (100, 0));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cin >> cost[i][j];
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
				cin >> income[i][j];
		}
//		Solve(cost, income, 1, 1, 1, 0);

		vector<vector<int> > dp(100, vector<int> (100, 0));

		for (int i = 1; i <= n; i++)
		{
			dp[1][i] = dp[0][1] - cost[1][i] + income[1][i];
		}

		for (int i = 2; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dp[i][j] = dp[i - 1][j] + income[i][j] - cost[j][j];
				for (int k = 1; k <= n; k++)
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][k] + income[i][j]
							- cost[k][j]);
				}
				maxincome = max(maxincome, dp[m][j]);
			}
		}
		cout << maxincome << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
