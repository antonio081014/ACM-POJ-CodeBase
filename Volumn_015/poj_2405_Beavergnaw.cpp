//Mon Apr 19 11:17:52 CDT 2010
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
#define Pi 3.1415926
using namespace std;

int main( int argc, const char* argv[] )
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	double D;
	double d;
	double V;
	while(cin >> D >> V && V)
	{
		d = pow(D*D*D-6*V/Pi,1.0/3);
		cout.precision(3);
		cout << fixed << d << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
