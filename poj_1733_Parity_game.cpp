//Sun Jun 13 19:52:23 CDT 2010
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
#define MMAX 1000000001
using namespace std;

class Parity
{
public:
	int parent;
	int rank;
};

vector<Parity> v(MMAX);

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
	v[x].parent = Find(v[x].parent);
	return v[x].parent;
}

int main(int argc, const char* argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
