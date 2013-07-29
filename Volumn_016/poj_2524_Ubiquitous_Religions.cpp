//Thu Jun  3 12:06:11 EDT 2010
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
#define MMAX 50005
using namespace std;

class Religions
{
public:
	int parent;
	int rank;
};

vector<Religions> v(MMAX);

void MakeSet(vector<Religions> &v, int N)
{
	for (int i = 1; i <= N; i++)
	{
		v[i].parent = i;
		v[i].rank = 1;
	}
}

int Find(vector<Religions> &v, int x)
{
	int p = x;
	while (p != v[p].parent)
		p = v[p].parent;
	while (x != p)
	{
		int temp = v[x].parent;
		v[x].parent = p;
		x = temp;
	}
	return p;
}

void Union(vector<Religions> &v, int x, int y, int &count)
{
	int t1 = Find(v, x);
	int t2 = Find(v, y);
	if (t1 == t2)
		return;
	count--;
	if (v[t1].rank > v[t2].rank)
	{
		v[t2].parent = t1;
		v[t1].rank += v[t2].rank;
	}
	else
	{
		v[t1].parent = t2;
		v[t2].rank += v[t1].rank;
	}
	return;
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int N, M;
	int ncase = 0;
	while (scanf("%d %d", &N, &M) && (N + M))
	{
		int count = N;
		MakeSet(v, N);
		for (int i = 0; i < M; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			Union(v, x, y, count);
		}
		cout << "Case " << ++ncase << ": " << count << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
