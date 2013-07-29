//Tue Apr 13 15:46:54 CDT 2010
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

int LongestIncreasingCommonSubsequence(string A, string B)
{
	int N = A.size();
	int M = B.size();
	vector<vector<int> > v(N + 1, vector<int>(M + 1, 0));
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (i == 0 || j == 0)
				v[i][j] = 0;
			else if(A[i-1] == B[j-1])
				v[i][j] = v[i-1][j-1] + 1;
			else
				v[i][j] = max(v[i-1][j], v[i][j-1]);
		}
	}
	return v[N][M];
}

int main(int argc, const char* argv[])
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	string str1, str2;
	while(cin >> str1 >> str2)
	{
		cout << LongestIncreasingCommonSubsequence(str1, str2) << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
