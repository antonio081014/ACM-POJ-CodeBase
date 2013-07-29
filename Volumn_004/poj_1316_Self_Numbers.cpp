//Tue Apr 13 15:17:05 CDT 2010
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
map<int, bool> mp;
int main(int argc, const char* argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	for (int i = 1; i <= 10000; i++)
	{
		stringstream s;
		string str;
		s << i;
		str = s.str();
		int sum = i;
		for (int j = 0; j < (int) str.size(); j++)
		{
			sum += str[j] - '0';
		}
		mp[sum] = true;
		if (mp[i] == false)
			cout << i << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
