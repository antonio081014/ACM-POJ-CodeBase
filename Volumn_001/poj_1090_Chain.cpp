//Sat Apr 24 20:29:55 CDT 2010
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

//Double the number;
vector<int> Twice(vector<int> v)
{
	vector<int> ret = v;
	int flag = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		ret[i] += v[i] + flag;
		if (ret[i] > 9)
		{
			flag = 1;
			ret[i] %= 10;
		}
		else
			flag = 0;
	}
	if (flag == 1)
		ret.insert(ret.begin(), 1);
	return ret;
}

//Operation : number + 1;
vector<int> PlusOne(vector<int> v)
{
	int flag = 1;
	for(int i=(int)v.size() -1; i>=0; i--)
	{
		v[i] += flag;
		if(v[i] > 9)
		{
			flag = 1;
			v[i] %= 10;
		}
		else
			return v;
	}
	if(flag == 1)
	{
		v.insert(v.begin(), 1);
	}
	return v;
}

vector<int> Binary2Decimal(vector<int> v)
{
	vector<int> ret(1,0);
	for (int i = 0; i <(int) v.size(); i++)
	{
		if(v[i] == 1)
		{
			ret = PlusOne(Twice(ret));
		}
		else
		{
			ret = Twice(ret);
		}
	}
	return ret;
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int N;
	while (cin >> N)
	{
		vector<int> v(N);
		vector<int> dest(N);
		for (int i = 0; i < N; i++)
			cin >> v[N - i - 1];
		dest[0] = v[0];
		for (int i = 1; i < N; i++)
		{
			dest[i] = dest[i - 1] ^ v[i];
			//			cout << dest[i];
		}
		vector<int> res = Binary2Decimal(dest);
		for(int i=0; i<(int)res.size(); i++)
		{
			cout << res[i];
		}
		cout << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
