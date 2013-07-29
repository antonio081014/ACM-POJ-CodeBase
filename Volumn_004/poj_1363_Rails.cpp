//Mon Apr 26 01:19:00 CDT 2010
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
	while (cin >> N && N)
	{
		int a;
		while (cin >> a && a != 0)
		{
			vector<int> src;
			vector<int> dst;
			vector<int> mid;
			src.push_back(1);
			dst.push_back(a);
			for (int i = 1; i < N; i++)
			{
				src.push_back(i + 1);
				cin >> a;
				dst.push_back(a);
			}
			int y = 0;
			while(src.empty() == false)
			{
				if (dst[y] == src.front())
				{
					y++;
					src.erase(src.begin());
				}
				else
				{
					if (!mid.empty() && dst[y] == mid.back())
					{
						mid.pop_back();
						y++;
					}
					else
					{
						mid.push_back(src.front());
						src.erase(src.begin());
					}
				}
			}
			while(mid.empty() == false)
			{
				if(mid.back() == dst[y])
				{
					mid.pop_back();
					y++;
				}
				else
					break;
			}
			if (mid.empty() == false || y < N)
			{
				cout << "No" << endl;
			}
			else
			{
				cout << "Yes" << endl;
			}
		}
		cout << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
/**
 * 5
1 2 3 4 5
5 4 1 2 3
1 2 4 3 5
0
6
6 5 4 3 2 1
0
8
7 3 2 5 8 4 6 1
1 2 3 4 5 7 8 6
0
0
*/
