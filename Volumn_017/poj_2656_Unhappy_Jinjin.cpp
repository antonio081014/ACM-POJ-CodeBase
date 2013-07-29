//Thu Feb 24 00:45:51 CST 2011
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
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int N;
	while (cin >> N && N) {
		int a, b;
		int max = 0;
		int idx = 0;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			if (max < a + b) {
				idx = i + 1;
				max = a + b;
			}
		}
		if (max <= 8)
			cout << 0 << endl;
		else
			cout << idx << endl;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
