//Thu Jun  3 13:48:07 EDT 2010
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
#define MMAX 100005
using namespace std;

class Gang
{
public:
	int parent; //the number of element in this union;
	int rank; 	//0 for the same as set root,1 for different from it;
};

vector<Gang> v(MMAX);

void MakeSet(int N)
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
	v[x].parent = Find(temp);
//	v[x].rank = v[x].rank == v[temp].rank ? 0 : 1;
	v[x].rank = v[temp].rank == 0 ? v[x].rank : (1 - v[x].rank);
	return v[x].parent;
}

void Union(int t1, int t2, int x, int y, int d)
{
	v[t2].parent = t1;
	v[t2].rank = v[x].rank == v[y].rank ? d : (1 - d);
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int T;
	cin >> T;
//	scanf("%d", &T);
	while (T--)
	{
		int N, M;
		cin >> N >> M;
//		scanf("%d %d", &N, &M);
		MakeSet(N);
		char c;
		int a, b;
		for (int i = 0; i < M; i++)
		{
//			cin >> c >> a >> b;
			scanf("\n%c %d %d", &c, &a, &b);
//			cout << c << a << b << endl;
			int t1 = Find(a);
			int t2 = Find(b);
			if (c == 'A')
			{
				if (t1 == t2)
				{
					if (v[a].rank == v[b].rank)
						cout << "In the same gang." << endl;
					else
						cout << "In different gangs." << endl;
				}
				else
					cout << "Not sure yet." << endl;
			}
			else if (c == 'D')
			{
				Union(t1, t2, a, b, 1);
			}
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
