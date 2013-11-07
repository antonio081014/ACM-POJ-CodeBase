//Sun May 30 06:49:55 CDT 2010
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
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		double sum = 0;
		int score = 0;
		vector<pair<double, int> > v(M);
		for (int i = 0; i < N; i++)
		{
			double temp1;
			int temp2;
			cin >> temp1 >> temp2;
			sum += temp1 * temp2;
			score += temp2;
		}
		for (int i = 0; i < M; i++)
		{
			double temp1;
			int temp2;
			cin >> temp1 >> temp2;
			v[i] = make_pair(-temp1*temp2, temp2);
		}
		sort(v.begin(), v.end());
		if(90 * score <= sum)
		{
			cout << 0 << endl;
			continue;
		}
		bool flag = true;
		for(int i=0; i<M; i++)
		{
			sum -= v[i].first;
			score += v[i].second;
			if(90 * score <= sum )
			{
				cout << i+1 << endl;
				flag = false;
				break;
			}
		}
		if(flag)
		{
			cout << "Impossible" << endl;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
