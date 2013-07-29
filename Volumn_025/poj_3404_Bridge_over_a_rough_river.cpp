//Fri May 21 15:37:01 CDT 2010
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

long long crossriver(vector<int> v, int T)
{
	if (T == 1)
	{
		return v[0];
	}
	if (T == 2)
	{
		return v[1];
	}
	if (T == 3)
	{
		return v[0] + v[1] + v[2];
	}
	if (v[0] + 3 * v[1] + v[T - 1] > 2 * v[0] + v[1] + v[T - 2] + v[T - 1])
	{
		return 2 * v[0] + v[T - 2] + v[T - 1] + crossriver(v, T - 2);
	}
	else
	{
		return v[0] + 2 * v[1] + v[T - 1] + crossriver(v, T - 2);
	}
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int T;
	while(cin >> T)
	{
		vector<int> v;
		for(int i=0; i<T; i++)
		{
			int number;
			cin >> number;
			v.push_back(number);
		}
		sort(v.begin(), v.end());
		cout << crossriver(v, T) << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
