//Tue Nov 23 14:30:01 CST 2010
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

string add(string A, string B)
{
	int sz = max(A.size(), B.size());
	int flag = 0;
	if(sz > (int)A.size()) A += string(sz-A.size(), '0');
	if(sz > (int)B.size()) B += string(sz-B.size(), '0');
	string ret = "";
	for(int i=0; i<sz; i++)
	{
		int temp = A[i]-'0' + B[i] - '0' + flag;
		flag = temp > 9 ? 1 : 0;
		temp %= 10;
		ret += ('0' + temp);
	}
	if(flag == 1)
		ret += ('0' + flag);
//	cout << A << ", " << B << ", " << ret << endl;
	return ret;
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	string a0, a1, a2;
	while (cin >> a0 >> a1 >> a2)
	{
		vector<string> ret(100, "");
		reverse(a0.begin(), a0.end());
		reverse(a1.begin(), a1.end());
		reverse(a2.begin(), a2.end());
		ret[0] = a0;
		ret[1] = a1;
		ret[2] = a2;
		for (int i = 3; i < 100; i++)
		{
			ret[i] = add(ret[i - 1], add(ret[i - 2], ret[i - 3]));
		}
		reverse(ret[99].begin(), ret[99].end());
		cout << ret[99] << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
