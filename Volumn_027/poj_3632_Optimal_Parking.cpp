//Tue Apr 20 12:57:54 CDT 2010
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
	while (N--)
	{
		int mmin = -1;
		int mmax = -1;
		int t;
		cin >> t;
		for(int i=0; i<t; i++)
		{
			int number;
			cin >> number;
			if(number < mmin || mmin == -1) mmin = number;
			if(number > mmax || mmax == -1) mmax = number;
		}
		cout << 2 * (mmax - mmin) << endl;
	}

//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
