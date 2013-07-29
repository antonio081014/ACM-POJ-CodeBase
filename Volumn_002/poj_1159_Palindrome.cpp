//Mon Apr 12 10:33:15 CDT 2010
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

int LongestCommonSubstring(string A, string B)
{
	int N = A.size();
	int M = B.size();
	vector<vector<int> > v(2, vector<int>(M+1, 0));
	for(int i=0; i<=N; i++)
	{
		for(int j=0; j<=M; j++)
		{
			if(i==0 || j==0)
				v[i%2][j] = 0;
			else if(A[i-1] == B[j-1])
				v[i%2][j] = v[(i-1)%2][j-1] + 1;
			else
				v[i%2][j] = max(v[(i-1)%2][j], v[i%2][j-1]);
		}
	}
	return v[N%2][M];
}

int main( int argc, const char* argv[] )
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int N;
	while(cin >> N)
	{
		string str1;
		cin >> str1;
		string str2 = str1;
		reverse(str2.begin(), str2.end());
		cout << N - LongestCommonSubstring(str1, str2) << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
