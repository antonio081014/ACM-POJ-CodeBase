//Tue May 25 00:56:40 CDT 2010
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
	int T, N;
	while (cin >> T >> N && T)
	{
		long long sum = 0;
		string s;
		int score;
		for (int i = 0; i < T; i++)
		{
			cin >> s >> score;
			sum += score;
		}
		cout << 3 * N - sum << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
