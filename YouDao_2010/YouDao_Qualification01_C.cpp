//Sat May 29 06:53:23 CDT 2010
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
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}
		for (int i = 0; i < N - 1; i++)
			v.push_back(v[i]);
		int max1 = -12800;
		int sum = 0;
		set<pair<pair<int, int>, int > > count;
		int start = 0;
		int end = 0;
		for (int i = 0; i < (int) v.size(); i++)
		{
			if (sum > 0)
			{
				sum += v[i];
				end = i;
			}
			else
			{
				sum = v[i];
				start = i;
				end = i;
			}
			if (max1 <= sum)
			{
				max1 = sum;
				count.insert(make_pair(make_pair(start % N, end % N), max1));
//				cout << start << ", " << end << endl;
			}
		}
		vector<pair<pair<int, int>, int > > cc(count.begin(), count.end());
		int M = cc.size();
		cout << M << endl;
//		long long mmax1 = cc[0].second;
//		long long mmax2 = cc[0].second;
//		long long max = mmax1;
//		for(int i=0; i<M; i++)
//		{
//			for(int j=i+1; j<M; j++)
//			{
//
//			}
//		}
//		cout << cc[M - 1].first + cc[M - 2].first << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
