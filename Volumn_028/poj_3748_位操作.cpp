//Sat Apr 17 14:43:26 CDT 2010
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
	int R, X, Y;
	char c;
	while(cin >> hex >> R >> dec >> c >> X >> c >> Y)
	{
		R &= ~(1<<(X));
		R |= (1<<(Y));
		R |= (1<<(Y-1));
		R &= ~(1<<(Y-2));

		cout << hex << R << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
