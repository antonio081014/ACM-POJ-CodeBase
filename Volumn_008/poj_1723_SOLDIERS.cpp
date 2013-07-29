//Wed Jun  2 16:19:38 EDT 2010
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
		vector<int> x(N);
		vector<int> y(N);
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> x[i] >> y[i];
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		for (int i = 0; i < N; i++)
		{
			x[i] -= i;
		}
		sort(x.begin(), x.end());
		int M = N / 2;
		for (int i = 0; i < M; i++)
		{
			sum += y[N - 1 - i] - y[i];
			sum += x[N - 1 - i] - x[i];
		}
		cout << sum << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
