//Wed Apr 13 23:56:34 CDT 2011
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

void process(int a, int b) {
	if (a == b) {
		if (a % 2 == 0)
			cout << 2 * a << endl;
		else
			cout << 2 * a - 1 << endl;
	} else if (a == b + 2) {
		if (a % 2 == 0)
			cout << 2 * a - 2 << endl;
		else
			cout << 2 * a - 3 << endl;
	} else
		cout << "No Number" << endl;
}

int main(int argc, const char* argv[]) {
//	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int N;
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		process(a, b);
	}
//	fclose(stdin);
	//fclose(stdout);
	return 0;
}

