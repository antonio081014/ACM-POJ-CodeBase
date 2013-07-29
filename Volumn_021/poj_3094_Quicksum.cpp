//Sat Apr 16 14:25:29 CDT 2011
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

int translate(char c) {
	if (c == ' ')
		return 0;
	return c - 'A' + 1;
}

int process(string s) {
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
		sum += (i + 1) * translate(s[i]);
	return sum;
}

int main(int argc, const char* argv[]) {
//	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	while (getline(cin, s) && s != "#") {
		cout << process(s) << endl;
	}
//	fclose(stdin);
	//fclose(stdout);
	return 0;
}

