//Sun Feb 13 16:16:52 CST 2011
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

/** Perform the function. */
int checkString(vector<string> v, int number) {
	int sz = number;
	int count = 0;
	while (true) {
		for (int i = 0; i < sz; i++) {
			if(v[i].size() == 1) return count;
			v[i] = v[i].substr(1);
		}
		set<string> v1(v.begin(), v.end());
		if (v1.size() < v.size())
			return count;
		count++;
	}
}

int main(int argc, const char* argv[]) {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int number;
	while (cin >> number && number) {
		vector<string> v(number, "");
		for (int i = 0; i < number; i++)
			cin >> v[i];
		int count = checkString(v, number);
		cout << count << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
