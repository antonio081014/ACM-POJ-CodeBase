//Tue Nov 23 13:57:52 CST 2010
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

int mod(int m, int n)
{
	return m%n;
}

int main( int argc, const char* argv[] )
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF)
	{
		printf("%d\n", mod(a, b));
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
