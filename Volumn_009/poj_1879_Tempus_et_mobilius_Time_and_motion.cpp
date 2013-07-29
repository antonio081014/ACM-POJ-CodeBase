//Mon Apr 26 03:42:02 CDT 2010
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

int gcd(int xx, int yy)
{
	if (yy != 0)
		return gcd(yy, xx % yy);
	return xx;
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int N;
	while (cin >> N && N)
	{
		queue<int> All;
		stack<int> minute, fives, hour;
		for (int i = 0; i < N; i++)
		{
			All.push(i);
		}
		int mins = 60 * 24;
		while (mins--)
		{
			int now = All.front();
			All.pop();
			if (4 != minute.size())
			{
				minute.push(now);
			}
			else
			{
				for (int i = 0; i < 4; i++)
				{
					All.push(minute.top());
					minute.pop();
				}
				if (11 != fives.size())
				{
					fives.push(now);
				}
				else
				{
					for (int i = 0; i < 11; i++)
					{
						All.push(fives.top());
						fives.pop();
					}
					if (11 != hour.size())
					{
						hour.push(now);
					}
					else
					{
						for (int i = 0; i < 11; i++)
						{
							All.push(hour.top());
							hour.pop();
						}
						All.push(now);
					}
				}
			}
		}
		vector<int> src(N);
		for (int i = 0; i < N; i++)
		{
			src[i] = All.front();
			All.pop();
//			cout << src[i];
		}
//		cout << endl;
		vector<int> count(N, 1);
		for (int i = 0; i < N; i++)
		{
			int tmp = src[i];
			while (tmp != i)
			{
				tmp = src[tmp];
				count[i]++;
			}
		}
		int product = 1;
		for (int i = 0; i < N; i++)
		{
			product = product * count[i] / gcd(count[i], product);
		}
		cout << N << " balls cycle after " << product << " days." << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
