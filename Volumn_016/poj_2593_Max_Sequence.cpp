//Thu Apr  1 00:33:40 CDT 2010
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

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int n, i, max, sum;
	int a[100001], b[100001], c[100001];
	while (scanf("%d", &n) && n!=0)
	{
		max = -1000;
		sum = 0;
		if (n == 1)
		{
			scanf("%d", &a[0]);
			printf("%d\n", a[0]);
			continue;
		}
		if (n == 2)
		{
			scanf("%d", &a[0]);
			scanf("%d", &a[1]);
			printf("%d\n", a[0] + a[1]);
			continue;
		}
		//b[i] is the max sum from 0 to i.
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
			if (sum < 0)
				sum = 0;
			else if (sum > max)
				max = sum;
			b[i] = max;
		}
		//c[i] is the max sum from i to the end.
		max = -1000;
		sum = 0;
		for (i = n - 1; i >= 0; i--)
		{
			sum += a[i];
			if (sum < 0)
				sum = 0;
			else if (sum > max)
				max = sum;
			c[i] = max;
		}
		max = 0;
		for (i = 0; i < n - 1; i++)
			if (b[i] + c[i + 1] > max)
				max = b[i] + c[i + 1];
		printf("%d\n", max);
	}

	return (0);
}
