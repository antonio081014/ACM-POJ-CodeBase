//Thu Feb 24 00:20:44 CST 2011
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

int main(int argc, const char* argv[]) {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	string number;
	while (cin >> number && (number != "0")) {
		long long result = 0;
		for (int i = 0; i < (int) number.size(); i++) {
			int temp = number[i] - '0';
			if (temp > 4)
				temp--;
			result = result * 9 + temp;
		}
		cout << number << ": " << result << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
