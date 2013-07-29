//Thu 04 Feb 2010 05:40:55 PM CST 
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

#define inf	1<<16

int main(int argc, char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int N;
	while (cin >> N && N)
	{
//		vector<vector<int> > v(N, vector<int> (N, inf));
		vector<vector<int> > cost(N, vector<int> (N, inf));
		for (int i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			for (int j = 0; j < x; j++)
			{
				int a, b;
				cin >> a >> b;
				cost[i][a - 1] = b;
			}
			cost[i][i] = 0;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; k++)
				{
					cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
				}
			}
		}
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				cout << " " << cost[i][j];
//			}
//			cout << endl;
//		}
		int mmin = inf;
		int index = -1;
		for (int i = 0; i < N; i++)
		{
			int mmax = 0;
			for (int j = 0; j < N; j++)
			{
				mmax = max(mmax, cost[i][j]);
			}
			if (mmin > mmax)
			{
				mmin = mmax;
				index = i;
			}
		}
		if (mmin >= inf)
			cout << "disjoint" << endl;
		else
			cout << index + 1 << " " << mmin << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
