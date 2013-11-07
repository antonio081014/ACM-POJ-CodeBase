//Sat May 29 06:53:23 CDT 2010
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
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int N;
	while (cin >> N)
	{
		set<string> dict;
		for (int i = 0; i < N; i++)
		{
			string temp;
			cin >> temp;
			dict.insert(temp);
		}
		vector<string> v(dict.begin(), dict.end());
		vector<int> position(26, -1);
		for (int i = 0; i < (int) v.size(); i++)
		{
			if (position[v[i][0] - 'a'] == -1)
				position[v[i][0] - 'a'] = i;
		}
		int Q;
		cin >> Q;
		for (int i = 0; i < Q; i++)
		{
			string temp;
			cin >> temp;
			//			cout << temp;
			vector<string> print;
			int idx = position[temp[0] - 'a'];
			if (idx == -1)
			{
				cout << temp << endl;
				continue;
			}
			else if (idx == position[25])
			{
				int count = 0;
				int len = temp.size();
				for (int j = idx; j < (int) v.size(); j++)
				{
					if (v[j].substr(0, len) == temp)
					{
						print.push_back(v[j]);
						count++;
					}
					if (count == 8)
						break;
				}
			}
			else
			{
				int count = 0;
				int len = temp.size();
				for (int j = idx; j < (int) v.size() && v[j][0] == temp[0]; j++)
				{
					if (v[j].substr(0, len) == temp)
					{
						print.push_back(v[j]);
						count++;
					}
					if (v[j].substr(0, len) != temp && count > 0)
						break;
					if (count == 8)
						break;
				}
			}
			if (print.empty() == false)
				cout << print[0];
			else
				cout << temp;
			for (int j = 1; j < (int) print.size(); j++)
			{
				cout << " " << print[j];
			}
			cout << endl;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
