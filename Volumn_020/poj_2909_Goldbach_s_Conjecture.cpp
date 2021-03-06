//Fri May 21 17:33:08 CDT 2010
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

#define m 1000000
bool v[m];

using namespace std;

void Prime()
{
	v[0] = v[1] = true;
	for (int i = 2; i < m; i++)
		if (v[i] == false)
			for (int j = i + i; j < m; j += i)
				v[j] = true;
	return;
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	Prime();
	int N;
	while (cin >> N && N)
	{
		long count = 0;
		if (N % 2 != 0 && v[N - 2] == false)
		{
			count++;
		}
		for (int i = 3; i <= N / 2; i += 2)
		{
			if (v[i] == false && v[N - i] == false)
			{
				count++;
			}
		}
		cout << count << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
