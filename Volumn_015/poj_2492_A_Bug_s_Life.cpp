//Fri Jun  4 21:49:36 EDT 2010
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
#define MMAX 2001
using namespace std;

class Bugs
{
public:
	int parent; //The root;
	bool gender; //false, if it has the same gender with the root; otherwise, true;
};
vector<Bugs> v(MMAX);

void Makeset(int N)
{
	for (int i = 1; i <= N; i++)
	{
		v[i].parent = i;
		v[i].gender = false;
	}
}

int Find(int x)
{
	if (x == v[x].parent)
		return x;
	int temp = v[x].parent;
	v[x].parent = Find(v[x].parent);
	v[x].gender = v[temp].gender == false ? v[x].gender : !v[x].gender;
	return v[x].parent;
}

void Union(int t1, int t2, int x, int y)
{
	v[t2].parent = t1;
	v[t2].gender = v[x].gender == v[y].gender ? true : false;
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int T;
	cin >> T;
	for (int ncase = 1; ncase <= T; ncase++)
	{
		int N, M;
		cin >> N >> M;
		Makeset(N);
		bool flag = true;
		for (int i = 0; i < M; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			int t1 = Find(a);
			int t2 = Find(b);
			if (t1 == t2 && v[a].gender == v[b].gender)
			{
				flag = false;
			}
			else
			{
				Union(t1, t2, a, b);
			}
		}
		cout << "Scenario #" << ncase << ":" << endl;
		if (flag == true)
			cout << "No suspicious bugs found!" << endl;
		else
			cout << "Suspicious bugs found!" << endl;
		cout << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
