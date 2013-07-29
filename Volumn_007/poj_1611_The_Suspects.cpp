//Fri Jun  4 01:13:00 EDT 2010
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
#define MMAX 30001
using namespace std;

class Suspects
{
public:
	int parent; //The number of element in the union at root, else it's the parent's number;
};

vector<Suspects> v(MMAX);

void MakeSet(int N)
{
	for (int i = 0; i < N; i++)
	{
		v[i].parent = -1;
	}
}

int Find(int x)
{
	int p = x;
	while (v[p].parent > 0)
		p = v[p].parent;
	while (x != p)
	{
		int temp = v[x].parent;
		v[x].parent = p;
		x = temp;
	}
	return p;
}

void Union(int x, int y)
{
	int t1 = Find(x);
	int t2 = Find(y);
	if (t1 == t2)
		return;
	if (v[t1].parent >= v[t2].parent)
	{
		v[t2].parent += v[t1].parent;
		v[t1].parent = t2;
	}
	else
	{
		v[t1].parent += v[t2].parent;
		v[t2].parent = t1;
	}
}

int main(int argc, const char* argv[])
{
	//	freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	int M, N;
	while ((cin >> N >> M) && (M + N))
	{
		MakeSet(N);
		for (int i = 0; i < M; i++)
		{
			int k, num;
			cin >> k >> num;
			Union(num, num);
			for (int j = 1; j < k; j++)
			{
				int temp;
				cin >> temp;
				Union(num, temp);
			}
		}
		cout << -v[Find(0)].parent << endl;
	}
	//	fclose(stdin);
	//	fclose(stdout);
	return 0;
}
