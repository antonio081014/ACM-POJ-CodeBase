//Wed Mar  2 12:31:10 CST 2011
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

char check(vector<string> v, int x, int y) {
    int ret = 0;
    int m = v.size();
    int n = v[0].size();
    if (v[x][y] == '*') return '*';
    else {
        if (x > 0 && v[x - 1][y] == '*') ret++;
        if (x > 0 && y > 0 && v[x - 1][y - 1] == '*') ret++;
        if (y > 0 && v[x][y - 1] == '*') ret++;
        if (x + 1 < m && y > 0 && v[x + 1][y - 1] == '*') ret++;
        if (x + 1 < m && v[x + 1][y] == '*') ret++;
        if (x + 1 < m && y + 1 < n && v[x + 1][y + 1] == '*') ret++;
        if (y + 1 < n && v[x][y + 1] == '*') ret++;
        if (x > 0 && y + 1 < n && v[x - 1][y + 1] == '*') ret++;
    }
    return '0' + ret;
}

int main(int argc, const char* argv[]) {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    while (cin >> n) {
        bool flag = false;
        vector<string> v1(n, string(n, '.'));
        vector<string> v2(n, string(n, '.'));
        for (int i = 0; i < n; i++)
            cin >> v1[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char temp;
                cin >> temp;
                if (temp == 'x') {
                    if (v1[i][j] == '*') {
                        flag = true;
                        v2[i][j] = '*';
                    } else {
                        v2[i][j] = check(v1, i, j);
                    }
                } else {
                    v2[i][j] = temp;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (flag && v1[i][j] == '*')
                    cout << '*';
                else
                    cout << v2[i][j];
            }
            cout << endl;
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
