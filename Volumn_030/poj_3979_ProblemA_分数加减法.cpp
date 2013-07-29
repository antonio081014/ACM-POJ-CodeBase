//Mon Nov 22 23:32:14 CST 2010
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

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int a, b, c, d;
	char ch1, ch2;
	while (cin >> a >> ch1 >> b >> ch2 >> c >> ch1 >> d)
	{
		//cout << a << b << c << d << endl;

		int temp = b / gcd(b, d) * d;
		int flag = 1;
		switch (ch2)
		{
		case '+':
			a = a * (temp / b) + c * (temp / d);
			break;
		case '-':
			a = a * (temp / b) - c * (temp / d);
			flag = a < 0 ? -1 : 1;
			a = a < 0 ? -a : a;
		}
		int temp2 = gcd(a, temp);
		//cout << temp2 << endl;
		a /= temp2;
		temp /= temp2;
		if(a == 0)	//One WA here w/o considering if a is 0;
		{
			cout << "0" << endl;
			continue;
		}
		if(temp == 1)
		{
			cout << a*flag << endl; //One WA here w/o *flag;
			continue;
		}
		cout << a * flag << "/" << temp << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
