//Mon Apr 19 11:02:53 CDT 2010
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
	int m, n;
	while(cin >> m >> n)
	{
		map<string, int> mp;
		for(int i=0; i<m; i++)
		{
			string temp;
			int number;
			cin >> temp >> number;
			mp[temp] = number;
		}
		for(int i=0; i<n; i++)
		{
			string temp;
			int sum = 0;
			while(cin >> temp && temp != ".")
			{
				sum += mp[temp];
			}
			cout << sum << endl;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
