//Sat Apr 16 16:33:56 CDT 2011
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

vector<int> v;

bool init() {
	v.clear();
	v.resize(6);
	bool ret = false;
	for (int i = 0; i < 6; i++) {
		cin >> v[i];
		if (v[i] != 0)
			ret = true;
	}
	return ret;
}

bool check() {
	int sum = 0;
	for (int i = 0; i < 6; i++) {
		sum += v[i];
	}
	for (int i = 0; i < 6; i++)
		for (int j = i + 1; j < 6; j++)
			for (int k = j + 1; k < 6; k++) {
				if (2 * (v[i] + v[j] + v[k]) == sum)
					return true;
			}
	return false;
}

int main(int argc, const char* argv[]) {
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int count = 1;
	while (init()) {
		cout << "Collection #" << count++ << ":" << endl;
		if (check())
			cout << "Can be divided." << endl;
		else
			cout << "Can't be divided." << endl;
	}
	fclose(stdin);
	//fclose(stdout);
	return 0;
}

