//Tue Apr 13 16:28:04 CDT 2010
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
//本题是很简单的递推。
//①最少的盘子放了一个，这样每个盘子至少一个，n个盘子先放上n个，剩下的m-n个可以随便放
//②最少的盘子没有放，这样剩下的n-1个盘子还是随便放m个
int apple(int m, int n)
{
	if (m < 0)
		return 0;
	if (m == 0 || n == 1)
		return 1;
	return apple(m, n - 1) + apple(m - n, n);
}

int main(int argc, const char* argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int M, N;
		cin >> M >> N;
		cout << apple(M, N) << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
