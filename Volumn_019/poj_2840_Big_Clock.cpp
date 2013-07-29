//Fri May 21 01:01:41 CDT 2010
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
	int T;
	cin >> T;
	while (T--)
	{
		int h, m;
		scanf("%d:%d", &h, &m);
		if (m != 0)
		{
			cout << "0" << endl;
		}
		else if (h > 12)
			cout << h - 12 << endl;
		else
			cout << h + 12 << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
