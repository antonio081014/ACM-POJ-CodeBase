//Sun Nov 14 20:37:24 CST 2010
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

int main( int argc, const char* argv[] )
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int a[6];
	while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] && (a[0]||a[1]||a[2]||a[3]||a[4]||a[5]))
	{
		int mmax = a[0];
		int mmin = a[0];
		int sum = a[0];
		for(int i=1; i<6; i++)
		{
			mmax = max(mmax, a[i]);
			mmin = min(mmin, a[i]);
			sum += a[i];
		}
		cout << 1.0*(sum - mmax - mmin)/4. << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
