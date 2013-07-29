//Tue Jun  1 14:05:04 EDT 2010
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
		int N;
		cin >> N;
		vector<bool> v(N + 1, false);
		for (int i = 2; i <= N; i++)
		{
			for (int j = i; j <= N; j += i)
			{
				v[j] = v[j] ? false : true;
			}
		}
		int sum = 0;
		for (int i = 1; i <= N; i++)
		{
			if (v[i] == true)
				sum++;
		}
		cout << N - sum << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
