//Fri Jun  4 11:35:32 EDT 2010
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
#define MMAX 50001
using namespace std;
/* Method One:
 * (v[x].rank-v[y].rank+3)%3==0 表示x与y是同类
 * (v[x].rank-v[y].rank+3)%3==1 表示x吃y
 * (v[x].rank-v[y].rank+3)%3==2 表示y吃x
 *
 * Method Two:
 * rank[x]   表示x与father[x]的关系：
 * rank[x] == 0 表示x与 father[x] 是同类
 * rank[x] == 1 表示x吃 father[x]
 * rank[x] == 0 表示 father[x] 吃x
 * */
class Predator
{
public:
	int parent;
	int rank;
};

vector<Predator> v(MMAX);

void Makeset(int N)
{
	for (int i = 1; i <= N; i++)
	{
		v[i].parent = i;
		v[i].rank = 0;
	}
}

int Find(int x)
{
	if (x == v[x].parent)
		return x;
	int temp = v[x].parent;
	v[x].parent = Find(v[x].parent);
	v[x].rank = (v[x].rank + v[temp].rank) % 3;
	return v[x].parent;
}

void Union(int t1, int t2, int x, int y, int d)
{
	v[t2].parent = t1;
	v[t2].rank = (v[x].rank - v[y].rank + 6 - d) % 3;
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int N, M;
//	cin >> N >> M;
	scanf("%d%d", &N, &M);
	Makeset(N);
	int score = 0;
	int a, b, c;
	while (M--)
	{
//		cin >> a >> b >> c;
		scanf("%d%d%d", &a, &b, &c);
		if (b > N || c > N || (a == 2 && b == c))
		{
			score++;
			continue;
		}
		int t1 = Find(b);
		int t2 = Find(c);
		if (t1 == t2)
		{
			if (a == 1 && v[b].rank != v[c].rank)
				score++;
			if (a == 2 && (v[b].rank - v[c].rank + 3) % 3 != a - 1)
				score++;
		}
		else
		{
			Union(t1, t2, b, c, a - 1);
		}
	}
	cout << score << endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
