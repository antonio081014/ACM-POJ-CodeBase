//Sat Apr 17 12:25:46 CDT 2010
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
	int M, N;
	while (cin >> M >> N)
	{
		vector<vector<char> > v(M, vector<char> (N, '#'));
		int nextx = 0;
		int nexty = 0;
		int count = 0;
		int position = 0;
		int direction = 0; // right, down, left, up.
		while (count < M * N)
		{
			count ++;
			char letter = 'A' + position;
			position = (position + 1) % 26;
			v[nextx][nexty] = letter;
			//Right;
			if(direction == 0)
			{
				if(nexty + 1 == N || (nexty+1<N && v[nextx][nexty+1] != '#'))
				{
					direction = 1;
					nextx++;
				}
				else
				{
					nexty++;
				}
			}
			//Down;
			else if(direction == 1)
			{
				if(nextx+1==M || (nextx+1<M && v[nextx+1][nexty] != '#'))
				{
					direction = 2;
					nexty--;
				}
				else
				{
					nextx++;
				}
			}
			//Left;
			else if(direction == 2)
			{
				if(nexty-1<0 || (nexty-1>=0 && v[nextx][nexty-1] !='#'))
				{
					direction = 3;
					nextx--;
				}
				else
				{
					nexty--;
				}
			}
			//Up;
			else
			{
				if(nextx-1 <0 || (nextx-1>=0 && v[nextx-1][nexty] != '#'))
				{
					direction = 0;
					nexty++;
				}
				else
				{
					nextx--;
				}
			}
		}
		for(int i=0; i<M; i++)
		{
			for(int j=0; j<N; j++)
			{
				cout << "   " << v[i][j];
			}
			cout << endl;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
