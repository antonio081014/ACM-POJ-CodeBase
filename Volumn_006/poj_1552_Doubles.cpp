//Thu Mar 10 13:21:41 CST 2011
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

int main(int argc, const char* argv[])
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    while (cin >> n && n != -1)
    {
        vector<int> v;
        v.push_back(n);
        while (cin >> n && n != 0)
        {
            v.push_back(n);
        }
        sort(v.begin(), v.end());
        int count = 0;
        for (int i = 0; i < v.size(); i++)
            for (int j = i + 1; j < v.size(); j++)
            {
                if (v[j] == 2 * v[i])
                    count++;
            }
        cout << count << endl;

    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
