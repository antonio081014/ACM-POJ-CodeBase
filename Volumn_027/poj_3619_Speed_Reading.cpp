//Fri Apr 23 01:56:26 CDT 2010
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
	int N, K;
	while (cin >> N >> K)
	{
		vector<vector<int> > v(K, vector<int> (3));
		for (int i = 0; i < K; i++)
		{//The total Reading Time; Max Reading Time; Min Rest time;
			cin >> v[i][0] >> v[i][1] >> v[i][2];
			v[i][0] = (int) ((N + v[i][0] - 1) / v[i][0]);
//			cout << v[i][0] << v[i][1] << v[i][2] << endl;
			int times = (int) ((v[i][0] + v[i][1] - 1) / v[i][1]);
			int total = v[i][0] + v[i][2]*(times-1);
			cout << total << endl;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
