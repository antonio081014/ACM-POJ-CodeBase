//Tue Apr 20 11:49:19 CDT 2010
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

int main( int argc, const char* argv[] )
{
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	string str;
	while(getline(cin ,str) && str != "#")
	{
		for(int i=0; i<str.size(); i++)
		{
			if(str[i] == ' ') cout << "%20";
			else if(str[i] == '!') cout << "%21";
			else if(str[i] == '$') cout << "%24";
			else if(str[i] == '%') cout << "%25";
			else if(str[i] == '(') cout << "%28";
			else if(str[i] == ')') cout << "%29";
			else if(str[i] == '*') cout << "%2a";
			else cout << str[i];
		}
		cout << endl;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
