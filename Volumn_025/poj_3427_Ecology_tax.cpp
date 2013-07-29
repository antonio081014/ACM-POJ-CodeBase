//Wed May  5 02:12:32 CDT 2010
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
	int N, L;
	while (cin >> N >> L)
	{
		int year = 0;
		for (int i = 0; i < N; i++)
		{
			int number;
			cin >> number;
			number %= L;
			if (number > 0 && year + number < L)
				year = L - number;
		}
		cout << year << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
