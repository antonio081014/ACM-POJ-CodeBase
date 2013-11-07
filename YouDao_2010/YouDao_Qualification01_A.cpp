//Sat May 29 06:53:23 CDT 2010
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
		long long A, B;
		string str;
		cin >> A >> str >> B;
		int N = str.size() + 1;
		int sum = 0;
		int factor = 1;
		while (A > 0 || B > 0)
		{
			int temp = A % N + B % N;
			temp %= N;
			sum += factor * temp;
			A /= N;
			B /= N;
			factor *= N;
		}
		cout << sum << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
