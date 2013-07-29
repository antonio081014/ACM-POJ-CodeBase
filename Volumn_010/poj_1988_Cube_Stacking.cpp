//Mon Jun  7 15:51:10 CDT 2010
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

class Cube
{
public:
	int parent; //The cube at the top of the stack;
	int before; //The number of cubes above this cube.
	int after; //The number of cubes under this cube, self inclusive;
};

vector<Cube> v(MMAX);

void Makeset(int N)
{
	for (int i = 1; i <= N; i++)
	{
		v[i].parent = i;
		v[i].before = 0;
		v[i].after = 1;
	}
}

int Find(int x)
{
//	int depth = 0;
//	int p = x;
//	while (p != v[p].parent)
//	{
//		p = v[p].parent;
//		depth++;
//	}
//
//	v[p].after = depth + v[x].after;
//	while (x != p)
//	{
//		int temp = v[x].parent;
//		v[x].parent = p;
//		v[x].before = depth--;
//		v[temp].after = v[x].after + 1;
//		x = temp;
//	}
//	return p;
	int p = x;
	if (p != v[p].parent)
	{
		int temp = v[p].parent;
		v[p].parent = Find(temp);
		v[p].before += v[temp].before;
	}
	return v[p].parent;
}

void Union(int x, int y)
{
	int t1 = Find(x);
	int t2 = Find(y);
	if (t1 == t2)
		return;
	v[t2].parent = t1;
//	v[y].parent = t1;
//	v[x].after += v[t2].after;
//	if (x != t1)
//		v[t1].after += v[t2].after;
//	v[t2].before = v[t1].after;
//	if (y != t2)
//		v[y].before += v[t1].after;
	v[t2].before += v[t1].after;
	v[t1].after += v[t2].after;
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int N, P;
	N = MMAX;
	Makeset(N);
	cin >> P;
	for (int i = 0; i < P; i++)
	{
		char c;
		int x, y;
		cin >> c;
		if (c == 'M')
		{
			cin >> x >> y;
			Union(x, y);
//			cout << v[x].parent << ", " << v[x].before << ", " << v[x].after
//					<< endl;
//			cout << v[y].parent << ", " << v[y].before << ", " << v[y].after
//					<< endl;
		}
		else
		{
			cin >> x;
			int t1 = Find(x);
			cout << v[t1].after - v[x].before - 1 << endl;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
