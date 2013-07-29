//Sat Apr 16 14:42:56 CDT 2011
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

vector<double> v;

void init(int N) {
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
}

void process(int N) {
	sort(v.begin(), v.end());
	if (N % 2 == 1)
		printf("%.1f\n", v[(N - 1) / 2]);
	else
		printf("%.1f\n", (v[(N + 1) / 2] + v[(N - 1) / 2]) / 2);
}

int main(int argc, const char* argv[]) {
//	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int N;
	cin >> N;
	init(N);
	process(N);
//	fclose(stdin);
	//fclose(stdout);
	return 0;
}

