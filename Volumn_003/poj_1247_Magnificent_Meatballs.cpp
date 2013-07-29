//Sat Jul  3 22:32:26 CDT 2010
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
	while (cin >> N)
	{
		if (N == 0)
			break;
		vector<int> v(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 1; i <= N; i++)
		{
			sum1 = 0;
			sum2 = 0;
			for (int p = 0; p < i; p++)
				sum1 += v[p];
			for (int p = i; p < N; p++)
				sum2 += v[p];
			if (sum2 == sum1)
			{
				cout << "Sam stops at position " << i
						<< " and Ella stops at position " << (i + 1) << "."
						<< endl;
				break;
			}
		}
		if (sum1 != sum2)
			cout << "No equal partitioning." << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
