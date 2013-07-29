//Fri May 21 16:08:01 CDT 2010
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

char Zone[32][5] =
{ "UTC", "GMT", "BST", "IST", "WET", "WEST", "CET", "CEST", "EET", "EEST",
		"MSK", "MSD", "AST", "ADT", "NST", "NDT", "EST", "EDT", "CST", "CDT",
		"MST", "MDT", "PST", "PDT", "HST", "AKST", "AKDT", "AEST", "AEDT",
		"ACST", "ACDT", "AWST" };

float Diff[32] =
{ 0, 0, 1, 1, 0, 1, 1, 2, 2, 3, 3, 4, -4, -3, -3.5, -2.5, -5, -4, -6, -5, -7,
		-6, -8, -7, -10, -9, -8, 10, 11, 9.5, 10.5, 8 };

int main(int argc, const char* argv[])
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t, h, m, i, j, min;
	char time[9], tmp, zone[5];
	cin >> t;
	while (t--)
	{
		cin >> time;
		if (time[0] == 'n')
			h = 12, m = 0;
		else if (time[0] == 'm')
			h = 24, m = 0;
		else
		{
			istringstream is(time);
			is >> h, is >> tmp, is >> m;
			h %= 12;
			cin >> time;
			if (time[0] == 'p')
				h += 12;
		}
		i = j = 0;
		cin >> zone;
		while (strcmp(zone, Zone[i]))
			i++;
		cin >> zone;
		while (strcmp(zone, Zone[j]))
			j++;
		min = 60 * h + m + int(60 * (Diff[j] - Diff[i]));
		if (min < 0)
			min += 1440;
		min %= 1440;
		if (!min)
			cout << "midnight\n";
		else if (min == 720)
			cout << "noon\n";
		else
		{
			m = min % 60, h = min / 60;
			if (!h)
				cout << "12:" << setw(2) << setfill('0') << m << " a.m.\n";
			else if (h < 12)
				cout << h << ':' << setw(2) << setfill('0') << m << " a.m.\n";
			else if (h == 12)
				cout << h << ':' << setw(2) << setfill('0') << m << " p.m.\n";
			else
				cout << h - 12 << ':' << setw(2) << setfill('0') << m
						<< " p.m.\n";
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
