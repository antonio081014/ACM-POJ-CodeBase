//Sat Jun  5 11:26:21 CDT 2010
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
#define MMAX 1002
using namespace std;

class Networks
{
public:
	int x;
	int y;
	int parent;
	int rank;
	bool visited;
};

vector<Networks> v(MMAX);

void Makeset(int N)
{
	for (int i = 1; i <= N; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i].x = x;
		v[i].y = y;
		v[i].parent = i;
		v[i].rank = 1;
		v[i].visited = false;
	}
}

int Find(int x)
{
	if (x != v[x].parent)
		v[x].parent = Find(v[x].parent);
	return v[x].parent;
}

void Union(int x, int y)
{
	int t1 = Find(x);
	int t2 = Find(y);
	if (t1 == t2)
		return;
	if (v[t1].rank > v[t2].rank)
		v[t2].parent = t1;
	else
	{
		v[t1].parent = t2;
		if (v[t1].rank == v[t2].rank)
			v[t2].rank++;
	}
}

bool check(int a, int b, long dist)
{
	double d = (v[a].x - v[b].x) * (v[a].x - v[b].x) + (v[a].y - v[b].y)
			* (v[a].y - v[b].y);
	d = sqrt(d);
	return d <= dist ? true : false;
}

int main(int argc, const char* argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int N;
	long D;
	cin >> N >> D;
	Makeset(N);
	string c;
	int a, b;
	while (cin >> c >> a)
	{
		if (c[0] == 'O')
		{
			for (int i = 1; i <= N; i++)
			{
				if (v[i].visited && i != a && check(i, a, D))
				{
					Union(i, a);
				}
			}
			v[a].visited = true;
		}
		else
		{
			cin >> b;
			int t1 = Find(a);
			int t2 = Find(b);
			if (check(a, b, D) || t1 == t2)
			{

				cout << "SUCCESS" << endl;
				//				Union(a, b);
			}
			else
				cout << "FAIL" << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
