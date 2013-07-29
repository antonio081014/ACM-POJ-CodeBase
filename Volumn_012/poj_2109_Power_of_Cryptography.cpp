//Wed Apr 14 12:17:16 CDT 2010
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
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	double n, p;
	while(cin >> n >> p)
	{
		cout << (int) round(pow(p, 1/n)) << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
