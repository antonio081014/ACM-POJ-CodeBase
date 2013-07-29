//Fri May 28 00:51:28 CDT 2010
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
	int N, K;
	cin >> N >> K;
	double number;
	vector<long long> v;
	long long left = 1;
	long long right = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> number;
		v.push_back((long long) (number * 100));
		right = max(right, (long long) (number * 100));
	}

	long long ret = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long count = 0;
		for (int i = 0; i < N; i++)
		{
			count += (long long) (v[i] / mid);
		}
		if (count >= K && mid > ret)
		{
			ret = mid;
		}
		if (count >= K)
			left = mid + 1;
		else
			right = mid - 1;
	}
	cout.precision(2);
	cout << fixed << (double) (ret * 0.01) << endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
