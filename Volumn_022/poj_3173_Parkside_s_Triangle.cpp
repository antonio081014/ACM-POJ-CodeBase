//Sat Apr 24 01:39:44 CDT 2010
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
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int N, S;
	while (cin >> N >> S)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int a = ((j + 1) * j / 2 + i + S) % 9;
				if (a == 0)
					a = 9;
				if (i > j)
					cout << "  ";
				else if (j < N - 1)
					cout << a << " ";
				else
					cout << a << endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
