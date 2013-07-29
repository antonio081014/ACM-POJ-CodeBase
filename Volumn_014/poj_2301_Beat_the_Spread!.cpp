//Mon Apr 19 01:34:56 CDT 2010
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

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int N;
	cin >> N;
	for (int ncase = 0; ncase < N; ncase++)
	{
		int a, b;
		cin >> a >> b;
		if ((a + b) % 2 != 0 || a < b)
		{
			cout << "impossible" << endl;
			continue;
		}
		cout << (a+b)/2 << " " << (a-b)/2 << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
