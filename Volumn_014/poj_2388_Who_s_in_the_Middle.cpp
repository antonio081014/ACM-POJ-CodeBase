//Mon Apr 19 01:47:31 CDT 2010
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
	int N;
	while(cin >> N)
	{
		vector<int> v(N);
		for(int i=0; i<N; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		cout << v[N/2];
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
