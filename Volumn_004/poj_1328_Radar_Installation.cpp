//Tue Apr 13 14:01:31 CDT 2010
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

#define eps 10e-7
class Radar
{
public:
	double left;
	double right;
};

bool cmp(Radar A, Radar B)
{
	return A.left < B.left;
}

int main(int argc, const char* argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int N, d;
	vector<Radar> v;
	for (int ncase = 1; (cin >> N >> d) && N; ncase++)
	{
		bool flag = true;
		v.clear();
		for (int i = 0; i < N; i++)
		{
			Radar r;
			int x, y;
			cin >> x >> y;
			if (y > d)
				flag = false;
			else
			{
				double tmp = sqrt(1.0 * d * d - 1.0 * y * y);
				r.left = 1.0 * x - tmp;
				r.right = 1.0 * x + tmp;
				v.push_back(r);
			}

		}
		if (flag == false)
		{
			cout << "Case " << ncase << ": " << -1 << endl;
			continue;
		}
		sort(v.begin(), v.end(), cmp);
		int number = 1;
		double preidx = v[0].right;
		for (int i = 1; i < N; i++)
		{
			if (v[i].left > preidx + eps)
			{
				number++;
				preidx = v[i].right;
			}
			else
			{
				if (preidx > v[i].right + eps)
					preidx = v[i].right;
			}
		}
		cout << "Case " << ncase << ": " << number << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
