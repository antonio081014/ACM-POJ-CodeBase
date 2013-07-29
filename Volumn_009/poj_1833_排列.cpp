//Mon Apr 26 05:13:30 CDT 2010
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

int cmp ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}

void getNext(int v[], int n)
{
	int i, j;
	if (1 == n)
		return;
	for (i = n - 2; i >= 0; i--)
	{
		if (v[i] < v[i + 1])
			break;
	}
	//Check if it's the inverse order;
	if (i < 0)
	{
		for (j = 0; j < n; j++)
			v[j] = j + 1;
		return;
	}
	//find the min from i+1 to the end;
	int idx = i + 1;
	for (j = i + 2; j < n; j++)
	{
		if (v[j] < v[idx] && v[j] > v[i])
			idx = j;
	}
	//Swap;
	int tmp = v[idx];
	v[idx] = v[i];
	v[i] = tmp;
//	sort(v.begin() + i + 1, v.end());
	qsort(v + i + 1, n-1-i, sizeof(v[0]), cmp);
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int N;
	scanf("%d", &N);

	for (int ncase = 0; ncase < N; ncase++)
	{
		int m, k;
		scanf("%d%d", &m, &k);
		int v[1025];
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &v[i]);
		}
		for (int i = 0; i < k; i++)
		{
			getNext(v, m);
		}
		for (int i = 0; i < m; i++)
		{
			if (i != 0)
				printf(" ");
			printf("%d", v[i]);
		}
		printf("\n");
	}

//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
